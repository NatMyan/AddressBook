#ifndef DATABASE_COMMAND_HPP
#define DATABASE_COMMAND_HPP

#include "../DatabaseConnection.hpp"

class DatabaseCommand {
    public:
        virtual ~DatabaseCommand() = default;
        virtual void execute() = 0;

    //private:
        // DatabaseInitializerWrapper& dbWrapper;
};

#endif // DATABASE_COMMAND_HPP