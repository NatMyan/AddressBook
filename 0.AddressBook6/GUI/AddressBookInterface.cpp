#include "AddressBookInterface.hpp"
#include "AddDialog.hpp"
#include "SearchResultDialog.hpp"

AddressBookInterface::AddressBookInterface(AddressBookLogic* logic, QWidget* parent) :
    QWidget(parent), 
    logic_(logic) 
{
    setupUi();
}

void AddressBookInterface::onAddContactClicked() {
    // Add contact button clicked, show a dialog or perform related actions
    AddDialog aDialog;
    aDialog.exec();
}

void AddressBookInterface::onSearchClicked(const QString& searchOption, const QString& searchName) {
    // Search button clicked, trigger logic for searching contacts
    auto searchResults = logic_->searchContacts(searchOption, searchName);
    SearchResultDialog resultDialog(searchResults, this);
    resultDialog.showSearchResultDialog();
}

void AddressBookInterface::setupUi() {
    // Initialize UI components
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Table for displaying contacts
    contactTable_ = new QTableWidget(this);

    // Search components
    QHBoxLayout* searchLayout = new QHBoxLayout;
    searchNameLineEdit_ = new QLineEdit(this);
    searchOptionComboBox_ = new QComboBox(this);
    QPushButton* searchButton = new QPushButton("Search", this);
    connect(searchButton, &QPushButton::clicked, this, &AddressBookInterface::onSearchClicked);

    // Add components to layouts
    searchLayout->addWidget(searchNameLineEdit_);
    searchLayout->addWidget(searchOptionComboBox_);
    searchLayout->addWidget(searchButton);

    // Add components to the main layout
    mainLayout->addWidget(contactTable_);
    mainLayout->addLayout(searchLayout);

    // Connect signals and slots
    connect(logic_, &AddressBookLogic::updateTable, this, [this] { /* Update UI when the table changes */ });

    // Initialize the tab widget
    tabWidget_ = new QTabWidget(this);
    connect(tabWidget_, &QTabWidget::currentChanged, this, &AddressBookInterface::onTabChanged);
    mainLayout->addWidget(tabWidget_);

    // Initialize tabs
    updateTabNames();
}

void AddressBookInterface::updateTabNames() {
    QVector<QString> tabNames = tabNames_.getTabNames();
    for (const auto& tabName : tabNames) {
        auto tab = new QWidget(tabWidget_);
        tabWidget_->addTab(tab, tabName);
    }
}

void AddressBookInterface::onTabChanged(int index) {
    // Handle tab change, update the displayed contacts based on the selected tab
    // You can use the tab index to filter the contacts from the database
    // and update the table accordingly
    logic_->filterContactsByTab(tabWidget_->tabText(index));
}

