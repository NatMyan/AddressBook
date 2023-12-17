#include "SignInMenuLogic.hpp"
#include <QSqlError>

SignInMenuLogic::SignInMenuLogic(QObject *parent) : QObject(parent) {
    currID = 0;
    openDatabase();
}

void SignInMenuLogic::signIn(QString &username, QString &password) {
    QString hashedPassword = hashPassword(password);

    if (checkCredentials(username, hashedPassword)) {
        qDebug() << "Sign in successful!";
        emit sigSignInSuccess(username, password);
    } 
    else {
        qDebug() << "Sign in failed. Please try again.";
        emit sigSignInFailed();
    }
}

bool SignInMenuLogic::checkCredentials(const QString &username, const QString &hashedPassword) {
    if (!openDatabase()) {
        qDebug() << "Failed to open the database.";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);
    if (query.exec() && query.next()) {
        setUserID(query.value("id").toInt());
    }
    
    QSqlQuery query2;
    query2.prepare("SELECT username, password FROM users WHERE username = :username AND password = :password");
    // query2.prepare("SELECT id FROM users WHERE username = :username AND password = :password");
    query2.bindValue(":username", username);
    query2.bindValue(":password", hashedPassword);

    
    if (!query2.exec()) {
        qDebug() << "Query execution failed:" << query2.lastError().text();
        return false;
    }
    
    return query2.next();
}

QString SignInMenuLogic::hashPassword(const QString &password) {
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    return hash.result().toHex();
}

bool SignInMenuLogic::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../zinfo/users.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    return true;
}

QSqlDatabase SignInMenuLogic::getUserDB() {
    return db;
}

int SignInMenuLogic::getUserID() {
    return currID;
}

void SignInMenuLogic::setUserID(int id) {
    currID = id;
}