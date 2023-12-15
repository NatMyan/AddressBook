#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "StartMenu.hpp"
#include "SignInMenu.hpp"
#include "SignUpMenu.hpp"
#include "AddressBookInterface.hpp"
#include "../Logic/AddressBookLogic.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private slots:
        void onSignInClicked();
        void onSignUpClicked();
        void onSignInSuccess(QString username);

    private:
        void setupUi();

    private:
        QStackedWidget *stackedWidget_;
        StartMenu *startMenu_;
        SignInMenu *signInMenu_;
        SignUpMenu *signUpMenu_;
        AddressBookInterface *addressBookInterface_;
        AddressBookLogic *addressBookLogic_;
};

#endif // MAINWINDOW_HPP


/*#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "startmenu.hpp"
#include "signinmenu.hpp"
#include "signupmenu.hpp"
#include "addressbookinterface.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onSignInClicked();
    void onSignUpClicked();
    void onSignInSuccess(QString username);

private:
    void setupUi();

private:
    QStackedWidget *stackedWidget_;
    StartMenu *startMenu_;
    SignInMenu *signInMenu_;
    SignUpMenu *signUpMenu_;
    AddressBookInterface *addressBookInterface_;
};

#endif // MAINWINDOW_HPP*/


/*#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "StartMenu.hpp"
#include "AddressBookInterface.hpp"
#include "../Logic/AddressBookLogic.hpp"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private slots:
        void onAddClicked();
        void onOpenClicked();
        void onContactAdded();
        void onContactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email, const QString &tab);
        void showDatabaseContents();

    private:
        void setupUi();

    private:
        QStackedWidget *stackedWidget;
        StartMenu *startMenu;
        AddressBookInterface *addressBookInterface;
        AddressBookLogic *addressBookLogic;
};

#endif // MAIN_WINDOW_HPP
*/
