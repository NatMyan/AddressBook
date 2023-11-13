#include "SortCommand.hpp"

std::string SortCommand::sortCommand() {
    std::string sortContactsSQL = "SELECT * FROM contacts ORDER BY name;";
    return sortContactsSQL;
}

void SortCommand::accept(CommandVisitor& visitor) {
    visitor.visit(*this);
}