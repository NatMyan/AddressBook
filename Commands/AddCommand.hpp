#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "../Contact.hpp"
#include "Command.hpp"

class AddCommand : public Command {
    public:
        std::string addCommand(Contact contact);
        void accept(CommandVisitor& visitor) override;

    private:
        std::string buildContactPart(std::vector<std::string> contactPart);
};

#endif // ADD_COMMAND_HPP