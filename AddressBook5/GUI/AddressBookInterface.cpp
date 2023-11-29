#include "AddressBookInterface.hpp"

#include <QInputDialog>
#include <QHeaderView>
#include <QSqlTableModel>
#include <QStandardItemModel>

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
    showDatabaseContents();
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

    for (int i = 0; i < tabNames.getTabNames().size(); ++i) {
        QTableWidget *table = new QTableWidget;
        tabWidget->addTab(table, tabNames.getTabNames().at(i));
        // tables.addTable(table);
    }
    tabWidget->addTab(addTabButton, "+");

    currentTable = qobject_cast<QTableWidget*>(tabWidget->widget(0));

    // tabWidget->addTab(currentTable, "I am table");
    // tabWidget->addTab(tabW);
    
    mainLayout->addWidget(tabWidget);

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(addContactButton, &QPushButton::clicked, this, &AddressBookInterface::addContactClicked);
    connect(openButton, &QPushButton::clicked, this, &AddressBookInterface::openAddressBook);
    connect(searchButton, &QPushButton::clicked, this, &AddressBookInterface::searchContacts);
    connect(saveButton, &QPushButton::clicked, this, &AddressBookInterface::saveAddressBook);
}

void AddressBookInterface::setupTabs() {
    /*tabWidget->addTab(createEditableTable(), "Family");
    tabWidget->addTab(createEditableTable(), "Friends");
    tabWidget->addTab(createEditableTable(), "Co-Workers");
    tabWidget->addTab(addTabButton, "+");*/

    connect(tabWidget, &QTabWidget::currentChanged, [this](int index) {
        if (index == tabWidget->count() - 1) {
            addTabClicked();
        } 
        else {
            currentTable = qobject_cast<QTableWidget*>(tabWidget->widget(index));
            currentTable->setProperty("TabName", tabWidget->tabText(index));
        }
    });

    connect(addTabButton, &QPushButton::clicked, this, &AddressBookInterface::addTabClicked);
    connect(currentTable, &QTableWidget::itemDoubleClicked, this, &AddressBookInterface::editContact);
}

void AddressBookInterface::addTabClicked() {
    bool ok;
    QString tabName = QInputDialog::getText(this, "New Tab", "Enter tab name:", QLineEdit::Normal, QString(), &ok);

    if (ok && !tabName.isEmpty()) {
        QTableWidget *newTable = new QTableWidget;
        tabWidget->insertTab(tabWidget->count() - 1, newTable, tabName);
        tabWidget->setCurrentIndex(tabWidget->count() - 2);
    }
}

void AddressBookInterface::showDatabaseContents() {
    if (currentTable) {
        currentTable->clearContents();
        currentTable->setRowCount(0);

        QSqlTableModel model(nullptr, logic->getDB());
        model.setTable("contacts");
        // model.setFilter("tab = '" + currentTable->property("TabName").toString() + "'");
        if (model.select()) {
            int rowCount = model.rowCount();
            int columnCount = model.columnCount();
            qDebug() << rowCount << columnCount;

            currentTable->setRowCount(rowCount);
            currentTable->setColumnCount(columnCount);

            qDebug() << rowCount << columnCount;

            for (int row = 0; row < rowCount; ++row) {
                for (int col = 0; col < columnCount; ++col) {
                    QTableWidgetItem *item = new QTableWidgetItem(model.data(model.index(row, col)).toString());
                    currentTable->setItem(row, col, item);
                }

                QTableWidgetItem *tabItem = new QTableWidgetItem(currentTable->property("TabName").toString());
                currentTable->setItem(row, columnCount, tabItem);
            }
        } 
        else {
            qDebug() << "Failed to fetch database contents: " << model.lastError().text();
        }
    }
}

void AddressBookInterface::addContactClicked() {
    if (currentTable) {
        logic->addContact();
        showDatabaseContents();
    }
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


/*QStandardItemModel* convertToStandardItemModel(QSqlTableModel* tableModel) {
    QStandardItemModel* standardModel = new QStandardItemModel();

    standardModel->setRowCount(tableModel->rowCount());
    standardModel->setColumnCount(tableModel->columnCount());

    for (int row = 0; row < tableModel->rowCount(); ++row) {
        for (int column = 0; column < tableModel->columnCount(); ++column) {
            QModelIndex index = tableModel->index(row, column);
            QVariant data = tableModel->data(index);
            QStandardItem* item = new QStandardItem(data.toString());
            standardModel->setItem(row, column, item);
        }
    }
    return standardModel;
}*/

/*

void AddressWidget::showAddEntryDialog() {
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), aDialog.phone(), aDialog.email());
}

void AddressWidget::showOpenEntryDialog() {
    OpenDialog oDialog;

    if (oDialog.exec())
        openEntry(oDialog.getSelectedFilePath());
}

void AddressWidget::addEntry(const QString &name, const QString &phone, const QString &email) {
    if (!table->getContacts().contains({ name, phone, email })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);

        index = table->index(0, 1, QModelIndex());
        table->setData(index, phone, Qt::EditRole);

        index = table->index(0, 2, QModelIndex());
        table->setData(index, email, Qt::EditRole);

        removeTab(indexOf(newAddressTab));
    } 
    else {
        QMessageBox::information(this, tr("Duplicate Name"), tr("The name \"%1\" already exists.").arg(name));
    }
}

void AddressWidget::openEntry(const QString &filePath) {
    if (dbManager->openDatabase(filePath)) {
        readFromDatabase();
    } 
    else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database."));
    }
}
*/

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