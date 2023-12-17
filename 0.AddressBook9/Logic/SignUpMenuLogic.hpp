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
        int getUserID();
        void setUserID(int id);
        
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
        int insertUser(const QString& username, const QByteArray& hashedPassword);
    
    private:
        QSqlDatabase db;
        int currID;
};

#endif // SIGN_UP_MENU_LOGIC_HPP


/*class SignUpMenuLogic : public QObject {
    Q_OBJECT

public:
    explicit SignUpMenuLogic(QObject* parent = nullptr);

public slots:
    void signUp(const QString& username, const QString& password);

signals:
    void signUpSuccess();
    void signUpError(const QString& errorMessage);
};

#endif // SIGN_UP_MENU_LOGIC_HPP*/

/*class SignUpMenuLogic {
    public:
        bool signUp(const QString& username, const QString& password);
};

bool SignUpMenuLogic::signUp(const QString& username, const QString& password) {
    // Open the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    // Check if the users table exists; create it if not
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)")) {
        qDebug() << "Failed to create the users table:" << createTableQuery.lastError().text();
        return false;
    }

    // Check if the username already exists
    QSqlQuery checkUsernameQuery;
    checkUsernameQuery.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    checkUsernameQuery.addBindValue(username);
    if (!checkUsernameQuery.exec()) {
        qDebug() << "Error checking username existence:" << checkUsernameQuery.lastError().text();
        return false;
    }

    checkUsernameQuery.next();
    int usernameCount = checkUsernameQuery.value(0).toInt();

    if (usernameCount > 0) {
        qDebug() << "Username already exists. Choose a different username.";
        return false;
    }

    // Hash the password before storing it
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Insert the new user into the users table
    QSqlQuery insertUserQuery;
    insertUserQuery.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    insertUserQuery.addBindValue(username);
    insertUserQuery.addBindValue(QString::fromUtf8(hashedPassword));

    if (!insertUserQuery.exec()) {
        qDebug() << "Failed to insert user:" << insertUserQuery.lastError().text();
        return false;
    }

    qDebug() << "User signed up successfully.";
    return true;
}*/