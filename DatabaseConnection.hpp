#ifndef DATABASE_INITIALIZER_SINGLETON_HPP
#define DATABASE_INITIALIZER_SINGLETON_HPP

#include "DatabaseException.hpp"

#include <sqlite3.h>
#include <string>

class DatabaseConnection { // RAII
    public:
        DatabaseConnection(const std::string& connectionString) {
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

        ~DatabaseConnection() {
            if (db_) {
                sqlite3_close(db_);
            }
        }

    private:
        sqlite3* db_;
};

#endif // DATABASE_INITIALIZER_SINGLETON_HPP