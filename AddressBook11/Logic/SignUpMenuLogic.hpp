#ifndef SIGN_UP_MENU_LOGIC_HPP
#define SIGN_UP_MENU_LOGIC_HPP

#include <QObject>
#include <QString>
#include <QSqlDatabase>

class SignUpMenuLogic : public QObject {
    Q_OBJECT

    public:
        explicit SignUpMenuLogic(QObject* parent = nullptr);
        QSqlDatabase getUserDB();

    public slots:
        bool signUp(QString& username, QString& password);

    signals:
        void sigSignUpSuccess(QString &username, QString &password);
        void signUpError(const QString& errorMessage);

    private:
        bool openDatabase();
        bool createUsersTable();
        bool checkUsernameExists(const QString& username);
        QByteArray hashPassword(const QString& password);
        bool insertUser(const QString& username, const QByteArray& hashedPassword);
    
    private:
        QSqlDatabase db_;
};

#endif // SIGN_UP_MENU_LOGIC_HPP

