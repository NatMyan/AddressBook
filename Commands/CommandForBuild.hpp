#ifndef COMMAND_FOR_BUILD_HPP
#define COMMAND_FOR_BUILD_HPP

#include "AddCommand.hpp"
#include "RemoveCommand.hpp"
#include "FindCommand.hpp"
#include "SortCommand.hpp"

class CommandForBuild {
    public:
        void createForAdd(Contact contactForAdd);
        void createForFind(std::string byWhatForFind, std::string contactToFind);
        void createForRemove(std::string contactNameToRemove);

    private:
        Contact contactForAdd_;
        std::string byWhatForFind_;
        std::string contactToFind_;
        std::string contactNameToRemove_;

};

#endif // COMMAND_FOR_BUILD_HPP