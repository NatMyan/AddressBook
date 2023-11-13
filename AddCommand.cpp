#include "AddCommand.hpp"

std::string AddCommand::addCommand(Contact contact) {
    std::string name = contact.name_;
    std::string phoneNums = buildContactPart(contact.phoneNumber_);
    std::string emails = buildContactPart(contact.email_);
    std::string addContactSQL = "INSERT INTO contacts (name, phone, email, additional) VALUES ('" + name + "', '" + phoneNums + "', '" + emails + "');";
    if (!contact.additional_.empty()) {
        std::string additionals = buildContactPart(contact.additional_);
        addContactSQL = addContactSQL = "INSERT INTO contacts (name, phone, email, additional) VALUES ('" + name + "', '" + phoneNums + "', '" + emails + "', '" + additionals + "');";
    }
    return addContactSQL;
}

std::string AddCommand::buildContactPart(std::vector<std::string> contactPart) {
    std::string partToBuild = "";
    for (const auto& part : contactPart) {
        partToBuild += part + '\n';
    }
    // partToBuild.pop_back();
    return partToBuild;
}

void AddCommand::accept(CommandVisitor& visitor) {
    visitor.visit(*this);
}