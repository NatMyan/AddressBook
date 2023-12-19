#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* parent) : 
    QMainWindow(parent) 
{
    setupUi();
    connect(startMenu_, &StartMenu::sigSignInClicked, this, &MainWindow::onSignInClicked);
    connect(startMenu_, &StartMenu::sigSignUpClicked, this, &MainWindow::onSignUpClicked);
    connect(signInMenu_, &SignInMenu::sigSignIn, signInMenuLogic_, &SignInMenuLogic::signIn);
    connect(signUpMenu_, &SignUpMenu::sigSignUp, signUpMenuLogic_, &SignUpMenuLogic::signUp);
    connect(signInMenuLogic_, &SignInMenuLogic::sigSignInSuccess, this, &MainWindow::onSignInSuccess);
    connect(signUpMenuLogic_, &SignUpMenuLogic::sigSignUpSuccess, this, &MainWindow::onSignUpSuccess);
    connect(this, &MainWindow::sigSignInToAddressBook, tableLogic_, &TableLogic::signIn);
    connect(this, &MainWindow::sigSignUpToAddressBook, tableLogic_, &TableLogic::signUp);
    connect(tableInterface_, &TableInterface::sigSignOutClicked, this, &MainWindow::onSignOutClicked);
}

void MainWindow::setupUi() {
    stackedWidget_ = new QStackedWidget(this);
    startMenu_ = new StartMenu(this);
    signInMenu_ = new SignInMenu(this);
    signUpMenu_ = new SignUpMenu(this);
    signInMenuLogic_ = new SignInMenuLogic(this);
    signUpMenuLogic_ = new SignUpMenuLogic(this);
    tableLogic_ = new TableLogic(this);
    tableInterface_ = new TableInterface(tableLogic_, this);

    stackedWidget_->addWidget(startMenu_);
    stackedWidget_->addWidget(signInMenu_);
    stackedWidget_->addWidget(signUpMenu_);
    stackedWidget_->addWidget(tableInterface_);

    setCentralWidget(stackedWidget_);
    stackedWidget_->setCurrentWidget(startMenu_);
}

void MainWindow::onSignInClicked() {
    stackedWidget_->setCurrentWidget(signInMenu_);
    connect(signInMenu_, &SignInMenu::sigCancelClicked, this, &MainWindow::onCancelClicked);
}

void MainWindow::onCancelClicked() {
    stackedWidget_->setCurrentWidget(startMenu_);
}

void MainWindow::onSignUpClicked() {
    stackedWidget_->setCurrentWidget(signUpMenu_);
    connect(signUpMenu_, &SignUpMenu::sigCancelClicked, this, &MainWindow::onCancelClicked);
}

void MainWindow::onSignInSuccess(QString& username, QString& password) {
    stackedWidget_->setCurrentWidget(tableInterface_);
    tableInterface_->onShowDatabaseContents();
    emit sigSignInToAddressBook(username, password);
}

void MainWindow::onSignUpSuccess(QString& username, QString& password) {
    stackedWidget_->setCurrentWidget(tableInterface_);
    emit sigSignUpToAddressBook(username, password);
}

void MainWindow::onSignOutClicked() {
    stackedWidget_->setCurrentWidget(startMenu_);
}


