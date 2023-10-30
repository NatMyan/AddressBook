#ifndef SORT_COMMAND_HPP
#define SORT_COMMAND_HPP

#include "Command.hpp"

#include <string>

class SortCommand : public Command  {
    public:
        std::string sortCommand();
        void accept(CommandVisitor& visitor) override;
};

#endif // SORT_COMMAND_HPP