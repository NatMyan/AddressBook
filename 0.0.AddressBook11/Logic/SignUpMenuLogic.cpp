#include "SignUpMenuLogic.hpp"
#include "../Data/User.hpp"

#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDebug>
#include <QSqlError>

SignUpMenuLogic::SignUpMenuLogic(QObject* parent) : QObject(parent) {
    openDatabase();
    createUsersTable();
}

bool SignUpMenuLogic::signUp(QString& username, QString& password) {
    if (!openDatabase()) {
        emit signUpError("Database connection failed.");
        return false;
    }

    if (!createUsersTable()) {
        emit signUpError("Failed to create the users table.");
        return false;
    }

    if (checkUsernameExists(username)) {
        emit signUpError("Username already exists. Choose a different username.");
        return false;
    }

    QByteArray hashedPassword = hashPassword(password);

    if (insertUser(username, hashedPassword)) {
        User::setName(username);
        qDebug() << "User signed up successfully.";
        emit sigSignUpSuccess(username, password);
        return true;
    }

    emit signUpError("Failed to sign up. Please try again.");
    return false;
}

bool SignUpMenuLogic::openDatabase() {
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("../zinfo/users.db");

    if (!db_.open()) {
        qDebug() << "Database connection failed:" << db_.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase SignUpMenuLogic::getUserDB() {
    return db_;
}

bool SignUpMenuLogic::createUsersTable() {
    QSqlQuery createTableQuery(db_);
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)")) {
        qDebug() << "Failed to create the users table:" << createTableQuery.lastError().text();
        return false;
    }

    return true;
}

bool SignUpMenuLogic::checkUsernameExists(const QString& username) {
    QSqlQuery checkUsernameQuery;
    checkUsernameQuery.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    checkUsernameQuery.addBindValue(username);

    if (!checkUsernameQuery.exec()) {
        qDebug() << "Error checking username existence:" << checkUsernameQuery.lastError().text();
        return false;
    }

    checkUsernameQuery.next();
    int usernameCount = checkUsernameQuery.value(0).toInt();

    return (usernameCount > 0);
}

QByteArray SignUpMenuLogic::hashPassword(const QString& password) {
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}

bool SignUpMenuLogic::insertUser(const QString& username, const QByteArray& hashedPassword) {
    QSqlQuery insertUserQuery;
    insertUserQuery.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    insertUserQuery.addBindValue(username);
    insertUserQuery.addBindValue(QString::fromUtf8(hashedPassword));

    if (!insertUserQuery.exec()) {
        qDebug() << "Failed to insert user:" << insertUserQuery.lastError().text();
        return false;
    }
    return true;
}



