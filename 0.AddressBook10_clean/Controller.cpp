#include "Controller.hpp"

Controller::Controller(int argc, char *argv[]) : 
    QApplication(argc, argv)
{
    signInLogic_ = new SignInMenuLogic(this);
    signUpLogic_ = new SignUpMenuLogic(this);
    mainWindow_ = new MainWindow();
    addressBookModel_ = new AddressBookModel(this);
    tableLogic_ = new TableLogic(mainWindow_->getTableInterface(), addressBookModel_, this);

    setupConnections();
}

void Controller::setupConnections() {
    connect(mainWindow_, &MainWindow::sigSignInToAddressBook, this, &Controller::onSignIn);
    connect(mainWindow_, &MainWindow::sigSignUpToAddressBook, this, &Controller::onSignUp);
    connect(mainWindow_, &MainWindow::onSignOutClicked, this, &Controller::onSignOut);

    connect(tableLogic_, &TableLogic::sigContactAdded, mainWindow_->getTableInterface(), &TableInterface::onAddContactClicked);
    connect(tableLogic_, &TableLogic::sigSearchClicked, mainWindow_->getTableInterface(), &TableInterface::onSearchContacts);
    connect(tableLogic_, &TableLogic::sigSearchClicked, this, &Controller::onTableSearchClicked);

    connect(mainWindow_->getTableInterface(), &TableInterface::sigAddContactClicked, tableLogic_, &TableLogic::onAddContactClicked2);
    connect(mainWindow_->getTableInterface(), &TableInterface::sigSearchClicked, tableLogic_, &TableLogic::onSearchClicked);

    connect(signInLogic_, &SignInMenuLogic::sigSignInSuccess, this, &Controller::onSignIn);
    connect(signUpLogic_, &SignUpMenuLogic::sigSignUpSuccess, this, &Controller::onSignUp);
}

void Controller::onSignIn(QString& username, QString& password) {
    signInLogic_->signIn(username, password);
}

void Controller::onSignUp(QString& username, QString& password) {
    signUpLogic_->signUp(username, password);
}

void Controller::onSignOut() {
    // Implement the logic to handle sign-out
    mainWindow_->onSignOutClicked();
}

void Controller::onTableAddContact(const QString& name, const QString& phone, const QString& email, const QString& tab) {
    tableLogic_->onAddContactClicked2();
}

void Controller::onTableSearchClicked() {
    tableLogic_->onSearchClicked();
}

void Controller::onSearchAccepted(const QString& name, const QString& searchName, const QString& searchOption) {
    QVector<Contact> searchResults = addressBookModel_->retrieveContacts(name, searchName, searchOption);
    tableLogic_->showSearchResult(searchResults);
}