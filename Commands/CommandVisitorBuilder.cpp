#include "CommandVisitorBuilder.hpp"

CommandVisitorBuilder::CommandVisitorBuilder() {
    cmdForBuild_ = std::make_shared<CommandForBuild>();
}

std::shared_ptr<CommandForBuild> CommandVisitorBuilder::createForAdd(Contact contactForAdd) {
    cmdForBuild_->createForAdd(contactForAdd);
    return cmdForBuild_;
}

std::shared_ptr<CommandForBuild> CommandVisitorBuilder::createForFind(std::string byWhatForFind, std::string contactToFind) {
    cmdForBuild_->createForFind(byWhatForFind, contactToFind);
    return cmdForBuild_;
}

std::shared_ptr<CommandForBuild> CommandVisitorBuilder::createForRemove(std::string contactNameToRemove) {
    cmdForBuild_->createForRemove(contactNameToRemove);
    return cmdForBuild_;
}

std::shared_ptr<CommandForBuild> CommandVisitorBuilder::build() {
    return cmdForBuild_;
}
