#include "Database.hpp"

#include <QFileInfo>
#include <QTimer>

/// NOTE: back to this when DBManager is DB somehow
Database::Database(const QString& fileName) {
    makeDatabase(fileName);
    createTable();
}

Database::~Database() {
    closeDatabase();
}

void Database::setDatabase(const QSqlDatabase& db) {
    db_ = db;
}

QSqlDatabase Database::getDatabase() {
    return db_;
}

void Database::changeDatabaseName(const QString& fileName) {
    db_.close();
    db_.setDatabaseName(fileName);
    db_.open();
}

void Database::openDatabase(const QString &filePath, const QString &dbName, const QString &fields) {
    if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(filePath);


        if (db.open()) {
            qDebug() << "Database opened successfully";

            QSqlQuery query(db_);
            if (!query.exec("SELECT * FROM " + dbName)) {
                if (!query.exec("CREATE TABLE " + dbName + " " + fields)) {
                    qDebug() << "Failed to create '" + dbName + "' table: " << query.lastError().text();
                }
            }
        } 
        else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }
    /*db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName(databaseName);
    
    if (!db_.open()) {
        qDebug() << "Error opening database:" << db_.lastError().text();
        return false;
    }

    return true;*/
}

void Database::closeDatabase() {
    if (db_.isOpen()) {
        db_.close();
    }
}

void Database::makeDatabase(const QString &fileName) {
    closeDatabase();
    db_ = QSqlDatabase::addDatabase("QSQLITE");

    if (!fileName.isEmpty()) {
        fileName_ = fileName;
    } 
    /*else {
        fileName_ = "../untitled.db";

        QFileInfo fileInfo(fileName_);
        if (fileInfo.exists()) {
            int i = 1;
            fileName_ = "../untitled" + QString::number(i) + ".db";  
            while (QFileInfo(fileName_).exists()) {
                ++i;
                fileName_ = "../untitled" + QString::number(i) + ".db";
            }
        }
    }*/

    db_.setDatabaseName(fileName_);

    if (!db_.open()) {
        qDebug() << "Failed to open database:" << db_.lastError().text();
        return;
    }

/*db_ = QSqlDatabase::addDatabase("QSQLITE");
    fileName_ = "../untitled.db";  

    QFileInfo fileInfo(fileName_);
    if (fileInfo.exists()) {
        int i = 1;
        fileName_ = "../untitled" + QString::number(i) + ".db";  
        while (QFileInfo(fileName_).exists()) {
            ++i;
            fileName_ = "../untitled" + QString::number(i) + ".db";
        }
    }
    db_.setDatabaseName(fileName_);

    if (!db_.open()) {
        qDebug() << "Failed to open database:" << db_.lastError().text();
        return;
    }*/
}

bool Database::createTable() {
    QSqlQuery query(db_);
    
    query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT, belonging TEXT)");

    if (query.isActive()) {
        qDebug() << "Table created successfully";
        return true;
    } 
    else {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
}

QList<Contact> Database::readContacts() {
    QList<Contact> contacts;

    QSqlQuery query(db_);
    if (query.exec("SELECT name, phone, email, belonging FROM contacts")) {
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

bool Database::writeContacts(const QList<Contact> &contacts) {
    QSqlQuery query(db_);

    if (!query.exec("DELETE FROM contacts")) {
        qDebug() << "Error clearing contacts:" << query.lastError().text();
        return false;
    }

    for (const auto &contact : contacts) {
        query.prepare("INSERT INTO contacts (name, phone, email, belonging) VALUES (?, ?, ?, ?)");
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
