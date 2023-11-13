#include "RemoveCommand.hpp"

std::string RemoveCommand::removeCommand (std::string contactName) {
    std::string removeContactSQL = "DELETE FROM contacts WHERE name = '" + contactName + "';";
    return removeContactSQL;
}

void RemoveCommand::accept(CommandVisitor& visitor) {
    visitor.visit(*this);
}