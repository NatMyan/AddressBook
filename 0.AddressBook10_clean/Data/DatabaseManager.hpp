#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include "Contact.hpp"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class DatabaseManager {
    public:
        DatabaseManager(const QString& name);
        ~DatabaseManager();
    
    public:
        void makeDB();
        void closeDB();
        bool createTable();
        // void openDB(const QString& path, const QString &name, const QString &fields); // someone else should open db, not db itself

        QList<Contact> readContacts();
        bool writeContacts(const QList<Contact>& contacts);

        QSqlDatabase getDatabase();
        void setDatabase(const QSqlDatabase& db);
    
    private:
        QSqlDatabase db_;
        QString name_;
};

#endif // DATABASE_MANAGER_HPP