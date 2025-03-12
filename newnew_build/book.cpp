#include "book.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Book::Book(const QString &title, const QString &author, const QString &category, int availabilityCount)
    : b_title(title), b_author(author), b_category(category), b_availabilityCount(availabilityCount)
{
}

QString Book::getTitle() const {
    return b_title;
}

QString Book::getAuthor() const {
    return b_author;
}

QString Book::getCategory() const {
    return b_category;
}

int Book::getAvailabilityCount() const {
    return b_availabilityCount;
}

void Book::setAvailabilityCount(int count) {
    b_availabilityCount = count;
}

int Book::getAuthorId(const QString &author) {
    QSqlQuery query;
    query.prepare("SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author");
    query.bindValue(":author", author);
    if (query.exec() && query.next()) {
        return query.value("author_id").toInt();
    }
    qWarning() << "Автор не найден:" << author;
    return -1;
}

int Book::getCategoryId(const QString &category) {
    QSqlQuery query;
    query.prepare("SELECT category_id FROM categories WHERE name = :category");
    query.bindValue(":category", category);
    if (query.exec() && query.next()) {
        return query.value("category_id").toInt();
    }
    qWarning() << "Категория не найдена:" << category;
    return -1;
}

bool Book::addBook(const Book &book) {
    int authorId = getAuthorId(book.getAuthor());
    if (authorId == -1) return false;

    int categoryId = getCategoryId(book.getCategory());
    if (categoryId == -1) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO books (title, author_id, category_id, availability_count) "
                  "VALUES (:title, :authorId, :categoryId, :availabilityCount)");
    query.bindValue(":title", book.getTitle());
    query.bindValue(":authorId", authorId);
    query.bindValue(":categoryId", categoryId);
    query.bindValue(":availabilityCount", book.getAvailabilityCount());

    if (!query.exec()) {
        qWarning() << "Ошибка добавления книги:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Book::deleteBook(const Book &book) {
    QSqlQuery query;
    query.prepare("DELETE FROM books WHERE title = :title AND author_id = "
                  "(SELECT author_id FROM authors WHERE first_name || ' ' || last_name = :author)");
    query.bindValue(":title", book.getTitle());
    query.bindValue(":author", book.getAuthor());

    if (!query.exec()) {
        qWarning() << "Ошибка удаления книги:" << query.lastError().text();
        return false;
    }
    return true;
}
