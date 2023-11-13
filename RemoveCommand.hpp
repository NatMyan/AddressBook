#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "Command.hpp"

#include <string>

class RemoveCommand : public Command {
    public:
        std::string removeCommand (std::string contactName);
        void accept(CommandVisitor& visitor) override; 
};

#endif // REMOVE_COMMAND_HPP