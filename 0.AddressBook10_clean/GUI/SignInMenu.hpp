#ifndef SIGN_IN_MENU_HPP
#define SIGN_IN_MENU_HPP

#include "../Data/User.hpp"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class SignInMenu : public QWidget {
    Q_OBJECT

    public:
        explicit SignInMenu(QWidget* parent = nullptr);

    public:
        void setTableName(const QString& name);
        QString getTableName();

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
        QString tableName_;
        User user_;
};

#endif // SIGN_IN_MENU_HPP
