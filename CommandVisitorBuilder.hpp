#ifndef COMMAND_VISITOR_BUILDER_HPP
#define COMMAND_VISITOR_BUILDER_HPP

#include "CommandVisitor.hpp"
#include "CommandForBuild.hpp"

#include <memory>

class CommandVisitorBuilder : public CommandVisitor, public CommandForBuild {
    public:
        CommandVisitorBuilder();

    public:
        std::shared_ptr<CommandForBuild> createForAdd(Contact contactForAdd);
        std::shared_ptr<CommandForBuild> createForFind(std::string byWhatForFind, std::string contactToFind);
        std::shared_ptr<CommandForBuild> createForRemove(std::string contactNameToRemove);
        std::shared_ptr<CommandForBuild> build();

    private:
        std::shared_ptr<CommandForBuild> cmdForBuild_;
};

#endif // COMMAND_VISITOR_BUILDER_HPP