#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QSqlDatabase>

class Book {
public:
    Book(const QString& title, const QString& author, const QString& category, int availabilityCount);

    QString getTitle() const;
    QString getAuthor() const;
    QString getCategory() const;
    int getAvailabilityCount() const;
    void setAvailabilityCount(int count);
    int getAuthorId(const QString &author);
    int getCategoryId(const QString &category);
    bool addBook(const Book &book);
    bool deleteBook(const Book &book);

private:
    QString b_title;
    QString b_author;
    QString b_category;
    int b_availabilityCount;
};

#endif // BOOK_H
