#ifndef ADDRESS_BOOK_MODEL_HPP
#define ADDRESS_BOOK_MODEL_HPP

#include "Contact.hpp"
#include "DatabaseManager.hpp"

#include <QObject>
#include <QSqlDatabase>
#include <QVector>

class AddressBookModel : public QObject {
    Q_OBJECT

    public:
        explicit AddressBookModel(QObject* parent = nullptr);

    public:
        bool openDatabase(const QString& name);
        QVector<Contact> retrieveContacts(const QString& tableName, const QString& searchName, const QString& searchOption);

    private:
        DatabaseManager* db_;
};

#endif // ADDRESS_BOOK_MODEL_HPP
   