#include "DatabaseManager.hpp"

/// NOTE: back to this when DBManager is DB somehow
/*DatabaseManager::DatabaseManager() {

}*/

bool DatabaseManager::openDatabase(const QString &databaseName) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databaseName);
    
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::createTable() {
    QSqlQuery query;
    return query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT)");
}

QList<Contact> DatabaseManager::readContacts() {
    QList<Contact> contacts;

    QSqlQuery query;
    if (query.exec("SELECT name, phone, email FROM contacts")) {
        while (query.next()) {
            Contact contact;
            contact.name = query.value(0).toString();
            contact.phone = query.value(1).toString();
            contact.email = query.value(2).toString();
            contacts.append(contact);
        }
    } 
    else {
        qDebug() << "Error reading contacts:" << query.lastError().text();
    }

    return contacts;
}

bool DatabaseManager::writeContacts(const QList<Contact> &contacts) {
    QSqlQuery query;

    if (!query.exec("DELETE FROM contacts")) {
        qDebug() << "Error clearing contacts:" << query.lastError().text();
        return false;
    }

    for (const auto &contact : contacts) {
        query.prepare("INSERT INTO contacts (name, phone, email) VALUES (?, ?, ?)");
        query.addBindValue(contact.name);
        query.addBindValue(contact.phone);
        query.addBindValue(contact.email);

        if (!query.exec()) {
            qDebug() << "Error writing contact:" << query.lastError().text();
            return false;
        }
    }

    return true;
}
