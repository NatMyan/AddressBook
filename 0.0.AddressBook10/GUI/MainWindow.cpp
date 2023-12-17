#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setupUi();
}

MainWindow::MainWindow(QWidget* parent) : 
    QMainWindow(parent)
{
    setupUi();
}

void MainWindow::setupUi() {
    stackedWidget_ = new QStackedWidget(this);
    startMenu_ = new StartMenu(this);
    signInMenu_ = new SignInMenu(this);
    signUpMenu_ = new SignUpMenu(this);
    tableInterface_ = new TableInterface(this);

    stackedWidget_->addWidget(startMenu_);
    stackedWidget_->addWidget(signInMenu_);
    stackedWidget_->addWidget(signUpMenu_);
    stackedWidget_->addWidget(tableInterface_);

    connect(startMenu_, &StartMenu::sigSignInClicked, this, &MainWindow::onSignInClicked);
    connect(startMenu_, &StartMenu::sigSignUpClicked, this, &MainWindow::onSignUpClicked);
    connect(signInMenu_, &SignInMenu::sigCancelClicked, this, &MainWindow::onCancelClicked);
    connect(signUpMenu_, &SignUpMenu::sigCancelClicked, this, &MainWindow::onCancelClicked);
    connect(signInMenu_, &SignInMenu::sigSignIn, this, &MainWindow::onSignInSuccess);
    connect(signUpMenu_, &SignUpMenu::sigSignUp, this, &MainWindow::onSignUpSuccess);
    connect(tableInterface_, &TableInterface::sigSignOutClicked, this, &MainWindow::onSignOutClicked);

    setCentralWidget(stackedWidget_);
    stackedWidget_->setCurrentWidget(startMenu_);
}

void MainWindow::onSignInClicked() {
    stackedWidget_->setCurrentWidget(signInMenu_);
}

void MainWindow::onCancelClicked() {
    stackedWidget_->setCurrentWidget(startMenu_);
}

void MainWindow::onSignUpClicked() {
    stackedWidget_->setCurrentWidget(signUpMenu_);
}

void MainWindow::onSignInSuccess(QString& username, QString& password) {
    // tableInterface_->setUsername(username);
    stackedWidget_->setCurrentWidget(tableInterface_);
    emit sigSignInToAddressBook(username, password);
}

void MainWindow::onSignUpSuccess(QString& username, QString& password) {
    // tableInterface_->setUsername(username);
    stackedWidget_->setCurrentWidget(tableInterface_);
    emit sigSignUpToAddressBook(username, password);
}

void MainWindow::onSignOutClicked() {
    stackedWidget_->setCurrentWidget(startMenu_);
}


/*connect(startMenu_, &StartMenu::sigSignInClicked, this, &MainWindow::onSignInClicked);
connect(startMenu_, &StartMenu::sigSignUpClicked, this, &MainWindow::onSignUpClicked);
connect(signInMenu_, &SignInMenu::sigSignIn, signInMenuLogic_, &SignInMenuLogic::signIn);
connect(signUpMenu_, &SignUpMenu::sigSignUp, signUpMenuLogic_, &SignUpMenuLogic::signUp);
connect(signInMenuLogic_, &SignInMenuLogic::sigSignInSuccess, this, &MainWindow::onSignInSuccess);
connect(signUpMenuLogic_, &SignUpMenuLogic::sigSignUpSuccess, this, &MainWindow::onSignUpSuccess);
connect(this, &MainWindow::sigSignInToAddressBook, addressBookLogic_, &AddressBookLogic::signIn);
connect(this, &MainWindow::sigSignUpToAddressBook, addressBookLogic_, &AddressBookLogic::signUp);
connect(addressBookInterface_, &AddressBookInterface::sigSignOutClicked, this, &MainWindow::onSignOutClicked);*/