#include "SignUpMenuLogic.hpp"

#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDebug>
#include <QSqlError>

SignUpMenuLogic::SignUpMenuLogic(QObject* parent) : QObject(parent) {
    currID = 0;
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

    int userID = insertUser(username, hashedPassword);
    if (userID > 0) {
        qDebug() << "User signed up successfully.";
        setUserID(userID);
        emit sigSignUpSuccess(username, password);
        return true;
    }

    emit signUpError("Failed to sign up. Please try again.");
    return false;
}

bool SignUpMenuLogic::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../zinfo/users.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase SignUpMenuLogic::getUserDB() {
    return db;
}

bool SignUpMenuLogic::createUsersTable() {
    QSqlQuery createTableQuery(db);
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT)")) {
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

int SignUpMenuLogic::insertUser(const QString& username, const QByteArray& hashedPassword) {
    QSqlQuery insertUserQuery;
    insertUserQuery.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    insertUserQuery.addBindValue(username);
    insertUserQuery.addBindValue(QString::fromUtf8(hashedPassword));

    if (!insertUserQuery.exec()) {
        qDebug() << "Failed to insert user:" << insertUserQuery.lastError().text();
        return -1;
    }
    return insertUserQuery.lastInsertId().toInt();
}

int SignUpMenuLogic::getUserID() {
    return currID;
}

void SignUpMenuLogic::setUserID(int id) {
    currID = id;
}

/*
SignUpMenuLogic::SignUpMenuLogic(QObject* parent) : QObject(parent) {}

void SignUpMenuLogic::signUp(const QString& username, const QString& password) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    bool success = false;

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
    }

    // Check if the users table exists; create it if not
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)")) {
        qDebug() << "Failed to create the users table:" << createTableQuery.lastError().text();
    }

    // Check if the username already exists
    QSqlQuery checkUsernameQuery;
    checkUsernameQuery.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    checkUsernameQuery.addBindValue(username);
    if (!checkUsernameQuery.exec()) {
        qDebug() << "Error checking username existence:" << checkUsernameQuery.lastError().text();
    }

    checkUsernameQuery.next();
    int usernameCount = checkUsernameQuery.value(0).toInt();

    if (usernameCount > 0) {
        qDebug() << "Username already exists. Choose a different username.";
    }

    // Hash the password before storing it
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Insert the new user into the users table
    QSqlQuery insertUserQuery;
    insertUserQuery.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    insertUserQuery.addBindValue(username);
    insertUserQuery.addBindValue(QString::fromUtf8(hashedPassword));

    if (!insertUserQuery.exec()) {
        qDebug() << "Failed to insert user:" << insertUserQuery.lastError().text();
        emit signUpError("Failed to sign up. Please try again.");
    }
    else {
        qDebug() << "User signed up successfully.";
        emit signUpSuccess();
    }
}*/