#ifndef SIGN_UP_MENU_HPP
#define SIGN_UP_MENU_HPP

#include "../Data/User.hpp"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class SignUpMenu : public QWidget {
    Q_OBJECT

    public:
        explicit SignUpMenu(QWidget* parent = nullptr);

    public:
        void setTableName(const QString& name);
        QString getTableName();

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
        QString tableName_;
        User user_;
};

#endif // SIGN_UP_MENU_HPP

