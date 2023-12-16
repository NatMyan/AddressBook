#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
// #include "../GUI/OpenDialog.hpp"
#include "../GUI/SearchDialog.hpp"
// #include "../GUI/SaveDialog.hpp"
#include "../GUI/SearchResultDialog.hpp"
#include "../Data/Database.hpp"

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>

class AddressBookLogic : public QObject {
    Q_OBJECT

    public:
        explicit AddressBookLogic(QObject *parent = nullptr);

    public:
        QSqlDatabase getDB();
        // AddDialog *getAddDialog();
        // void createTable();

    public slots:
        void addContact();
        void editContact(QTableWidgetItem *item);
        void openAddressBook();
        void searchContacts();
        void saveAddressBook();
        void signIn(QString username, QString password);
        void signUp(QString username, QString password);
        // void addContactToDatabase(const QString &name, const QString &phone, const QString &email, const QString &tab);

    signals:
        void contactAdded(const QString &name, const QString &phone, const QString &email, const QString &tab);
        void contactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email, const QString &tab);
        void sigSignInSuccess(QString username);
        void sigSignInFailed();
        void sigSignUpSuccess();
        void sigSignUpFailed(const QString& errorMessage);

    /*private slots:
        void handleAddContactRequest();*/

    private:
        void showSearchResult(const QVector<Contact>& qVec);
        QByteArray hashPassword(const QString &password);
        bool insertUser(const QString &username, const QByteArray &hashedPassword);
        bool checkUsernameExists(const QString &username);
        bool checkCredentials(const QString &username, const QByteArray &hashedPassword);
        // void copyDatabaseContents(Database& sourceDb, Database& destDb, const QString& filePath);
        // void copyDatabaseContents(Database& sourceDb, const QString& destFilePath);

    private:
        Database *db;
        AddDialog *addDialog; 
        SearchDialog *searchDialog;
        // OpenDialog *openDialog;
        // SaveDialog *saveDialog;
};

#endif // ADDRESS_BOOK_LOGIC_HPP

/*
// addressbooklogic.hpp

#ifndef ADDRESSBOOKLOGIC_HPP
#define ADDRESSBOOKLOGIC_HPP

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>

class AddressBookLogic : public QObject {
    Q_OBJECT

public:
    explicit AddressBookLogic(QObject *parent = nullptr);

public:
    QSqlDatabase getDB();

public slots:
    void signIn(QString username, QString password);
    void signUp(QString username, QString password);
    // Add the necessary slots for other functionality

signals:
    void sigSignInSuccess(QString username);
    void sigSignInFailed();
    void sigSignUpSuccess();
    void sigSignUpFailed(const QString& errorMessage);
    // Add the necessary signals for other functionality

private:
    // Add the necessary private methods and members for the logic
};

#endif // ADDRESSBOOKLOGIC_HPP

*/