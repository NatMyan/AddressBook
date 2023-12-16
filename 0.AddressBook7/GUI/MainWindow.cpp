#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

void MainWindow::setupUi() {
    stackedWidget_ = new QStackedWidget(this);
    startMenu_ = new StartMenu(this);
    signInMenu_ = new SignInMenu(this);
    signUpMenu_ = new SignUpMenu(this);
    addressBookInterface_ = new AddressBookInterface(addressBookLogic_, this);
    addressBookLogic_ = new AddressBookLogic(this); // Provide necessary dependencies

    stackedWidget_->addWidget(startMenu_);
    stackedWidget_->addWidget(signInMenu_);
    stackedWidget_->addWidget(signUpMenu_);
    stackedWidget_->addWidget(addressBookInterface_);

    connect(startMenu_, &StartMenu::sigSignInClicked, this, &MainWindow::onSignInClicked);
    connect(startMenu_, &StartMenu::sigSignUpClicked, this, &MainWindow::onSignUpClicked);
    connect(signInMenu_, &SignInMenu::sigSignIn, addressBookLogic_, &AddressBookLogic::signIn);
    connect(signUpMenu_, &SignUpMenu::sigSignUp, addressBookLogic_, &AddressBookLogic::signUp);
    connect(addressBookLogic_, &AddressBookLogic::sigSignInSuccess, this, &MainWindow::onSignInSuccess);
    // connect(addressBookInterface_, &AddressBookInterface::sigSignOutClicked, this, &MainWindow::onSignOutClicked);

    setCentralWidget(stackedWidget_);
    stackedWidget_->setCurrentWidget(startMenu_);
}

void MainWindow::onSignInClicked() {
    stackedWidget_->setCurrentWidget(signInMenu_);
}

void MainWindow::onSignUpClicked() {
    stackedWidget_->setCurrentWidget(signUpMenu_);
}

void MainWindow::onSignInSuccess(QString username) {
    // addressBookInterface_->setUsername(username);
    stackedWidget_->setCurrentWidget(addressBookInterface_);
}

/*void MainWindow::onSignOutClicked() {
    stackedWidget_->setCurrentWidget(startMenu_);
}*/


/*#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent) 
{
    setupUi();
    showDatabaseContents();
}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);
    startMenu = new StartMenu;
    addressBookLogic = new AddressBookLogic;
    addressBookInterface = new AddressBookInterface(addressBookLogic);

    connect(startMenu, &StartMenu::sigSignInClicked, this, &MainWindow::onSignInClicked);
    connect(startMenu, &StartMenu::sigSignUpClicked, this, &MainWindow::onSignUpClicked);
    connect(addressBookLogic, &AddressBookLogic::contactAdded, this, &MainWindow::onContactAdded);
    connect(addressBookLogic, &AddressBookLogic::contactEdited, this, &MainWindow::onContactEdited);
    // connect(addressBookInterface, &AddressBookInterface::tabAdded, addressBookLogic->getAddDialog(), &AddDialog::updateTabNames);

    stackedWidget->addWidget(startMenu);
    stackedWidget->addWidget(addressBookInterface);

    setCentralWidget(stackedWidget);
}

void MainWindow::showDatabaseContents() {
    addressBookInterface->showDatabaseContents();
}

void MainWindow::onSignInClicked() {
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->addContactClicked();
}

void MainWindow::onOpenClicked() {
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->openAddressBook();
}

void MainWindow::onContactAdded() {
    stackedWidget->setCurrentIndex(1);
    addressBookInterface->addContactClicked();
}

void MainWindow::onContactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email, const QString &tab) {
    QTableWidget *editedTable = addressBookInterface->getCurrentTable();

    if (editedTable && rowIndex >= 0 && rowIndex < editedTable->rowCount()) {
        QTableWidgetItem *nameItem = editedTable->item(rowIndex, 0);
        QTableWidgetItem *phoneItem = editedTable->item(rowIndex, 1);
        QTableWidgetItem *emailItem = editedTable->item(rowIndex, 2);
        QTableWidgetItem *tabItem = editedTable->item(rowIndex, 3);

        if (nameItem && phoneItem && emailItem && tabItem) {
            nameItem->setText(name);
            phoneItem->setText(phone);
            emailItem->setText(email);
            tabItem->setText(tab);
        }
    }
}*/


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



