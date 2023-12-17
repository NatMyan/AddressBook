#include "Database.hpp"

Database::Database(const QString& name) : 
    name_(name)
{
    makeDB();
    createTable();
}

Database::~Database() {
    closeDB();
}

void Database::closeDB() {
    if (db_.open()) 
        db_.close();
}

void Database::makeDB() {
    closeDB();
    db_ = QSqlDatabase::addDatabase("QSQLITE");

    if (!name_.isEmpty()) {
        db_.setDatabaseName("../zinfo/users.db");
    }
    else {
        qDebug() << "Database name is empty, isn't set: " << db_.lastError().text();
    }

    if (!db_.open()) {
        qDebug() << "Failed to open database: " << db_.lastError().text();
    }
    else {
        qDebug() << "DB open";
    }
}

bool Database::createTable() {
    if (!name_.isEmpty()) {
        QSqlQuery query(db_);
        query.exec("CREATE TABLE IF NOT EXISTS " + name_ + " (name TEXT, phone TEXT, email TEXT, belonging TEXT)");

        if (query.isActive()) {
            qDebug() << "Table created successfully";
            return true;
        } 
        else {
            qDebug() << "Failed to create table:" << query.lastError().text();
            return false;
        }
    }
    return false;
}

QList<Contact> Database::readContacts() {
    QList<Contact> contacts;

    QSqlQuery query(db_);
    if (query.exec("SELECT name, phone, email, belonging FROM " + name_)) {
        while (query.next()) {
            Contact contact;
            contact = {query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString()};
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
        query.prepare("INSERT INTO " + name_ + " (name, phone, email, belonging) VALUES (?, ?, ?, ?)");
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

QSqlDatabase Database::getDatabase() {
    return db_;
}

void Database::setDatabase(const QSqlDatabase& db) {
    db_ = db;
}



/*void Database::openDB(const QString& path, const QString &name, const QString &fields) {
    if (!path.isEmpty()) {
        qDebug() << "Selected File: " << path;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);

        if (db.open()) {
            qDebug() << "Database opened successfully";

            QSqlQuery query(db_);
            if (!query.exec("SELECT * FROM " + name)) {
                if (!query.exec("CREATE TABLE " + name + " " + fields)) {
                    qDebug() << "Failed to create '" + name + "' table: " << query.lastError().text();
                }
            }
        } 
        else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }
}*/

/*contact.name = query.value(0).toString();
contact.phone = query.value(1).toString();
contact.email = query.value(2).toString();
contact.belonging = query.value(3).toString();*/

