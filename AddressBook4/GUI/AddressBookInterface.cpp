#include "AddressBookInterface.hpp"

#include <QInputDialog>
#include <QHeaderView>

AddressBookInterface::AddressBookInterface(AddressBookLogic *logic, QWidget *parent) :
    QWidget(parent),
    tabWidget(new QTabWidget),
    addTabButton(new QPushButton("Add Tab")),
    addContactButton(new QPushButton("Add")),
    openButton(new QPushButton("Open")),
    searchButton(new QPushButton("Search")),
    saveButton(new QPushButton("Save")),
    currentTable(new QTableWidget),
    logic(logic)
{
    setupUi();
    setupTabs();
}

void AddressBookInterface::setupUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addContactButton);
    buttonLayout->addWidget(openButton);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addWidget(saveButton);
    
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(addTabButton);
    mainLayout->addWidget(tabWidget);

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(addContactButton, &QPushButton::clicked, this, &AddressBookInterface::addContactClicked);
    connect(openButton, &QPushButton::clicked, this, &AddressBookInterface::openAddressBook);
    connect(searchButton, &QPushButton::clicked, this, &AddressBookInterface::searchContacts);
    connect(saveButton, &QPushButton::clicked, this, &AddressBookInterface::saveAddressBook);
}

void AddressBookInterface::setupTabs() {
    /*connect(tabWidget, &QTabWidget::currentChanged, [this](int index) {
        if (index == tabWidget->count() - 1) {
            addTabClicked();
        } 
        else {
            currentTable = qobject_cast<QTableWidget*>(tabWidget->currentWidget());
            currentTable->setProperty("TabIndex", index);
        }
    });*/

    tabWidget->addTab(createEditableTable(), "Family");
    tabWidget->addTab(createEditableTable(), "Friends");
    tabWidget->addTab(createEditableTable(), "Co-Workers");
    tabWidget->addTab(addTabButton, "+");

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(currentTable, &QTableWidget::itemDoubleClicked, this, &AddressBookInterface::editContact);
}

void AddressBookInterface::addTabClicked() {
    bool ok;
    QString tabName = QInputDialog::getText(this, "New Tab", "Enter tab name:", QLineEdit::Normal, QString(), &ok);

    if (ok && !tabName.isEmpty()) {
        QTableWidget *newTable = createEditableTable();
        tabWidget->insertTab(tabWidget->count() - 1, newTable, tabName);
        tabWidget->setCurrentIndex(tabWidget->count() - 2);
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
    qDebug() << "Save button clicked";
    logic->saveAddressBook();
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


/*QPushButton* AddressBookInterface::createAddTabButton() {
    QPushButton* addTabButton = new QPushButton("+");
    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    return addTabButton;
}*/

/*void AddressBookInterface::setupUi() {
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(addTabButton);
    layout->addWidget(tabWidget);

    QHBoxLayout *nlayout = new QHBoxLayout(this);
    nlayout->addWidget(addContactButton);
    nlayout->addWidget(openButton);
    nlayout->addWidget(searchButton);
    nlayout->addWidget(saveButton);

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(addContactButton, &QPushButton::clicked, this, &AddressBookInterface::addContactClicked);
    connect(openButton, &QPushButton::clicked, this, &AddressBookInterface::openAddressBook);
    connect(searchButton, &QPushButton::clicked, this, &AddressBookInterface::searchContacts);
    connect(saveButton, &QPushButton::clicked, this, &AddressBookInterface::saveAddressBook);
}*/

/*QTableWidget* AddressBookInterface::createEditableTable() {
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    return table;
}*/

/*void AddressBookInterface::addContact(const QString &name, const QString &phone, const QString &email, const QString &tab) {
    QTableWidget *table = getCurrentTable();

    if (table) {
        int rowIndex = table->rowCount();
        table->insertRow(rowIndex);
        table->setItem(rowIndex, 0, new QTableWidgetItem(name));
        table->setItem(rowIndex, 1, new QTableWidgetItem(phone));
        table->setItem(rowIndex, 2, new QTableWidgetItem(email));

        // ... any additional logic for handling tabs ...
    }
}*/

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