#ifndef USER_H
#define USER_H

#include <QString>
#include <QSqlDatabase>

class User {
public:
    User(const QString& firstName, const QString& lastName, const QString& cardNumber);

    QString getFirstName() const;
    QString getLastName() const;
    QString getCardNumber() const;
    bool addUser(const User &user);
    bool deleteUser(const QString &cardNumber);

private:
    QString u_firstName;
    QString u_lastName;
    QString u_cardNumber;
};

#endif // USER_H
