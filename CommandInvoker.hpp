#ifndef COMMAND_INVOKER_HPP
#define COMMAND_INVOKER_HPP

#include "Commands/CommandVisitor.hpp"
#include "Contact.hpp"

template <typename ...Types>
class CommandInvoker {
    public:
        CommandInvoker(std::string commandToInvoke, Types()...); 

    private:
        Contact contactForAdd_;
        std::string byWhatForFind_;
        std::string contactToFind_;
        std::string contactNameToRemove_;
};

#endif // COMMAND_INVOKER_HPP

