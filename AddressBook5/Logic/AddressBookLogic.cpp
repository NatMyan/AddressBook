#include "AddressBookLogic.hpp"

#include <QInputDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

AddressBookLogic::AddressBookLogic(QObject *parent) : 
    QObject(parent),
    addDialog(new AddDialog),
    openDialog(new OpenDialog),
    searchDialog(new SearchDialog),
    saveDialog(new SaveDialog),
    db (new Database(""))
{   
    // connect(addDialog, &AddDialog::accepted, this, &AddressBookLogic::handleAddContactRequest);
    // createTable();
}

// void AddressBookLogic::createTable() {
    // db.makeDatabase();
    // db.createTable();
    /* db = QSqlDatabase::addDatabase("QSQLITE");
    QString fileName = "../untitled.db";  

    QFileInfo fileInfo(fileName);
    if (fileInfo.exists()) {
        int i = 1;
        fileName = "../untitled" + QString::number(i) + ".db";  
        while (QFileInfo(fileName).exists()) {
            ++i;
            fileName = "../untitled" + QString::number(i) + ".db";
        }
    }
    db.setDatabaseName(fileName);

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.prepare("CREATE TABLE contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, phone TEXT, email TEXT, tab TEXT)");

    if (query.exec()) {
        qDebug() << "Table created successfully";
    } 
    else {
        qDebug() << "Failed to create table:" << query.lastError().text();
    }*/
// }

QSqlDatabase AddressBookLogic::getDB() {
    return db->getDatabase();
}

/*AddDialog* AddressBookLogic::getAddDialog() {
    return addDialog;
}*/

void AddressBookLogic::addContact() {
    addDialog->updateTabs2();
    int result = addDialog->exec();

    if (result == QDialog::Accepted) {
        QString name = addDialog->name();
        QString phone = addDialog->phone();
        QString email = addDialog->email();
        // addDialog->updateTabNames();
        QString tab = addDialog->selectedTab();

        QSqlQuery query(getDB());
        query.prepare("INSERT INTO contacts (name, phone, email, belonging) VALUES (:name, :phone, :email, :belonging)");
        query.bindValue(":name", name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":belonging", tab);

        //qDebug() << "Test: " << name;          
        // qDebug() << "Last query: " << query.lastQuery();
        if (query.exec()) {
            emit contactAdded(name, phone, email, tab);
            qDebug() << "Contact added to the database";
        } 
        else {
            qDebug() << "Failed to add contact to the database: " << query.lastError().text();
        }
        // QSqlQuery query2(db);
        // qDebug() <<"DB query"<< query2.lastQuery();
    } 
    else {
        qDebug() << "User canceled adding a contact.";
    }
}

void AddressBookLogic::editContact(QTableWidgetItem *item) {
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

    emit contactEdited(tabIndex, rowIndex, name, phone, email, tab);
}

void AddressBookLogic::openAddressBook() {
    qDebug() << "Open button clicked";

    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Address Book", "", "SQLite Database (*.db *.sqlite)");

    db->openDatabase(filePath);
    /*if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(filePath);

        if (db.open()) {
            qDebug() << "Database opened successfully";

            QSqlQuery query;
            if (!query.exec("SELECT * FROM contacts")) {
                if (!query.exec("CREATE TABLE contacts (name TEXT, phone TEXT, email TEXT)")) {
                    qDebug() << "Failed to create 'contacts' table: " << query.lastError().text();
                }
            }
        } 
        else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }*/
}

void AddressBookLogic::showSearchResult(const QVector<Contact>& qVec) {
    SearchResultDialog searchResultDialog(qVec);
    if (searchResultDialog.exec()) {
        qDebug() << "Contact found";
    }
    else {
        qDebug() << "Contact not found";
    }
}

void AddressBookLogic::searchContacts() {
    qDebug() << "Search button clicked";

    SearchDialog searchDialog;
    if (searchDialog.exec()) {
        QString searchName = searchDialog.getSearchName();
        QString searchOption = searchDialog.getSearchOption();

        qDebug() << "Search Criteria: " << searchName << ", Option: " << searchOption;

        QSqlQuery query;
        QString queryString = "SELECT * FROM contacts WHERE " + searchOption + " LIKE '%" + searchName + "%'";
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
                // showSearchResult(name, phone, email, tab);
            }
            showSearchResult(qVec);
        } 
        else {
            qDebug() << "Search failed: " << query.lastError().text();
        }
    }
}

