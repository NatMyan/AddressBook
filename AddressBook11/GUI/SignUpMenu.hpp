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
        explicit SignUpMenu(QWidget* parent = nullptr);

    signals:
        void sigSignUp(QString& username, QString& password);
        void sigCancelClicked();

    private slots:
        void onSignUpButtonClicked();
        void onCancelButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit* usernameEdit_;
        QLineEdit* passwordEdit_;
        QLineEdit* confirmPasswordEdit_;
        QPushButton* signUpButton_;
        QPushButton* cancelButton_;
};

#endif // SIGN_UP_MENU_HPP

