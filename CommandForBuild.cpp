#include "CommandForBuild.hpp"

void CommandForBuild::createForAdd(Contact contactForAdd) {
    contactForAdd_ = contactForAdd;
}

void CommandForBuild::createForFind(std::string byWhatForFind, std::string contactToFind) {
    byWhatForFind_ = byWhatForFind;
    contactToFind_ = contactToFind;
}

void CommandForBuild::createForRemove(std::string contactNameToRemove) {
    contactNameToRemove_ = contactNameToRemove;
}