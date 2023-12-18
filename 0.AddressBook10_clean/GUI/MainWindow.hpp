#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "StartMenu.hpp"
#include "SignInMenu.hpp"
#include "SignUpMenu.hpp"
#include "TableInterface.hpp"
// #include "../Controller.hpp"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget* parent = nullptr);
    
    public:
        TableInterface* getTableInterface();

    public slots:
        void onSignInClicked();
        void onSignUpClicked();
        void onSignInSuccess(QString& username, QString& password);
        void onSignUpSuccess(QString& username, QString& password);
        void onCancelClicked();
        void onSignOutClicked();
    
    signals:
        void sigSignInToAddressBook(QString& username, QString& password);
        void sigSignUpToAddressBook(QString& username, QString& password);

    private:
        void setupUi();

    private:
        QStackedWidget* stackedWidget_;
        StartMenu* startMenu_;
        SignInMenu* signInMenu_;
        SignUpMenu* signUpMenu_;
        TableInterface* tableInterface_;
};

#endif // MAIN_WINDOW_HPP



/*
// MainWindow.hpp
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "Controller.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(Controller* controller, QWidget* parent = nullptr);

private slots:
    void onSignInClicked();
    void onCancelClicked();
    void onSignUpClicked();
    void onSignInSuccess(QString& username, QString& password);
    void onSignUpSuccess(QString& username, QString& password);
    void onSignOutClicked();

signals:
    void sigSignInToAddressBook(QString& username, QString& password);
    void sigSignUpToAddressBook(QString& username, QString& password);

private:
    Controller* controller;
    QStackedWidget* stackedWidget;
    StartMenu* startMenu;
    SignInMenu* signInMenu;
    SignUpMenu* signUpMenu;
    AddressBookInterface* addressBookInterface;
};

#endif // MAINWINDOW_HPP
*/