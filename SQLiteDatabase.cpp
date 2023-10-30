#include "SQLiteDatabase.hpp"
#include "DatabaseException.hpp"

SQLiteDatabase::~SQLiteDatabase() {
    close();
}

bool SQLiteDatabase::connect(const std::string& connectionString) {
    close();
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

ResultPair SQLiteDatabase::executeQuery(const std::string& query) {
    if (!db_) {
        return { {}, false }; 
    }

    char* errorMessage = nullptr;
    std::vector<std::vector<std::string>> result;

    int resultStatus = sqlite3_exec(db_, query.c_str(), callback, &result, &errorMessage);
    if (resultStatus != SQLITE_OK) {
        sqlite3_free(errorMessage);
        return { {}, false };
    }

    return { result, true };
}

void SQLiteDatabase::close() {
    if (db_) {
        sqlite3_close(db_);
    }
}

int SQLiteDatabase::callback(void* data, int argc, char** argv, char** columnNames) {
    auto result = static_cast<std::vector<std::vector<std::string>>*>(data);
    result->emplace_back(argv, argv + argc);
    return 0;
}

