#include "dataq.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Library::Library() {}

bool Library::connectToDatabase(const QString &host, const QString &dbName, const QString &user, const QString &password)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(host);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);

    if (!db.open()) {
        qWarning() << "Ошибка подключения к базе данных: " << db.lastError().text();
        return false;
    }
    return true;
}

bool Library::addBook(const QString &title, const QString &author, const QString &category, int availabilityCount)
{
    // Поиск author_id по имени и фамилии автора
    QSqlQuery authorQuery;
    authorQuery.prepare("SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author");
    authorQuery.bindValue(":author", author);

    if (!authorQuery.exec() || !authorQuery.next()) {
        qWarning() << "Ошибка добавления книги: автор не найден.";
        return false;
    }
    int authorId = authorQuery.value("author_id").toInt();

    // Поиск category_id по названию жанра
    QSqlQuery categoryQuery;
    categoryQuery.prepare("SELECT category_id FROM categories WHERE name = :category");
    categoryQuery.bindValue(":category", category);

    if (!categoryQuery.exec() || !categoryQuery.next()) {
        qWarning() << "Ошибка добавления книги: категория не найдена.";
        return false;
    }
    int categoryId = categoryQuery.value("category_id").toInt();

    // Добавление книги
    QSqlQuery query;
    query.prepare("INSERT INTO books (title, author_id, category_id, availability_count) "
                  "VALUES (:title, :authorId, :categoryId, :availabilityCount)");
    query.bindValue(":title", title);
    query.bindValue(":authorId", authorId);
    query.bindValue(":categoryId", categoryId);
    query.bindValue(":availabilityCount", availabilityCount);

    if (!query.exec()) {
        qWarning() << "Ошибка добавления книги: " << query.lastError().text();
        return false;
    }

    return true;
}

bool Library::deleteBook(const QString &title, const QString &author)
{
    QSqlQuery query;
    query.prepare("DELETE FROM books WHERE title = :title AND author_id = "
                  "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    query.bindValue(":title", title);
    query.bindValue(":author", author);

    if (!query.exec()) {
        qWarning() << "Ошибка удаления книги: " << query.lastError().text();
        return false;
    }

    return true;
}

bool Library::issueBook(const QString &title, const QString &author, const QString &cardNumber)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT book_id, availability_count FROM books WHERE title = :title AND author_id = "
                       "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    checkQuery.bindValue(":title", title);
    checkQuery.bindValue(":author", author);

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value("availability_count").toInt() <= 0) {
        qWarning() << "Ошибка выдачи книги: книга недоступна или не найдена.";
        return false;
    }

    int bookId = checkQuery.value("book_id").toInt();

    QSqlQuery userQuery;
    userQuery.prepare("SELECT user_id FROM users WHERE library_card_number = :cardNumber");
    userQuery.bindValue(":cardNumber", cardNumber);

    if (!userQuery.exec() || !userQuery.next()) {
        qWarning() << "Ошибка получения пользователя: пользователь не найден.";
        return false;
    }

    int userId = userQuery.value("user_id").toInt();

    QSqlQuery issueQuery;
    issueQuery.prepare("INSERT INTO book_loans (book_id, user_id, loan_date) VALUES (:bookId, :userId, CURRENT_DATE)");
    issueQuery.bindValue(":bookId", bookId);
    issueQuery.bindValue(":userId", userId);

    if (!issueQuery.exec()) {
        qWarning() << "Ошибка выдачи книги: " << issueQuery.lastError().text();
        return false;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE books SET availability_count = availability_count - 1 WHERE book_id = :bookId");
    updateQuery.bindValue(":bookId", bookId);

    if (!updateQuery.exec()) {
        qWarning() << "Ошибка обновления количества книг: " << updateQuery.lastError().text();
        return false;
    }

    return true;
}

bool Library::returnBook(const QString &libraryCardNumber, const QString &title, const QString &author)
{
    // Получаем user_id по номеру библиотечного билета
    QSqlQuery userQuery;
    userQuery.prepare("SELECT user_id FROM users WHERE library_card_number = :libraryCardNumber");
    userQuery.bindValue(":libraryCardNumber", libraryCardNumber);

    if (!userQuery.exec() || !userQuery.next()) {
        qWarning() << "Ошибка: пользователь не найден по номеру библиотечного билета.";
        return false;
    }

    int userId = userQuery.value("user_id").toInt();

    // Находим book_id книги по названию и автору
    QSqlQuery bookQuery;
    bookQuery.prepare("SELECT book_id FROM books WHERE title = :title AND author_id = "
                      "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    bookQuery.bindValue(":title", title);
    bookQuery.bindValue(":author", author);

    if (!bookQuery.exec() || !bookQuery.next()) {
        qWarning() << "Ошибка возврата книги: книга не найдена.";
        return false;
    }

    int bookId = bookQuery.value("book_id").toInt();

    // Проверяем, что книга действительно была выдана пользователю
    QSqlQuery loanQuery;
    loanQuery.prepare("SELECT loan_id FROM book_loans WHERE book_id = :bookId AND user_id = :userId AND return_date IS NULL");
    loanQuery.bindValue(":bookId", bookId);
    loanQuery.bindValue(":userId", userId);

    if (!loanQuery.exec() || !loanQuery.next()) {
        qWarning() << "Ошибка: книга не была выдана этому пользователю или уже возвращена.";
        return false;
    }

    int loanId = loanQuery.value("loan_id").toInt();

    // Обновляем запись о возврате книги
    QSqlQuery returnQuery;
    returnQuery.prepare("UPDATE book_loans SET return_date = CURRENT_DATE WHERE loan_id = :loanId");
    returnQuery.bindValue(":loanId", loanId);

    if (!returnQuery.exec()) {
        qWarning() << "Ошибка возврата книги: " << returnQuery.lastError().text();
        return false;
    }

    // Обновляем количество доступных экземпляров книги
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE books SET availability_count = availability_count + 1 WHERE book_id = :bookId");
    updateQuery.bindValue(":bookId", bookId);

    if (!updateQuery.exec()) {
        qWarning() << "Ошибка обновления количества книг: " << updateQuery.lastError().text();
        return false;
    }

    return true;
}

bool Library::addUser(const QString &firstName, const QString &lastName, const QString &cardNumber)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, last_name, library_card_number) "
                  "VALUES (:firstName, :lastName, :cardNumber)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":cardNumber", cardNumber);

    if (!query.exec()) {
        qWarning() << "Ошибка добавления пользователя: " << query.lastError().text();
        return false;
    }

    return true;
}

bool Library::deleteUser(const QString &cardNumber)
{
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE library_card_number = :cardNumber");
    query.bindValue(":cardNumber", cardNumber);

    if (!query.exec()) {
        qWarning() << "Ошибка удаления пользователя: " << query.lastError().text();
        return false;
    }

    return true;
}
