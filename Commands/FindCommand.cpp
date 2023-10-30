#include "FindCommand.hpp"

std::string FindCommand::findCommand(std::string byWhat, std::string contactToFind) {
    std::string findContactSQL = "SELECT * FROM contacts WHERE " + byWhat + " = '" + contactToFind + "';";
    return findContactSQL;
}

void FindCommand::accept(CommandVisitor& visitor) {
    visitor.visit(*this);
}