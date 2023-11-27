#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent) 
{
    setupUi();
}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);
    startMenu = new StartMenu;
    addressBookLogic = new AddressBookLogic;
    addressBookInterface = new AddressBookInterface(addressBookLogic);

    // connect(startMenu, &StartMenu::addClicked, this, &MainWindow::onAddClicked);
    connect(startMenu, &StartMenu::openClicked, this, &MainWindow::onOpenClicked);
    connect(addressBookLogic, &AddressBookLogic::contactAdded, this, &MainWindow::onContactAdded);
    connect(addressBookLogic, &AddressBookLogic::contactEdited, this, &MainWindow::onContactEdited);

    stackedWidget->addWidget(startMenu);
    stackedWidget->addWidget(addressBookInterface);

    setCentralWidget(stackedWidget);
}

void MainWindow::onAddClicked() {
    // Show the AddressBookInterface when the 'Add' button is clicked
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->addContactClicked();
}

void MainWindow::onOpenClicked() {
    // Show the AddressBookInterface when the 'Open' button is clicked
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->openAddressBook();
}

void MainWindow::onContactAdded(const QString &name, const QString &phone, const QString &email) {
    // Show the AddressBookInterface when a contact is added
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->addContactClicked();
}

void MainWindow::onContactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email) {
    // Handle contact editing logic
    QTableWidget *editedTable = addressBookInterface->getCurrentTable();

    if (editedTable && rowIndex >= 0 && rowIndex < editedTable->rowCount()) {
        QTableWidgetItem *nameItem = editedTable->item(rowIndex, 0);
        QTableWidgetItem *phoneItem = editedTable->item(rowIndex, 1);
        QTableWidgetItem *emailItem = editedTable->item(rowIndex, 2);

        if (nameItem && phoneItem && emailItem) {
            nameItem->setText(name);
            phoneItem->setText(phone);
            emailItem->setText(email);
        }
    }
}


/*MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);
    startMenu = new StartMenu;
    addressBookLogic = new AddressBookLogic;
    addressBookInterface = new AddressBookInterface(addressBookLogic);

    connect(startMenu, &StartMenu::addClicked, this, &MainWindow::onAddClicked);
    connect(startMenu, &StartMenu::openClicked, this, &MainWindow::onOpenClicked);
    connect(addressBookLogic, &AddressBookLogic::contactAdded, this, &MainWindow::onContactAdded);
    connect(addressBookLogic, &AddressBookLogic::contactEdited, this, &MainWindow::onContactEdited);

    stackedWidget->addWidget(startMenu);
    stackedWidget->addWidget(addressBookInterface);

    setCentralWidget(stackedWidget);
}

void MainWindow::onAddClicked() {
    stackedWidget->setCurrentIndex(1); // Switch to the AddressBookInterface
    addressBookInterface->addContactClicked();
    // addressBookInterface->addTabClicked();
}

void MainWindow::onOpenClicked() {
    stackedWidget->setCurrentIndex(1); // Switch to the AddressBookInterface
    addressBookInterface->openAddressBook();
}

void MainWindow::onContactAdded(const QString &name, const QString &phone, const QString &email) {
    stackedWidget->setCurrentIndex(1); // Switch to the AddressBookInterface
    // addressBookInterface->addContactClicked();
    addressBookInterface->addTabClicked();
}

void MainWindow::onContactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email) {
    QTableWidget *editedTable = addressBookInterface->getCurrentTable();

    if (editedTable && rowIndex >= 0 && rowIndex < editedTable->rowCount()) {
        QTableWidgetItem *nameItem = editedTable->item(rowIndex, 0);
        QTableWidgetItem *phoneItem = editedTable->item(rowIndex, 1);
        QTableWidgetItem *emailItem = editedTable->item(rowIndex, 2);

        if (nameItem && phoneItem && emailItem) {
            nameItem->setText(name);
            phoneItem->setText(phone);
            emailItem->setText(email);
        }
    }
}*/



