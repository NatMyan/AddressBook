#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>

#include "StartMenu.hpp"
#include "SignInMenu.hpp"
#include "SignUpMenu.hpp"
#include "TableInterface.hpp"
#include "../Logic/SignInMenuLogic.hpp"
#include "../Logic/SignUpMenuLogic.hpp"
#include "../Logic/TableLogic.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget* parent = nullptr);

    private slots:
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
        SignInMenuLogic* signInMenuLogic_;
        SignUpMenuLogic* signUpMenuLogic_;
        TableLogic* tableLogic_;
};

#endif // MAIN_WINDOW_HPP


