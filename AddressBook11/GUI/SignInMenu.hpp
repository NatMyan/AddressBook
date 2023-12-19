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
        explicit SignInMenu(QWidget* parent = nullptr);

    signals:
        void sigSignIn(QString& username, QString& password);
        void sigCancelClicked();

    private slots:
        void onSignInButtonClicked();
        void onCancelButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit* usernameEdit_;
        QLineEdit* passwordEdit_;
        QPushButton* signInButton_;
        QPushButton* cancelButton_;
};

#endif // SIGN_IN_MENU_HPP
