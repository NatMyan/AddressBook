#include "AddressBookModel.hpp"

#include <QSqlQuery>
#include <QDebug>

AddressBookModel::AddressBookModel(QObject* parent) :
    QObject(parent) 
{}

bool AddressBookModel::openDatabase(const QString& name) {
    db_ = new Database(name);
}

QVector<Contact> AddressBookModel::retrieveContacts(const QString& tableName, const QString& searchName, const QString& searchOption) {
    QVector<Contact> contacts;

    QSqlQuery query;
    QString queryString = "SELECT * FROM " + tableName + " WHERE " + searchOption + " LIKE '%" + searchName + "%'";
    if (query.exec(queryString)) {
        while (query.next()) {
            Contact contact;
            contact = { query.value("name").toString(), query.value("phone").toString(), 
                        query.value("email").toString(), query.value("belonging").toString() };
            contacts.append(contact);
        }
    } 
    else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    return contacts;
}
   