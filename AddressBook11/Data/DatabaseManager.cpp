#include "DatabaseManager.hpp"
#include "User.hpp"

#include <QFileInfo>
#include <QTimer>

DatabaseManager::DatabaseManager(const QString& fileName) {
    makeDatabase(fileName);
    createTable();
}

DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

void DatabaseManager::setDatabase(const QSqlDatabase& db) {
    db_ = db;
}

QSqlDatabase DatabaseManager::getDatabase() {
    return db_;
}

void DatabaseManager::changeDatabaseName(const QString& fileName) {
    db_.close();
    db_.setDatabaseName(fileName);
    db_.open();
}

void DatabaseManager::openDatabase(const QString& filePath, const QString& dbName, const QString& fields) {
    if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(filePath);

        if (db.open()) {
            qDebug() << "Database opened successfully";

            QSqlQuery query(db_);
            if (!query.exec("SELECT * FROM " + dbName)) {
                qDebug() << "dbName: " << dbName;
                if (!query.exec("CREATE TABLE " + dbName + " " + fields)) {
                    qDebug() << "Failed to create '" + dbName + "' table: " << query.lastError().text();
                }
            }
        } 
        else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }
}

void DatabaseManager::closeDatabase() {
    if (db_.isOpen()) {
        db_.close();
    }
}

void DatabaseManager::makeDatabase(const QString& fileName) {
    closeDatabase();
    db_ = QSqlDatabase::addDatabase("QSQLITE");

    if (!fileName.isEmpty()) {
        fileName_ = fileName;
    } 

    db_.setDatabaseName(fileName_);

    if (!db_.open()) {
        qDebug() << "Failed to open database:" << db_.lastError().text();
        return;
    }
}

bool DatabaseManager::createTable() {
    QSqlQuery query(db_);
    
    query.exec("CREATE TABLE IF NOT EXISTS " + User::getName() + " (name TEXT, phone TEXT, email TEXT, belonging TEXT)");

    if (query.isActive()) {
        qDebug() << "Table created successfully";
        return true;
    } 
    else {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
}

QList<Contact> DatabaseManager::readContacts() {
    QList<Contact> contacts;

    QSqlQuery query(db_);
    if (query.exec("SELECT name, phone, email, belonging FROM " + User::getName())) {
        while (query.next()) {
            Contact contact;
            contact.name = query.value(0).toString();
            contact.phone = query.value(1).toString();
            contact.email = query.value(2).toString();
            contact.belonging = query.value(3).toString();
            contacts.append(contact);
        }
    } 
    else {
        qDebug() << "Error reading contacts:" << query.lastError().text();
    }

    return contacts;
}

bool DatabaseManager::writeContacts(const QList<Contact>& contacts) {
    QSqlQuery query(db_);

    if (!query.exec("DELETE FROM " + User::getName())) {
        qDebug() << "Error clearing contacts:" << query.lastError().text();
        return false;
    }

    for (const auto& contact : contacts) {
        query.prepare("INSERT INTO " + User::getName() + " (name, phone, email, belonging) VALUES (?, ?, ?, ?)");
        query.addBindValue(contact.name);
        query.addBindValue(contact.phone);
        query.addBindValue(contact.email);
        query.addBindValue(contact.belonging);

        if (!query.exec()) {
            qDebug() << "Error writing contact:" << query.lastError().text();
            return false;
        }
    }

    return true;
}
