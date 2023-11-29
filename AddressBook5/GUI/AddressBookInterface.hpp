#ifndef ADDRESS_BOOK_INTERFACE_HPP
#define ADDRESS_BOOK_INTERFACE_HPP

#include "../Logic/AddressBookLogic.hpp"
#include "TabNames.hpp"

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlTableModel>

class AddressBookInterface : public QWidget {
    Q_OBJECT

    public:
        AddressBookInterface(AddressBookLogic *logic, QWidget *parent = nullptr);

    public:
        QTableWidget* getCurrentTable() const;

    public slots:
        void addTabClicked();
        void addContactClicked();
        void editContact(QTableWidgetItem *item);
        void openAddressBook();
        void searchContacts();
        void saveAddressBook();
        void showDatabaseContents();
        
    private:
        void setupUi();
        void setupTabs();
        QTableWidget* createEditableTable();
        // QTableWidget* createContactTable();

    private:
        QTabWidget *tabWidget;
        QPushButton *addTabButton;
        QPushButton *addContactButton;
        QPushButton *openButton;
        QPushButton *searchButton;
        QPushButton *saveButton;
        QTableWidget *currentTable;
        QVector<QTableWidget*> currTables;
        TabNames tabNames; 
        AddressBookLogic *logic;
};

#endif // ADDRESS_BOOK_INTERFACE_HPP

