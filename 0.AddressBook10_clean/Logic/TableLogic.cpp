#include "TableLogic.hpp"
#include "../GUI/SearchResultDialog.hpp"
#include "../Data/User.hpp"

TableLogic::TableLogic(TableInterface* tableInterface, AddressBookModel* addressBookModel, QObject* parent) : 
    QObject(parent), 
    tableInterface_(tableInterface), 
    addressBookModel_(addressBookModel),
    addDialog_(new AddDialog()), 
    searchDialog_(new SearchDialog()) 
{
    dbManager_ = new DatabaseManager(user_.getName());
    connect(tableInterface_, &TableInterface::sigAddContactClicked, this, &TableLogic::onAddContactClicked2);
    connect(tableInterface_, &TableInterface::sigSearchClicked, this, &TableLogic::onSearchClicked);
    connect(tableInterface_, &TableInterface::sigSignOutClicked, this, &TableLogic::onSignOutClicked);
    connect(addDialog_, &AddDialog::contactAdded, this, &TableLogic::onAddAccepted);
    connect(searchDialog_, &SearchDialog::sigAccepted, this, &TableLogic::onSearchAccepted); // sigAccepted -> no args ?
}

void TableLogic::onAddContactClicked2() {
    int res = addDialog_->exec();
    if (res == QDialog::Accepted) {
        QString name = addDialog_->name();
        QString phone = addDialog_->phone();
        QString email = addDialog_->email();
        QString tab = addDialog_->selectedTab();

        QSqlQuery query(dbManager_->getDatabase());
        QString tableName = determineTableName();
        query.prepare("INSERT INTO " + tableName + " (name, phone, email, belonging) VALUES (:name, :phone, :email, :belonging)");
        query.bindValue(":name", name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":belonging", tab);

        if (query.exec()) {
            onAddAccepted(name, phone, email, tab);
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

void TableLogic::onSearchClicked() {
    int res = searchDialog_->exec();
    if (res == QDialog::Accepted) {
        QString searchName = searchDialog_->getSearchName();
        QString searchOption = searchDialog_->getSearchOption();
        QString tableName = determineTableName();

        qDebug() << "Search Criteria: " << searchName << ", Option: " << searchOption;

        QSqlQuery query;
        QString queryString = "SELECT * FROM " + tableName + " WHERE " + searchOption + " LIKE '%" + searchName + "%'";
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

void TableLogic::showSearchResult(const QVector<Contact>& qVec) {
    SearchResultDialog searchResultDialog(qVec);
    if (searchResultDialog.exec()) {
        qDebug() << "Contact(s) found";
    }
    else {
        qDebug() << "Contact(s) not found";
    }
}

void TableLogic::onAddAccepted(const QString& name, const QString& phone, const QString& email, const QString& tab) {
    emit sigContactAdded(name, phone, email, tab);
}

void TableLogic::onSearchAccepted(const QString &name, const QString &searchName, const QString &searchOption) {
    addressBookModel_->retrieveContacts(name, searchName, searchOption);
    emit sigSearchClicked();  
}

QString TableLogic::determineTableName() {
    return user_.getName();
}

void TableLogic::onSignOutClicked() {
    emit sigSignOutClicked();
}