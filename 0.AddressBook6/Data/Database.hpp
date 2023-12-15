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
        void openDatabase(const QString &filePath);
        void closeDatabase();
        bool createTable();
        QList<Contact> readContacts();
        bool writeContacts(const QList<Contact> &contacts);
        QSqlDatabase getDatabase();
        void setDatabase(const QSqlDatabase& db);
        void changeDatabaseName(const QString& fileName);

    private:
        QSqlDatabase db_;
};

#endif // DATABASE_HPP
