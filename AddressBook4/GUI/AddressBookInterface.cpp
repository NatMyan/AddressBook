#include "AddressBookInterface.hpp"

#include <QInputDialog>
#include <QHeaderView>

AddressBookInterface::AddressBookInterface(AddressBookLogic *logic, QWidget *parent) :
    QWidget(parent),
    tabWidget(new QTabWidget),
    addTabButton(new QPushButton("+")),
    addContactButton(new QPushButton("Add Contact")),
    openButton(new QPushButton("Open")),
    searchButton(new QPushButton("Search")),
    saveButton(new QPushButton("Save")),
    currentTable(nullptr),
    logic(logic)
{
    setupUi();
    setupTabs();
}

void AddressBookInterface::setupUi() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(tabWidget);
    layout->addWidget(addTabButton);

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
}

void AddressBookInterface::setupTabs() {
    connect(tabWidget, &QTabWidget::currentChanged, [this](int index) {
        if (index == tabWidget->count() - 1) {
            // The last tab ("+") was selected, add a new tab
            addTabClicked();
        } 
        else {
            // Update the current table
            currentTable = qobject_cast<QTableWidget*>(tabWidget->currentWidget());
            currentTable->setProperty("TabIndex", index);
        }
    });

    // Add default tabs
    tabWidget->addTab(createEditableTable(), "Family");
    tabWidget->addTab(createEditableTable(), "Friends");
    tabWidget->addTab(createEditableTable(), "Co-Workers");
    tabWidget->addTab(addTabButton, "+");

    // Connect signals and slots
    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addContactClicked);
    connect(currentTable, &QTableWidget::itemDoubleClicked, this, &AddressBookInterface::editContact);
}

/*QTableWidget* AddressBookInterface::createEditableTable() {
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    return table;
}*/

void AddressBookInterface::addTabClicked() {
    bool ok;
    QString tabName = QInputDialog::getText(this, "New Tab", "Enter tab name:", QLineEdit::Normal, QString(), &ok);

    if (ok && !tabName.isEmpty()) {
        // Add a new editable tab
        QTableWidget *newTable = createEditableTable();
        tabWidget->insertTab(tabWidget->count() - 1, newTable, tabName);
        tabWidget->setCurrentIndex(tabWidget->count() - 2); // Switch to the newly added tab
    }
}

void AddressBookInterface::addContactClicked() {
    if (currentTable)
        logic->addContact();
}

void AddressBookInterface::editContact(QTableWidgetItem *item) {
    if (currentTable)
        logic->editContact(item);
}

void AddressBookInterface::openAddressBook() {
    logic->openAddressBook();
}

void AddressBookInterface::searchContacts() {
    logic->searchContacts();
}

void AddressBookInterface::saveAddressBook() {
    // Placeholder for save functionality
    qDebug() << "Save button clicked";
}

QTableWidget* AddressBookInterface::createEditableTable() {
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(table, &QTableWidget::itemDoubleClicked, this, &AddressBookInterface::editContact);

    return table;
}

QTableWidget* AddressBookInterface::getCurrentTable() const {
    return currentTable;
}

/*
// AddressBookInterface.cpp
#include "AddressBookInterface.hpp"
#include <QInputDialog>

AddressBookInterface::AddressBookInterface(AddressBookLogic *logic, QWidget *parent) :
    QWidget(parent),
    tabWidget(new QTabWidget),
    addTabButton(new QPushButton("+")),
    addContactButton(new QPushButton("Add Contact")),
    openButton(new QPushButton("Open")),
    searchButton(new QPushButton("Search")),
    saveButton(new QPushButton("Save")),
    currentTable(nullptr),
    logic(logic)
{
    setupUi();
}

void AddressBookInterface::setupUi() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(tabWidget);
    layout->addWidget(addTabButton);
    layout->addWidget(addContactButton);
    layout->addWidget(openButton);
    layout->addWidget(searchButton);

    // Connect signals and slots
    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(addContactButton, &QPushButton::clicked, this, &AddressBookInterface::addContactClicked);
    connect(openButton, &QPushButton::clicked, this, &AddressBookInterface::openAddressBook);
    connect(searchButton, &QPushButton::clicked, this, &AddressBookInterface::searchContacts);

    // Placeholder for save functionality
    connect(saveButton, &QPushButton::clicked, this, &AddressBookInterface::saveAddressBook);
}

void AddressBookInterface::addTabClicked() {
    bool ok;
    QString tabName = QInputDialog::getText(this, "New Tab", "Enter tab name:", QLineEdit::Normal, QString(), &ok);

    if (ok && !tabName.isEmpty()) {
        // Add a new editable tab
        QTableWidget *newTable = createEditableTable();
        tabWidget->insertTab(tabWidget->count() - 1, newTable, tabName);
        tabWidget->setCurrentIndex(tabWidget->count() - 2); // Switch to the newly added tab
    }
}

void AddressBookInterface::addContactClicked() {
    if (currentTable)
        logic->addContact();
}

void AddressBookInterface::editContact(QTableWidgetItem *item) {
    if (currentTable)
        logic->editContact(item);
}

void AddressBookInterface::openAddressBook() {
    logic->openAddressBook();
}

void AddressBookInterface::searchContacts() {
    logic->searchContacts();
}

void AddressBookInterface::saveAddressBook() {
    // Placeholder for save functionality
    qDebug() << "Save button clicked";
}

QTableWidget* AddressBookInterface::createEditableTable() {
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connect signals and slots
    connect(table, &QTableWidget::itemDoubleClicked, this, &AddressBookInterface::editContact);

    return table;
}
*/