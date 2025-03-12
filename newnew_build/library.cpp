#include "library.h"
#include "book.h"
#include "user.h"
#include "ui_mainwindow.h"
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

bool Library::issueBook(const Book &book, const QString &cardNumber) {
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT book_id, availability_count FROM books WHERE title = :title AND author_id = "
                       "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    checkQuery.bindValue(":title", book.getTitle());
    checkQuery.bindValue(":author", book.getAuthor());

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
        qWarning() << "Ошибка выдачи книги:" << issueQuery.lastError().text();
        return false;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE books SET availability_count = availability_count - 1 WHERE book_id = :bookId");
    updateQuery.bindValue(":bookId", bookId);
    if (!updateQuery.exec()) {
        qWarning() << "Ошибка обновления количества книг:" << updateQuery.lastError().text();
        return false;
    }
    return true;
}

bool Library::returnBook(const QString &cardNumber, const Book &book) {
    QSqlQuery userQuery;
    userQuery.prepare("SELECT user_id FROM users WHERE library_card_number = :libraryCardNumber");
    userQuery.bindValue(":libraryCardNumber", cardNumber);
    if (!userQuery.exec() || !userQuery.next()) {
        qWarning() << "Ошибка: пользователь не найден по номеру библиотечного билета.";
        return false;
    }
    int userId = userQuery.value("user_id").toInt();

    QSqlQuery bookQuery;
    bookQuery.prepare("SELECT book_id FROM books WHERE title = :title AND author_id = "
                      "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    bookQuery.bindValue(":title", book.getTitle());
    bookQuery.bindValue(":author", book.getAuthor());
    if (!bookQuery.exec() || !bookQuery.next()) {
        qWarning() << "Ошибка возврата книги: книга не найдена.";
        return false;
    }
    int bookId = bookQuery.value("book_id").toInt();

    QSqlQuery loanQuery;
    loanQuery.prepare("SELECT loan_id FROM book_loans WHERE book_id = :bookId AND user_id = :userId AND return_date IS NULL");
    loanQuery.bindValue(":bookId", bookId);
    loanQuery.bindValue(":userId", userId);
    if (!loanQuery.exec() || !loanQuery.next()) {
        qWarning() << "Ошибка: книга не была выдана этому пользователю или уже возвращена.";
        return false;
    }
    int loanId = loanQuery.value("loan_id").toInt();

    QSqlQuery returnQuery;
    returnQuery.prepare("UPDATE book_loans SET return_date = CURRENT_DATE WHERE loan_id = :loanId");
    returnQuery.bindValue(":loanId", loanId);
    if (!returnQuery.exec()) {
        qWarning() << "Ошибка возврата книги:" << returnQuery.lastError().text();
        return false;
    }

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE books SET availability_count = availability_count + 1 WHERE book_id = :bookId");
    updateQuery.bindValue(":bookId", bookId);
    if (!updateQuery.exec()) {
        qWarning() << "Ошибка обновления количества книг:" << updateQuery.lastError().text();
        return false;
    }
    return true;
}
