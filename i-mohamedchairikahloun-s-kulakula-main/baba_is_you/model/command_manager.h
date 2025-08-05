#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H
#include "move_command.h"
#include <stack>


namespace model {


class Command_Manager
{
    /**
     * Stack content the executes command
     * they can be unexecuted
     */
    std::stack<Move_command> undo_stack;

public:
    /**
     * Add all the command to the stack undo and clear redo
     * @param command Command first command
     */
    void add_command(Move_command &cmd);
    /**
     * Cancel the last command
     */
    void undo();
};

}   //namespace model

#endif // COMMAND_MANAGER_H
