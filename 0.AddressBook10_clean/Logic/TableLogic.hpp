#ifndef TABLE_LOGIC_HPP
#define TABLE_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
#include "../GUI/SearchDialog.hpp"
#include "../Data/AddressBookModel.hpp"
#include "../GUI/TableInterface.hpp"

#include <QObject>
#include <QDialog>

class TableLogic : public QObject {
    Q_OBJECT

    public:
        explicit TableLogic(TableInterface* tableInterface, AddressBookModel* addressBookModel, QObject* parent = nullptr);

    public:
        void showSearchResult(const QVector<Contact>& qVec);

    public slots:
        void onAddContactClicked2();
        void onSearchClicked();
        void onSignOutClicked();

    private slots:
        void onAddAccepted(const QString& name, const QString& phone, const QString& email, const QString& tab);
        void onSearchAccepted(const QString &name, const QString &searchName, const QString &searchOption);

    signals:
        void sigContactAdded(const QString& name, const QString& phone, const QString& email, const QString& tab);
        void sigSearchClicked(); 
        void sigSignOutClicked();

    private:
        // void showSearchResult(const QVector<Contact>& qVec);
        QString determineTableName();

    private:
        DatabaseManager* dbManager_;
        TableInterface* tableInterface_;
        AddressBookModel* addressBookModel_;
        AddDialog* addDialog_;
        SearchDialog* searchDialog_;
        User user_;
};
    
#endif // TABLE_LOGIC_HPP



/*
// TableLogic.hpp
#ifndef TABLE_LOGIC_HPP
#define TABLE_LOGIC_HPP

#include <QObject>
#include "AddDialog.hpp"
#include "SearchDialog.hpp"

class TableLogic : public QObject {
    Q_OBJECT

public:
    TableLogic(QObject* parent = nullptr);

public slots:
    void onAddContactClicked();
    void onSearchClicked();

private slots:
    void onAddDialogAccepted(const QString& name, const QString& phone, const QString& email, const QString& tab);
    void onSearchDialogAccepted(const QString& searchName, const QString& searchOption);

private:
    AddDialog* addDialog_;
    SearchDialog* searchDialog_;

    // Your other logic components and methods go here
};

#endif // TABLE_LOGIC_HPP
// TableLogic.cpp
#include "TableLogic.hpp"
#include "TableInterface.hpp"  // Assuming you have a TableInterface class

TableLogic::TableLogic(QObject* parent) : QObject(parent) {
    addDialog_ = new AddDialog;
    searchDialog_ = new SearchDialog;

    connect(addDialog_, &AddDialog::contactAdded, this, &TableLogic::onAddDialogAccepted);
    connect(searchDialog_, &SearchDialog::sigAccepted, this, &TableLogic::onSearchDialogAccepted);

    // Connect other signals and slots as needed
}

void TableLogic::onAddContactClicked() {
    addDialog_->exec();
}

void TableLogic::onSearchClicked() {
    searchDialog_->exec();
}

void TableLogic::onAddDialogAccepted(const QString& name, const QString& phone, const QString& email, const QString& tab) {
    // Handle the added contact, e.g., pass it to your model or update the UI
    emit sigAddContactClicked();  // Emit your custom signal or update UI directly
}

void TableLogic::onSearchDialogAccepted(const QString& searchName, const QString& searchOption) {
    // Handle the search criteria, e.g., pass it to your model or update the UI
    emit sigSearchClicked();  // Emit your custom signal or update UI directly
}
*/

/*
#ifndef TABLE_LOGIC_HPP
#define TABLE_LOGIC_HPP

#include <QObject>
#include <QDialog>
#include "TableInterface.hpp"
#include "AddContactDialog.hpp"
#include "SearchDialog.hpp"
#include "AddressBookModel.hpp"

class TableLogic : public QObject {
    Q_OBJECT

public:
    TableLogic(TableInterface* tableInterface, AddressBookModel* addressBookModel, QObject* parent = nullptr);

public slots:
    void onAddContactClicked();
    void onSearchClicked();
    void onSignOutClicked();

private:
    TableInterface* tableInterface_;
    AddressBookModel* addressBookModel_;
    AddContactDialog* addContactDialog_;
    SearchDialog* searchDialog_;

    void connectSignalsAndSlots();

private slots:
    void onAddContactAccepted(const Contact& contact);
    void onSearchAccepted(const QString& searchName, const QString& searchOption);
};

#endif // TABLE_LOGIC_HPP
#include "TableLogic.hpp"

TableLogic::TableLogic(TableInterface* tableInterface, AddressBookModel* addressBookModel, QObject* parent)
    : QObject(parent), tableInterface_(tableInterface), addressBookModel_(addressBookModel),
      addContactDialog_(new AddContactDialog()), searchDialog_(new SearchDialog()) {
    connectSignalsAndSlots();
}

void TableLogic::connectSignalsAndSlots() {
    connect(tableInterface_, &TableInterface::sigAddContactClicked, this, &TableLogic::onAddContactClicked);
    connect(tableInterface_, &TableInterface::sigSearchClicked, this, &TableLogic::onSearchClicked);
    connect(tableInterface_, &TableInterface::sigSignOutClicked, this, &TableLogic::onSignOutClicked);

    connect(addContactDialog_, &AddContactDialog::sigAccepted, this, &TableLogic::onAddContactAccepted);
    connect(searchDialog_, &SearchDialog::sigAccepted, this, &TableLogic::onSearchAccepted);
}

void TableLogic::onAddContactClicked() {
    addContactDialog_->clearFields();
    addContactDialog_->show();
}

void TableLogic::onSearchClicked() {
    searchDialog_->clearFields();
    searchDialog_->show();
}

void TableLogic::onSignOutClicked() {
    // Handle sign out logic here
}

void TableLogic::onAddContactAccepted(const Contact& contact) {
    // Add contact to the database using AddressBookModel
    // For example: addressBookModel_->addContact(contact);

    // Refresh the displayed data in the table or perform any necessary updates
    // tableInterface_->updateTable();

    // Optionally, you can emit a signal to inform other components about the addition
    // emit sigContactAdded(contact);
}

void TableLogic::onSearchAccepted(const QString& searchName, const QString& searchOption) {
    // Perform a search in the database using AddressBookModel
    // For example: QVector<Contact> searchResults = addressBookModel_->searchContacts(searchName, searchOption);

    // Update the displayed data in the table with searchResults
    // tableInterface_->showSearchResults(searchResults);
}
*/