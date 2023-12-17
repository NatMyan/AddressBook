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

    signals:
        void sigTabAdded(const QString& tabName);
        void sigSignOutClicked();

    public slots:
        void onAddTabClicked();
        void onAddContactClicked();
        void onSignOutClicked();
        void onEditContact(QTableWidgetItem *item);
        void onSearchContacts();
        void onShowDatabaseContents();
        // void openAddressBook();
        // void saveAddressBook();
        
    private:
        void setupUi();
        void setupTabs();
        QTableWidget* createEditableTable();
        // QTableWidget* createContactTable();

    private:
        QTabWidget *tabWidget;
        QPushButton *addTabButton;
        QPushButton *addContactButton;
        QPushButton *searchButton;
        QPushButton *signOutButton;
        QTableWidget *currentTable;
        QVector<QTableWidget*> currTables;
        TabNames tabNames; 
        AddressBookLogic *logic;
        // QPushButton *openButton;
        // QPushButton *saveButton;
};

#endif // ADDRESS_BOOK_INTERFACE_HPP

