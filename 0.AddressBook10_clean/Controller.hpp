#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Data/AddressBookModel.hpp"
#include "Logic/TableLogic.hpp"
#include "Logic/SignInMenuLogic.hpp"
#include "Logic/SignUpMenuLogic.hpp"
#include "GUI/MainWindow.hpp"

#include <QApplication>

class Controller : public QApplication {
    public:
        explicit Controller(int argc, char *argv[]);

    private slots:
        void onSignIn(QString& username, QString& password);
        void onSignUp(QString& username, QString& password);
        void onSignOut();
        void onTableAddContact(const QString& name, const QString& phone, const QString& email, const QString& tab);
        void onTableSearchClicked();
        void onSearchAccepted(const QString& name, const QString& searchName, const QString& searchOption);

    private:
        void setupConnections();

    private:
        SignInMenuLogic* signInLogic_;
        SignUpMenuLogic* signUpLogic_;
        TableLogic* tableLogic_;
        MainWindow* mainWindow_;
        AddressBookModel* addressBookModel_;
};

#endif // CONTROLLER_HPP