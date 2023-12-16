#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../Data/Database.hpp"
#include "../Data/Contact.hpp"

#include <QObject>

class AddressBookLogic : public QObject {
    Q_OBJECT

    public:
        AddressBookLogic(const QString& username);

    public slots:
        void addContact(const QString& name, const QString& phone, const QString& email, const QString& belonging);
        QList<Contact> searchContacts(const QString& searchOption, const QString& searchName);
        void filterContactsByTab(const QString& tabName);

    signals:
        void updateTable();

    private:
        Database database_;
        // Add other private members and methods as needed
};

#endif // ADDRESS_BOOK_LOGIC_HPP

