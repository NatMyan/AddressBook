#ifndef FIND_COMMAND_HPP
#define FIND_COMMAND_HPP

#include "Command.hpp"

#include <string>

class FindCommand : public Command {
    public:
        std::string findCommand(std::string byWhat, std::string contactToFind);
        void accept(CommandVisitor& visitor) override;
};

// std::string findContactSQL = "SELECT * FROM contacts WHERE name = '" + contactNameToFind + "';";
#endif // FIND_COMMAND_HPP