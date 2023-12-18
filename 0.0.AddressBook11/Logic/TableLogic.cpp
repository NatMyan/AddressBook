#include "TableLogic.hpp"
#include "../Data/User.hpp"

#include <QInputDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>

TableLogic::TableLogic(QObject *parent) : 
    QObject(parent),
    addDialog_(new AddDialog),
    searchDialog_(new SearchDialog),
    db_(new DatabaseManager("../zinfo/users.db"))
{}

QSqlDatabase TableLogic::getDB() {
    return db_->getDatabase();
}

void TableLogic::addContact() {
    addDialog_->updateTabs2();
    int result = addDialog_->exec();

    if (result == QDialog::Accepted) {
        QString name = addDialog_->name();
        QString phone = addDialog_->phone();
        QString email = addDialog_->email();
        QString tab = addDialog_->selectedTab();

        db_->openDatabase("../zinfo/users.db", User::getName(), "(name TEXT, phone TEXT, email TEXT, belonging TEXT)");

        QSqlQuery query(*db_);
        query.prepare("INSERT INTO " + User::getName() + " (name, phone, email, belonging) VALUES (:name, :phone, :email, :belonging)");
        qDebug() << "user get name: " << User::getName();
        query.bindValue(":name", name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":belonging", tab);

        if (query.exec()) {
            emit sigContactAdded(name, phone, email, tab);
            qDebug() << "Contact added to the database";
        } 
        else {
            qDebug() << "Failed to add contact to the database: " << query.lastError().text();
        }
    } 
    else {
        qDebug() << "User canceled adding a contact.";
    }
}

void TableLogic::editContact(QTableWidgetItem* item) {
    int tabIndex = item->tableWidget()->property("TabIndex").toInt();
    int rowIndex = item->row();

    QString name = item->tableWidget()->item(rowIndex, 0)->text();
    QString phone = item->tableWidget()->item(rowIndex, 1)->text();
    QString email = item->tableWidget()->item(rowIndex, 2)->text();
    QString tab = item->tableWidget()->item(rowIndex, 3)->text();

    bool ok;
    name = QInputDialog::getText(nullptr, "Edit Contact", "Name:", QLineEdit::Normal, name, &ok);
    if (!ok) return;

    phone = QInputDialog::getText(nullptr, "Edit Contact", "Phone:", QLineEdit::Normal, phone, &ok);
    if (!ok) return;

    email = QInputDialog::getText(nullptr, "Edit Contact", "Email:", QLineEdit::Normal, email, &ok);
    if (!ok) return;

    tab = QInputDialog::getText(nullptr, "Edit Contact", "Tab:", QLineEdit::Normal, tab, &ok);
    if (!ok) return;

    emit sigContactEdited(tabIndex, rowIndex, name, phone, email, tab);
}

void TableLogic::showSearchResult(const QVector<Contact>& qVec) {
    SearchResultDialog searchResultDialog(qVec);
    if (searchResultDialog.exec()) {
        qDebug() << "Contact found";
    }
    else {
        qDebug() << "Contact not found";
    }
}

void TableLogic::searchContacts() {
    qDebug() << "Search button clicked";

    SearchDialog searchDialog;
    if (searchDialog.exec()) {
        QString searchName = searchDialog.getSearchName();
        QString searchOption = searchDialog.getSearchOption();

        qDebug() << "Search Criteria: " << searchName << ", Option: " << searchOption;

        QSqlQuery query;
        QString queryString = "SELECT * FROM " + User::getName() + " WHERE " + searchOption + " LIKE '%" + searchName + "%'";
        if (query.exec(queryString)) {
            QVector<Contact> qVec;
            while (query.next()) {
                QString name = query.value("name").toString();
                QString phone = query.value("phone").toString();
                QString email = query.value("email").toString();
                QString tab = query.value("belonging").toString();
                qDebug() << "Result: Name = " << name << ", Phone = " << phone << ", Email = " << email << ", Tab = " << tab;
                Contact contact = {name, phone, email, tab};
                qVec.append(contact);
            }
            showSearchResult(qVec);
        } 
        else {
            qDebug() << "Search failed: " << query.lastError().text();
        }
    }
}

void TableLogic::signIn(QString &username, QString& password) {
    QByteArray hashedPassword = hashPassword(password);

    if (checkCredentials(username, hashedPassword)) {
        DatabaseManager *newDB = new DatabaseManager("../zinfo/users.db");

        std::swap(db_, newDB);

        db_->openDatabase("../zinfo/users.db", User::getName(), "(name TEXT, phone TEXT, email TEXT, belonging TEXT)");
        emit sigSignInSuccess(username);
    } 
    else {
        emit sigSignInFailed();
    }
}

void TableLogic::signUp(QString& username, QString& password) {
    QByteArray hashedPassword = hashPassword(password);

    if (checkUsernameExists(username)) {
        emit sigSignUpFailed("Username already exists. Choose a different username.");
        return;
    }

    if (insertUser(username, hashedPassword)) {
        db_->openDatabase("../zinfo/users.db", User::getName(), "(name TEXT, phone TEXT, email TEXT, belonging TEXT)");
        emit sigSignUpSuccess(username);
    } 
    else {
        emit sigSignUpFailed("Sign-up failed. Please try again.");
    }
}

bool TableLogic::checkCredentials(const QString &username, const QByteArray &hashedPassword) {
    QSqlQuery query(*db_);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(hashedPassword);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool TableLogic::checkUsernameExists(const QString& username) {
    QSqlQuery query(*db_);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

QByteArray TableLogic::hashPassword(const QString& password) {
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}

bool TableLogic::insertUser(const QString& username, const QByteArray& hashedPassword) {
    QSqlQuery query(*db_);
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(QString::fromUtf8(hashedPassword));

    return query.exec();
}

