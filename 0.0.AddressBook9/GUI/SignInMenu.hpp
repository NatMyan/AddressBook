#ifndef SIGN_IN_MENU_HPP
#define SIGN_IN_MENU_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class SignInMenu : public QWidget {
    Q_OBJECT

    public:
        explicit SignInMenu(QWidget *parent = nullptr);

    signals:
        void sigSignIn(QString& username, QString& password);
        void sigCancelClicked();

    private slots:
        void onSignInButtonClicked();
        void onCancelButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit *usernameEdit;
        QLineEdit *passwordEdit;
        QPushButton *signInButton;
        QPushButton *cancelButton;
};

#endif // SIGN_IN_MENU_HPP
