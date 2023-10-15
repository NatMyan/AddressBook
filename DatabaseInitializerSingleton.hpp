#ifndef DATABASE_INITIALIZER_SINGLETON_HPP
#define DATABASE_INITIALIZER_SINGLETON_HPP

#include <sqlite3.h>

class DatabaseInitializerSingleton {
    public:
        static DatabaseInitializerSingleton& getInstance();
        sqlite3* getDatabase();

    public:    
        DatabaseInitializerSingleton(const DatabaseInitializerSingleton&) = delete;
        DatabaseInitializerSingleton& operator=(const DatabaseInitializerSingleton&) = delete;
        
    private:
        DatabaseInitializerSingleton();
        ~DatabaseInitializerSingleton();
    
    private:
        sqlite3* db_;
};


#endif // DATABASE_INITIALIZER_SINGLETON_HPP