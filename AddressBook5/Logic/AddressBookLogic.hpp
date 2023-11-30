#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
#include "../GUI/OpenDialog.hpp"
#include "../GUI/SearchDialog.hpp"
#include "../GUI/SaveDialog.hpp"
#include "../Data/Database.hpp"

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>

class AddressBookLogic : public QObject {
    Q_OBJECT

    public:
        explicit AddressBookLogic(QObject *parent = nullptr);

    public:
        void createTable();
        QSqlDatabase getDB();

    public slots:
        void addContact();
        void editContact(QTableWidgetItem *item);
        void openAddressBook();
        void searchContacts();
        void saveAddressBook();
        // void addContactToDatabase(const QString &name, const QString &phone, const QString &email, const QString &tab);

    signals:
        void contactAdded(const QString &name, const QString &phone, const QString &email, const QString &tab);
        void contactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email, const QString &tab);

    /*private slots:
        void handleAddContactRequest();*/

    private:
        Database db;
        AddDialog *addDialog; 
        OpenDialog *openDialog;
        SearchDialog *searchDialog;
        SaveDialog *saveDialog;
};

#endif // ADDRESS_BOOK_LOGIC_HPP

