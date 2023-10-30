#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "CommandVisitor.hpp"

class Command {
    public:
        virtual void accept(CommandVisitor& visitor) = 0;
};

#endif // COMMAND_HPP