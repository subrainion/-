#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"
#include <QString>
#include <QSqlDatabase>

class Library
{
public:
    Library();
    bool connectToDatabase(const QString &host, const QString &dbName, const QString &user, const QString &password);

    bool issueBook(const Book &book, const QString &cardNumber);
    bool returnBook(const QString &cardNumber, const Book &book);

private:
    QSqlDatabase db;
};

#endif // LIBRARY_H
