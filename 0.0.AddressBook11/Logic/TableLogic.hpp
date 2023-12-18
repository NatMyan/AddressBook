#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
#include "../GUI/SearchDialog.hpp"
#include "../GUI/SearchResultDialog.hpp"
#include "../Data/DatabaseManager.hpp"

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>

class TableLogic : public QObject {
    Q_OBJECT

    public:
        explicit TableLogic(QObject* parent = nullptr);

    public:
        QSqlDatabase getDB();
    public slots:
        void addContact();
        void editContact(QTableWidgetItem* item);
        void searchContacts();
        void signIn(QString& username, QString& password);
        void signUp(QString& username, QString& password);

    signals:
        void sigContactAdded(const QString& name, const QString& phone, const QString& email, const QString& tab);
        void sigContactEdited(int tabIndex, int rowIndex, const QString& name, const QString& phone, const QString& email, const QString& tab);
        void sigSignInSuccess(QString& username);
        void sigSignInFailed();
        void sigSignUpSuccess(QString& username);
        void sigSignUpFailed(const QString& errorMessage);

    private:
        void showSearchResult(const QVector<Contact>& qVec);
        QByteArray hashPassword(const QString& password);
        bool insertUser(const QString& username, const QByteArray& hashedPassword);
        bool checkUsernameExists(const QString& username);
        bool checkCredentials(const QString& username, const QByteArray& hashedPassword);

    private:
        DatabaseManager* db_;
        AddDialog* addDialog_; 
        SearchDialog* searchDialog_;
};

#endif // ADDRESS_BOOK_LOGIC_HPP


