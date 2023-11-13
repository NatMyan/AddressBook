#ifndef COMMAND_VISITOR_HPP
#define COMMAND_VISITOR_HPP

class AddCommand;
class FindCommand;
class RemoveCommand;
class SortCommand;

class CommandVisitor {
    public:
        virtual void visit(AddCommand& command) = 0;
        virtual void visit(FindCommand& command) = 0;
        virtual void visit(RemoveCommand& command) = 0;
        virtual void visit(SortCommand& command) = 0;
};

#endif // COMMAND_VISITOR_HPP