#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>

using ResultPair = std::pair<std::vector<std::vector<std::string> >, bool>;

class Database {
    public:
        virtual ~Database() = default; // is this a problem -> to have virtual dtor as default ?
        virtual bool connect(const std::string& connectionString) = 0;
        virtual ResultPair executeQuery(const std::string& query) = 0;
        virtual void close() = 0;
};

#endif // DATABASE_HPP