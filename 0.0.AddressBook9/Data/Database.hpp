#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Contact.hpp"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>

class Database : public QSqlDatabase {
    // Q_OBJECT
    
    public:
        Database(const QString &fileName);
        ~Database();

    public:
        void makeDatabase(const QString &fileName);
        void openDatabase(const QString &filePath, const QString &dbName, const QString &fields);
        void closeDatabase();
        bool createTable(const QString &fileName);
        QList<Contact> readContacts(const QString &name);
        bool writeContacts(const QList<Contact> &contacts, const QString &name);
        QSqlDatabase getDatabase();
        void setDatabase(const QSqlDatabase& db);
        void changeDatabaseName(const QString& fileName);

    private:
        QSqlDatabase db_;
        QString fileName_;
};

#endif // DATABASE_HPP
