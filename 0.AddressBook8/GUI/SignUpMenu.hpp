#ifndef SIGN_UP_MENU_HPP
#define SIGN_UP_MENU_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class SignUpMenu : public QWidget {
    Q_OBJECT

    public:
        explicit SignUpMenu(QWidget *parent = nullptr);

    signals:
        void sigSignUp(QString& username, QString& password);
        void sigCancelClicked();

    private slots:
        void onSignUpButtonClicked();
        void onCancelButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit *usernameEdit;
        QLineEdit *passwordEdit;
        QLineEdit *confirmPasswordEdit;
        QPushButton *signUpButton;
        QPushButton *cancelButton;
};

#endif // SIGN_UP_MENU_HPP