void AddressBookLogic::saveAddressBook() {
    qDebug() << "Save button clicked";

    QString saveFilePath = QFileDialog::getSaveFileName(nullptr, "Save Address Book", "", "SQLite Database (*.db *.sqlite)");

    if (!saveFilePath.isEmpty()) {
        qDebug() << "Save File Path: " << saveFilePath;

        /*QSqlDatabase db22 = QSqlDatabase::addDatabase("QSQLITE", "saveConnection");
        Database db2; // = new Database;
        db2.makeDatabase(saveFilePath);
        db2.createTable();
        db2.setDatabase(db->getDatabase());*/

        // db->setDatabaseName(saveFilePath);
        /*Database db2(saveFilePath);
        db2.addDatabase("QSQLITE", "saveConnection");
        db2.setDatabase(db->getDatabase());
        copyDatabaseContents(*db, saveFilePath);*/
        // db->changeDatabaseName(saveFilePath);
        qDebug() << saveFilePath;
        
        if (db->getDatabase().open()) {
            qDebug() << "Database is open for copy";
        }
        else {
            qDebug() << "Database isn't open for copy";
        } 

        QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "saveConnection");
        db2.setDatabaseName(saveFilePath);
        db2.open();

        QSqlQuery sourceQuery(db->getDatabase()); 
        QSqlQuery destQuery(db2);
        destQuery.exec("CREATE TABLE contacts (name TEXT, phone TEXT, email TEXT, belonging TEXT)");

        sourceQuery.exec("SELECT * FROM contacts");

        while (sourceQuery.next()) {
            QSqlRecord record = sourceQuery.record();

            QString name = record.value("name").toString();
            QString phone = record.value("phone").toString();
            QString email = record.value("email").toString();
            QString tab = record.value("belonging").toString();

            destQuery.prepare("INSERT INTO contacts (name, phone, email, belonging) VALUES (:name, :phone, :email, :belonging)");
            destQuery.bindValue(":name", name);
            destQuery.bindValue(":phone", phone);
            destQuery.bindValue(":email", email);
            destQuery.bindValue(":belonging", tab);

            if (!destQuery.exec()) {
                qDebug() << "Failed to insert record into destination database:" << destQuery.lastError().text();
            }
        }

        /*db->closeDatabase();
        Database* db2 = new Database;
        db2->setDatabase(db->getDatabase().addDatabase("QSQLITE", "saveConnection"));
        db2->setDatabaseName(saveFilePath);*/
        // db->makeDatabase();
        // db->createTable();
        // db->setDatabase(QSqlDatabase::addDatabase("QSQLITE", "saveConnection"));
        // db->setDatabaseName(saveFilePath);
        // db2->readContacts();

        if (db2.open()) {
        // if (db->open()) {
            qDebug() << "Database opened successfully for saving";
        } 
        else {
            // qDebug() << "Failed to open database for saving: " << db->lastError().text();
            qDebug() << "Failed to open database for saving: " << db2.lastError().text();
        }
    }
}

/*void AddressBookLogic::copyDatabaseContents(Database& sourceDb, Database& destDb, const QString& filePath) {
    // Open the source database and read its contents
    sourceDb.readContacts();

    // Open the destination database
    destDb.makeDatabase(filePath);  // This assumes makeDatabase initializes the destination database

    // Copy the contents from the source to the destination
    QSqlQuery sourceQuery(sourceDb.getDatabase()); 
    QSqlQuery destQuery(destDb.getDatabase());

    sourceQuery.exec("SELECT * FROM contacts");

    while (sourceQuery.next()) {
        QSqlRecord record = sourceQuery.record();

        // Assuming contacts table has columns: name, phone, email, tab
        QString name = record.value("name").toString();
        QString phone = record.value("phone").toString();
        QString email = record.value("email").toString();
        QString tab = record.value("tab").toString();

        // Insert the data into the destination database
        destQuery.prepare("INSERT INTO contacts (name, phone, email, tab) VALUES (:name, :phone, :email, :tab)");
        destQuery.bindValue(":name", name);
        destQuery.bindValue(":phone", phone);
        destQuery.bindValue(":email", email);
        destQuery.bindValue(":tab", tab);

        if (!destQuery.exec()) {
            qDebug() << "Failed to insert record into destination database:" << destQuery.lastError().text();
        }
    }

    // Save the destination database
    destDb.getDatabase().commit();
    // destDb.setDatabase(QSqlDatabase::addDatabase("QSQLITE", "saveConnection"));
}*/

/*void AddressBookLogic::copyDatabaseContents(Database& sourceDb, const QString& destFilePath) {
    // Open the source database and read its contents
    sourceDb.readContacts();

    // Attach the destination database
    QSqlQuery attachQuery(sourceDb.getDatabase());
    attachQuery.exec("ATTACH DATABASE '" + destFilePath + "' AS dest_database");

    // Copy the contents from the source to the destination
    QSqlQuery copyQuery(sourceDb.getDatabase());

    copyQuery.exec("INSERT INTO dest_database.contacts SELECT * FROM contacts");

    if (copyQuery.lastError().isValid()) {
        qDebug() << "Failed to copy database contents:" << copyQuery.lastError().text();
    }

    // Detach the destination database
    attachQuery.exec("DETACH DATABASE dest_database");
}*/

