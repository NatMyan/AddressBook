#include "AddressBookLogic.hpp"

#include <QInputDialog>

AddressBookLogic::AddressBookLogic(QObject *parent) : 
    QObject(parent),
    addDialog(new AddDialog)
{
    connect(this, &AddressBookLogic::contactAdded, this, &AddressBookLogic::handleAddContactRequest);
    connect(addDialog, &AddDialog::accepted, this, &AddressBookLogic::handleAddContactRequest);
}

void AddressBookLogic::addContact() {
    addDialog->show();
}

void AddressBookLogic::editContact(QTableWidgetItem *item) {
    int tabIndex = item->tableWidget()->property("TabIndex").toInt();
    int rowIndex = item->row();

    QString name = item->tableWidget()->item(rowIndex, 0)->text();
    QString phone = item->tableWidget()->item(rowIndex, 1)->text();
    QString email = item->tableWidget()->item(rowIndex, 2)->text();

    bool ok;
    name = QInputDialog::getText(nullptr, "Edit Contact", "Name:", QLineEdit::Normal, name, &ok);
    if (!ok) return;

    phone = QInputDialog::getText(nullptr, "Edit Contact", "Phone:", QLineEdit::Normal, phone, &ok);
    if (!ok) return;

    email = QInputDialog::getText(nullptr, "Edit Contact", "Email:", QLineEdit::Normal, email, &ok);
    if (!ok) return;

    emit contactEdited(tabIndex, rowIndex, name, phone, email);
}

void AddressBookLogic::handleAddContactRequest() {
    QString name = addDialog->name();
    QString phone = addDialog->phone();
    QString email = addDialog->email();

    emit contactAdded(name, phone, email);
}

#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>

void AddressBookLogic::openAddressBook() {
    qDebug() << "Open button clicked";

    // Open file dialog to get the selected file path
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Address Book", "", "SQLite Database (*.db *.sqlite)");

    if (!filePath.isEmpty()) {
        qDebug() << "Selected File: " << filePath;

        // Implement your logic here using the selected file path
        // For simplicity, we'll assume it's an SQLite database and open a connection
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(filePath);

        if (db.open()) {
            qDebug() << "Database opened successfully";
            // Load data from the database if needed
        } else {
            qDebug() << "Failed to open database: " << db.lastError().text();
        }
    }
}

void AddressBookLogic::searchContacts() {
    qDebug() << "Search button clicked";

    SearchDialog searchDialog;
    if (searchDialog.exec()) {
        QString searchName = searchDialog.getSearchName();
        QString searchOption = searchDialog.getSearchOption();

        qDebug() << "Search Criteria - Name: " << searchName << ", Option: " << searchOption;

        // Implement your search logic here using the provided search criteria
        // For simplicity, we'll assume it's an SQLite database and perform a query
        QSqlQuery query;
        QString queryString = "SELECT * FROM contacts WHERE " + searchOption + " LIKE '%" + searchName + "%'";
        if (query.exec(queryString)) {
            while (query.next()) {
                QString name = query.value("name").toString();
                QString phone = query.value("phone").toString();
                QString email = query.value("email").toString();
                qDebug() << "Result: Name=" << name << ", Phone=" << phone << ", Email=" << email;
                // Handle the search result as needed
            }
        } else {
            qDebug() << "Search failed: " << query.lastError().text();
        }
    }
}

void AddressBookLogic::saveAddressBook() {
    qDebug() << "Save button clicked";

    // Open file dialog to get the save file path
    QString saveFilePath = QFileDialog::getSaveFileName(nullptr, "Save Address Book", "", "SQLite Database (*.db *.sqlite)");

    if (!saveFilePath.isEmpty()) {
        qDebug() << "Save File Path: " << saveFilePath;

        // Implement your save logic here using the selected save file path
        // For simplicity, we'll assume it's an SQLite database and save data
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "saveConnection");
        db.setDatabaseName(saveFilePath);

        if (db.open()) {
            qDebug() << "Database opened successfully for saving";
            // Save data to the database if needed
        } 
        else {
            qDebug() << "Failed to open database for saving: " << db.lastError().text();
        }
    }
}


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