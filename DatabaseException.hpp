#ifndef DATABASE_EXCEPTION_HPP
#define DATABASE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class DatabaseException : public std::runtime_error {
    public:
        DatabaseException(const std::string& message) : std::runtime_error(message) {}
};

#endif // DATABASE_EXCEPTION_HPP
