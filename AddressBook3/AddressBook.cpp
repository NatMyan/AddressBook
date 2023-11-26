// AddressBook.cpp
#include "AddressBook.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>

AddressBook::AddressBook(QWidget *parent) : QMainWindow(parent) {
    setupUi();
    setupDatabase();
    setupTable();
}

void AddressBook::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *addButton = new QPushButton("Add", this);
    QPushButton *openButton = new QPushButton("Open", this);
    QPushButton *searchButton = new QPushButton("Search", this);

    tableView = new QTableView(this);
    addressBookTab = new AddressBookTab(this);

    connect(addButton, &QPushButton::clicked, this, &AddressBook::onAddButtonClicked);
    connect(openButton, &QPushButton::clicked, this, &AddressBook::onOpenButtonClicked);
    connect(searchButton, &QPushButton::clicked, this, &AddressBook::onSearchButtonClicked);

    layout->addWidget(addButton);
    layout->addWidget(openButton);
    layout->addWidget(searchButton);
    layout->addWidget(tableView);
    layout->addWidget(addressBookTab);
}

void AddressBook::setupDatabase() {
    // Setup your database connection here
    // For simplicity, we'll use an in-memory database
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(":memory:");

    if (!database.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database");
        QApplication::exit();
    }
}

void AddressBook::setupTable() {
    model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    tableView->setModel(model);
}

void AddressBook::onAddButtonClicked() {
    addressBookTab->addEntry();
}

void AddressBook::onOpenButtonClicked() {
    addressBookTab->openEntry();
}

void AddressBook::onSearchButtonClicked() {
    addressBookTab->show(); // Show the AddressBookTab
    addressBookTab->raise(); // Bring it to the front
}

void AddressBook::openDatabase(const QString &path) {
    // Open an existing database
    database.close();
    database.setDatabaseName(path);

    if (!database.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database");
        return;
    }

    // Load data into the table
    searchContacts("", "", "");
}

void AddressBook::searchContacts(const QString &name, const QString &phone, const QString &email) {
    model->removeRows(0, model->rowCount());

    QSqlQuery query(database);
    query.prepare("SELECT * FROM contacts WHERE name LIKE :name AND phone LIKE :phone AND email LIKE :email");
    query.bindValue(":name", "%" + name + "%");
    query.bindValue(":phone", "%" + phone + "%");
    query.bindValue(":email", "%" + email + "%");

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            model->insertRow(row);
            model->setData(model->index(row, 0), query.value("name").toString());
            model->setData(model->index(row, 1), query.value("phone").toString());
            model->setData(model->index(row, 2), query.value("email").toString());
            ++row;
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to search contacts: " + query.lastError().text());
    }
}