/*#include "AddressBookInterface.hpp"

AddressBookInterface::AddressBookInterface(const QString& username, QWidget* parent) : 
    QWidget(parent), 
    username_(username),
    database_("../zinfo/" + username + ".db") 
{
    setupUi();
    updateTable();
    createTabs();
}

void AddressBookInterface::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    addButton_ = new QPushButton("Add", this);
    searchButton_ = new QPushButton("Search", this);
    contactTable_ = new QTableWidget(this);
    tabWidget_ = new QTabWidget(this);

    connect(addButton_, &QPushButton::clicked, this, &AddressBookInterface::onAddButtonClicked);
    connect(searchButton_, &QPushButton::clicked, this, &AddressBookInterface::onSearchButtonClicked);

    mainLayout->addWidget(addButton_);
    mainLayout->addWidget(searchButton_);
    mainLayout->addWidget(tabWidget_);
    mainLayout->addWidget(contactTable_);
}

void AddressBookInterface::updateTable() {
    contactTable_->clearContents();
    contactTable_->setRowCount(0);

    QList<Contact> contacts = database_.readContacts();

    int row = 0;
    for (const Contact& contact : contacts) {
        contactTable_->insertRow(row);
        contactTable_->setItem(row, 0, new QTableWidgetItem(contact.name));
        contactTable_->setItem(row, 1, new QTableWidgetItem(contact.phone));
        contactTable_->setItem(row, 2, new QTableWidgetItem(contact.email));
        contactTable_->setItem(row, 3, new QTableWidgetItem(contact.belonging));
        ++row;
    }
}

void AddressBookInterface::createTabs() {
    QStringList tabNames = TabNames::getTabNames();

    for (const QString& tabName : tabNames) {
        QWidget* tab = new QWidget(tabWidget_);
        // Customize the tab widget based on your needs

        // Example: Display the contacts with the same tab/belonging in a tab
        QList<Contact> contacts = database_.readContacts();
        QList<Contact> filteredContacts;
        for (const Contact& contact : contacts) {
            if (contact.belonging == tabName) {
                filteredContacts.append(contact);
            }
        }

        QTableWidget* tabTable = new QTableWidget(tab);
        tabTable->setColumnCount(4);
        tabTable->setHorizontalHeaderLabels({ "Name", "Phone", "Email", "Tab" });

        int row = 0;
        for (const Contact& contact : filteredContacts) {
            tabTable->insertRow(row);
            tabTable->setItem(row, 0, new QTableWidgetItem(contact.name));
            tabTable->setItem(row, 1, new QTableWidgetItem(contact.phone));
            tabTable->setItem(row, 2, new QTableWidgetItem(contact.email));
            tabTable->setItem(row, 3, new QTableWidgetItem(contact.belonging));
            ++row;
        }

        QVBoxLayout* tabLayout = new QVBoxLayout(tab);
        tabLayout->addWidget(tabTable);

        tabWidget_->addTab(tab, tabName);
    }
}

void AddressBookInterface::onAddButtonClicked() {
    AddDialog addDialog(this);
    if (addDialog.exec() == QDialog::Accepted) {
        QString name = addDialog.name();
        QString phone = addDialog.phone();
        QString email = addDialog.email();
        QString tab = addDialog.selectedTab();

        // Save the new contact to the database
        database_.writeContacts({{name, phone, email, tab}});

        // Update the table
        updateTable();
    }
}

void AddressBookInterface::onSearchButtonClicked() {
    SearchDialog searchDialog(this);
    if (searchDialog.exec() == QDialog::Accepted) {
        QString searchName = searchDialog.getSearchName();
        QString searchOption = searchDialog.getSearchOption();

        // Perform search
        performSearch(searchName, searchOption);
    }
}

void AddressBookInterface::performSearch(const QString& searchName, const QString& searchOption) {
    // Perform your search logic based on searchName and searchOption
    // For example, search by name
    QList<Contact> searchResults;

    QList<Contact> contacts = database_.readContacts();
    for (const Contact& contact : contacts) {
        if (searchOption == "name")
            if (contact.name.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
        else if (searchOption == "phone")
            if (contact.phone.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
        else if (searchOption == "email")
            if (contact.email.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
    }

    // Display search results in a dialog
    SearchResultDialog resultDialog(searchResults, this);
    resultDialog.showSearchResultDialog();
}

void AddressBookInterface::onContactAdded(const QString& name, const QString& phone, const QString& email, const QString& tab) {
    // Handle contact added signal (if needed)
    // For example, update the table
    updateTable();
}*/

/*
// ... (previous code)

void AddressBookInterface::updateTable() {
    contactTable_->clearContents();
    contactTable_->setRowCount(0);

    QList<Contact> contacts = database_.readContacts();

    int row = 0;
    for (const Contact& contact : contacts) {
        contactTable_->insertRow(row);
        contactTable_->setItem(row, 0, new QTableWidgetItem(contact.name));
        contactTable_->setItem(row, 1, new QTableWidgetItem(contact.phone));
        contactTable_->setItem(row, 2, new QTableWidgetItem(contact.email));
        contactTable_->setItem(row, 3, new QTableWidgetItem(contact.belonging));
        ++row;
    }
}

void AddressBookInterface::createTabs() {
    QStringList tabNames = TabNames::getTabNames();

    for (const QString& tabName : tabNames) {
        QWidget* tab = new QWidget(tabWidget_);
        // Customize the tab widget based on your needs

        // Example: Display the contacts with the same tab/belonging in a tab
        QList<Contact> contacts = database_.readContacts();
        QList<Contact> filteredContacts;
        for (const Contact& contact : contacts) {
            if (contact.belonging == tabName) {
                filteredContacts.append(contact);
            }
        }

        QTableWidget* tabTable = new QTableWidget(tab);
        tabTable->setColumnCount(4);
        tabTable->setHorizontalHeaderLabels({ "Name", "Phone", "Email", "Tab" });

        int row = 0;
        for (const Contact& contact : filteredContacts) {
            tabTable->insertRow(row);
            tabTable->setItem(row, 0, new QTableWidgetItem(contact.name));
            tabTable->setItem(row, 1, new QTableWidgetItem(contact.phone));
            tabTable->setItem(row, 2, new QTableWidgetItem(contact.email));
            tabTable->setItem(row, 3, new QTableWidgetItem(contact.belonging));
            ++row;
        }

        QVBoxLayout* tabLayout = new QVBoxLayout(tab);
        tabLayout->addWidget(tabTable);

        tabWidget_->addTab(tab, tabName);
    }
}

void AddressBookInterface::performSearch(const QString& searchName, const QString& searchOption) {
    // Perform your search logic based on searchName and searchOption
    // For example, search by name
    QList<Contact> searchResults;

    QList<Contact> contacts = database_.readContacts();
    for (const Contact& contact : contacts) {
        if (contact.name.contains(searchName, Qt::CaseInsensitive)) {
            searchResults.append(contact);
        }
    }

    // Display search results in a dialog
    SearchResultDialog resultDialog(searchResults, this);
    resultDialog.showSearchResultDialog();
}

// ... (remaining code)
*/