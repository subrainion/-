#ifndef DATAQ_H
#define DATAQ_H

#include <QString>
#include <QSqlDatabase>

class Library
{
public:
    Library();
    bool connectToDatabase(const QString &host, const QString &dbName, const QString &user, const QString &password);

    // Методы для работы с книгами
    bool addBook(const QString &title, const QString &author, const QString &category, int availabilityCount);
    bool deleteBook(const QString &title, const QString &author);
    bool issueBook(const QString &title, const QString &author, const QString &cardNumber);
    bool returnBook(const QString &libraryCardNumber, const QString &title, const QString &author);

    // Методы для работы с пользователями
    bool addUser(const QString &firstName, const QString &lastName, const QString &cardNumber);
    bool deleteUser(const QString &cardNumber);

private:
    QSqlDatabase db;
};

#endif // DATAQ_H