/*void AddressBookLogic::handleAddContactRequest() {
    QString name = addDialog->name();
    QString phone = addDialog->phone();
    QString email = addDialog->email();
    QString tab = addDialog->selectedTab();

    emit contactAdded(name, phone, email, tab);
}*/

/*void AddressBookLogic::addContactToDatabase(const QString &name, const QString &phone, const QString &email, const QString &tab) {
    AddDialog aDialog;
    if (aDialog.exec()) {
        QSqlQuery query(db);
        query.prepare("INSERT INTO contacts (name, phone, email, tab) VALUES (:name, :phone, :email, :tab)");
        query.bindValue(":name", name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);
        query.bindValue(":tab", tab);

        //qDebug() << "Test: " << name;          
        // qDebug() << "Last query: " << query.lastQuery();
        if (query.exec()) {
            emit contactAdded(name, phone, email, tab);
            qDebug() << "Contact added to the database";
        } 
        else {
            qDebug() << "Failed to add contact to the database: " << query.lastError().text();
        }
        // QSqlQuery query2(db);
        // qDebug() <<"DB query"<< query2.lastQuery();
    } 
}*/

/*void AddressBookLogic::handleAddContactRequest() {
    QString name = addDialog->name();
    QString phone = addDialog->phone();
    QString email = addDialog->email();

    emit contactAdded(name, phone, email);

    addContactToDatabase(name, phone, email);
}*/

/*if (table) {
    int rowIndex = table->rowCount();
    table->insertRow(rowIndex);
    table->setItem(rowIndex, 0, new QTableWidgetItem(name));
    table->setItem(rowIndex, 1, new QTableWidgetItem(phone));
    table->setItem(rowIndex, 2, new QTableWidgetItem(email));
}*/

// connect(this, &AddressBookInterface::contactAdded, this, &AddressBookInterface::addContact);
// connect(addDialog, &AddDialog::accepted, this, &AddressBookLogic::handleAddContactRequest);

/*void AddressBookLogic::openAddressBook() {
    qDebug() << "Open button clicked";

    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Address Book", "", "SQLite Database (*.db *.sqlite)");

    if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(filePath);

        if (db.open()) {
            qDebug() << "Database opened successfully";
        } 
        else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }
}*/

/*
// AddressBookLogic.cpp
#include "AddressBookLogic.h"

AddressBookLogic::AddressBookLogic(QObject *parent)
    : QObject(parent) {
    addDialog = new AddDialog;  // Create an instance of AddDialog
    connect(this, &AddressBookLogic::requestAddContact, this, &AddressBookLogic::handleAddContactRequest);
    connect(addDialog, &AddDialog::accepted, this, &AddressBookLogic::handleAddContactRequest);
}

void AddressBookLogic::addContact() {
    // Show the AddDialog when the user wants to add a contact
    addDialog->show();
}

void AddressBookLogic::handleAddContactRequest() {
    // Retrieve the information entered by the user from AddDialog
    QString name = addDialog->name();
    QString phone = addDialog->phone();
    QString email = addDialog->email();

    // Emit the contactAdded signal with the retrieved information
    emit contactAdded(name, phone, email);
}
*/

/*void AddressBookLogic::addContact() {
    qDebug() << "Add button clicked";
    addDialog->show();
    // bool ok;
    // QString name = QInputDialog::getText(nullptr, "Add Contact", "Name:", QLineEdit::Normal, QString(), &ok);
    // QString phone = QInputDialog::getText(nullptr, "Add Contact", "Phone:", QLineEdit::Normal, QString(), &ok);
    // QString email = QInputDialog::getText(nullptr, "Add Contact", "Email:", QLineEdit::Normal, QString(), &ok);

    // if (ok) {
    //    emit contactAdded(name, phone, email);
    // }
}

void AddressBookLogic::openAddressBook() {
    // Placeholder for open functionality
    qDebug() << "Open button clicked";

    OpenDialog openDialog;
    if (openDialog.exec()) {
        QString filePath = openDialog.getSelectedFilePath();
        qDebug() << "Selected File: " << filePath;

        // Implement your logic here using the selected file path
    }
}

void AddressBookLogic::searchContacts() {
    // Placeholder for search functionality
    qDebug() << "Search button clicked";

    SearchDialog searchDialog;
    if (searchDialog.exec()) {
        QString searchName = searchDialog.getSearchName();
        QString searchOption = searchDialog.getSearchOption();

        // Implement your search logic here using the provided search criteria
    }
}

void AddressBookLogic::saveAddressBook() {
    // Placeholder for save functionality
    qDebug() << "Save button clicked";

    SaveDialog saveDialog;
    if (saveDialog.exec()) {
        QString saveFilePath = saveDialog.getSelectedFilePath();
        qDebug() << "Save File Path: " << saveFilePath;

        // Implement your save logic here using the selected save file path
    }
}
*/