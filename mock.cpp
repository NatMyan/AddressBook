/*#include <SQLiteCpp/SQLiteCpp.h>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    std::string getName() const { return name; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }

private:
    std::string name;
    std::string phoneNumber;
    std::string email;
};

class DatabaseInitializer {
public:
    static DatabaseInitializer& getInstance() {
        static DatabaseInitializer instance;
        return instance;
    }

    SQLite::Database& getDatabase() {
        return database;
    }

private:
    DatabaseInitializer() {
        database.open("address_book.db");
        database.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT)");
    }

    SQLite::Database database;
};

class AddressBook {
public:
    AddressBook() : dbInitializer(DatabaseInitializer::getInstance()), database(dbInitializer.getDatabase()) {}

    void addContact(const Contact& contact) {
        SQLite::Statement query(database, "INSERT INTO contacts (name, phone, email) VALUES (:name, :phone, :email)");
        query.bind(":name", contact.getName());
        query.bind(":phone", contact.getPhoneNumber());
        query.bind(":email", contact.getEmail());

        try {
            query.exec();
        } catch (std::exception& e) {
            // Handle insertion errors
        }
    }

    void removeContact(const std::string& name) {
        SQLite::Statement query(database, "DELETE FROM contacts WHERE name = :name");
        query.bind(":name", name);

        try {
            query.exec();
        } catch (std::exception& e) {
            // Handle deletion errors
        }
    }

    std::vector<Contact> getAllContacts() {
        std::vector<Contact> contacts;
        SQLite::Statement query(database, "SELECT name, phone, email FROM contacts");
        while (query.executeStep()) {
            contacts.emplace_back(query.getColumn(0), query.getColumn(1), query.getColumn(2));
        }
        return contacts;
    }

private:
    DatabaseInitializer& dbInitializer;
    SQLite::Database& database;
};

int main() {
    AddressBook addressBook;

    Contact contact1("John Doe", "123-456-7890", "john.doe@example.com");
    Contact contact2("Jane Smith", "987-654-3210", "jane.smith@example.com");

    // Add contacts
    addressBook.addContact(contact1);
    addressBook.addContact(contact2);

    // List all contacts
    std::vector<Contact> allContacts = addressBook.getAllContacts();
    for (const Contact& contact : allContacts) {
        std::cout << "Name: " << contact.getName() << ", Phone: " << contact.getPhoneNumber() << ", Email: " << contact.getEmail() << std::endl;
    }

    // Remove a contact
    addressBook.removeContact("John Doe");

    return 0;
}

#include <SQLiteCpp/SQLiteCpp.h>

class Contact {
public:
    // Contact class definition (same as before)
};

class DatabaseInitializer {
    // DatabaseInitializer class definition (same as before)
};

class AddContact {
public:
    AddContact(SQLite::Database& database) : database(database) {}

    void addContact(const Contact& contact) {
        SQLite::Statement query(database, "INSERT INTO contacts (name, phone, email) VALUES (:name, :phone, :email)");
        query.bind(":name", contact.getName());
        query.bind(":phone", contact.getPhoneNumber());
        query.bind(":email", contact.getEmail());

        try {
            query.exec();
        } catch (std::exception& e) {
            // Handle insertion errors
        }
    }

private:
    SQLite::Database& database;
};

class RemoveContact {
public:
    RemoveContact(SQLite::Database& database) : database(database) {}

    void removeContact(const std::string& name) {
        SQLite::Statement query(database, "DELETE FROM contacts WHERE name = :name");
        query.bind(":name", name);

        try {
            query.exec();
        } catch (std::exception& e) {
            // Handle deletion errors
        }
    }

private:
    SQLite::Database& database;
};

class AddressBook {
public:
    AddressBook() : dbInitializer(DatabaseInitializer::getInstance()), database(dbInitializer.getDatabase()) {}

    std::vector<Contact> getAllContacts() {
        // Implementation for getting all contacts (same as before)
    }

private:
    DatabaseInitializer& dbInitializer;
    SQLite::Database& database;
};

int main() {
    AddressBook addressBook;

    Contact contact1("John Doe", "123-456-7890", "john.doe@example.com");
    Contact contact2("Jane Smith", "987-654-3210", "jane.smith@example.com");

    // Add contacts
    AddContact addContact(addressBook.database);
    addContact.addContact(contact1);
    addContact.addContact(contact2);

    // List all contacts (same as before)

    // Remove a contact
    RemoveContact removeContact(addressBook.database);
    removeContact.removeContact("John Doe");

    return 0;
}
*/