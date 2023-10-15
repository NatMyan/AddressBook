#include "DatabaseInitializerSingleton.hpp"
#include "DatabaseException.hpp"

DatabaseInitializerSingleton& DatabaseInitializerSingleton::getInstance() {
    static DatabaseInitializerSingleton instance;
    return instance;
}

sqlite3* DatabaseInitializerSingleton::getDatabase() {
    return db_;
}

DatabaseInitializerSingleton::DatabaseInitializerSingleton() : db_(nullptr) {
    int result = sqlite3_open("address_book.db", &db_);
    if (result != SQLITE_OK) {
        throw DatabaseException("Error opening database: " + std::string(sqlite3_errmsg(db_)));
    }
    else {
        const char* createTableSQL = "CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT);";
        result = sqlite3_exec(db_, createTableSQL, nullptr, nullptr, nullptr);
        if (result != SQLITE_OK) {
            throw DatabaseException("Error creating table: " + std::string(sqlite3_errmsg(db_)));
        }
    }
}

DatabaseInitializerSingleton::~DatabaseInitializerSingleton() {
    if (db_) {
        sqlite3_close(db_);
    }
}
    
