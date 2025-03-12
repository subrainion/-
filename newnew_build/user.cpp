#include "user.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

User::User(const QString &firstName, const QString &lastName, const QString &cardNumber)
    : u_firstName(firstName), u_lastName(lastName), u_cardNumber(cardNumber)
{
}

QString User::getFirstName() const {
    return u_firstName;
}

QString User::getLastName() const {
    return u_lastName;
}

QString User::getCardNumber() const {
    return u_cardNumber;
}

bool User::addUser(const User &user) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (first_name, last_name, library_card_number) "
                  "VALUES (:firstName, :lastName, :cardNumber)");
    query.bindValue(":firstName", user.getFirstName());
    query.bindValue(":lastName", user.getLastName());
    query.bindValue(":cardNumber", user.getCardNumber());
    if (!query.exec()) {
        qWarning() << "Ошибка добавления пользователя:" << query.lastError().text();
        return false;
    }
    return true;
}

bool User::deleteUser(const QString &cardNumber) {
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE library_card_number = :cardNumber");
    query.bindValue(":cardNumber", cardNumber);
    if (!query.exec()) {
        qWarning() << "Ошибка удаления пользователя:" << query.lastError().text();
        return false;
    }
    return true;
}
