#ifndef ADD_TO_DATABASE_COMMAND_HPP
#define ADD_TO_DATABASE_COMMAND_HPP

#include "../Contact.hpp"
#include "DatabaseCommand.hpp"

class AddToDatabaseCommand : public DatabaseCommand {
    public:
        void execute();
        void initAdd(Contact contact);
};

#endif // ADD_TO_DATABASE_COMMAND_HPP