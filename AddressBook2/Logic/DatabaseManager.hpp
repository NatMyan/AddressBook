#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include "../DataLayer/Contact.hpp"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class DatabaseManager {
    public:
        // DatabaseManager(QObject *parent = nullptr);
        bool openDatabase(const QString &databaseName);
        void closeDatabase();
        bool createTable();
        QList<Contact> readContacts();
        bool writeContacts(const QList<Contact> &contacts);

    private:
        QSqlDatabase db;
};

#endif // DATABASE_MANAGER_HPP
