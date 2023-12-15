#include "AddressBookLogic.hpp"

AddressBookLogic::AddressBookLogic(Database& database) : database_(database) 
{
    // Additional initialization if needed
}

void AddressBookLogic::addContact(const QString& name, const QString& phone, const QString& email, const QString& belonging) {
    // Logic for adding a contact
    Contact newContact{ name, phone, email, belonging };
    QList<Contact> contacts = database_.readContacts();
    contacts.append(newContact);
    database_.writeContacts(contacts);
    emit updateTable(); // Notify the UI to update the table
}

void AddressBookLogic::searchContacts(const QString& searchOption, const QString& searchName) {
    QList<Contact> searchResults;

    QList<Contact> contacts = database_.readContacts();
    for (const Contact& contact : contacts) {
        if (searchOption == "name")
            if (contact.name.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
        else if (searchOption == "phone")
            if (contact.phone.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
        else if (searchOption == "email")
            if (contact.email.contains(searchName, Qt::CaseInsensitive)) {
                searchResults.append(contact);
            }
    }

    emit updateTable(); // Notify the UI to update the table
}

void AddressBookLogic::filterContactsByTab(const QString& tabName) {
    // Logic for filtering contacts based on the selected tab
    QList<Contact> contacts = database_.readContacts();
    QList<Contact> filteredContacts;

    // Apply filtering based on the tabName
    if (!tabName.isEmpty() && tabName != "All") {
        for (auto contact : contacts) {
            if (contact.belonging == tabName) {
                filteredContacts.append(contact);
            }
        }
    }

    // Notify the UI to update the table
    emit updateTable();
}
