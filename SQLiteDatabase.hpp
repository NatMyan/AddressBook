#ifndef SQLITE_DATABASE_HPP
#define SQLITE_DATABASE_HPP

#include "Database.hpp"

#include <sqlite3.h>

class SQLiteDatabase : public Database {
    public:
        SQLiteDatabase() : db_(nullptr) {}
        ~SQLiteDatabase();

    public:
        bool connect(const std::string& connectionString) override;
        ResultPair executeQuery(const std::string& query) override;
        void close() override;

    private:
        static int callback(void* data, int argc, char** argv, char** columnNames);
    
    private:
        sqlite3* db_;
};

#endif // SQLITE_DATABASE_HPP