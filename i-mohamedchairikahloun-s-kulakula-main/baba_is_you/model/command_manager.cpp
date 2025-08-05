#include "command_manager.h"

namespace model{

void Command_Manager::add_command(Move_command &cmd){
    cmd.execute();
    undo_stack.push(cmd);
}

void Command_Manager::undo()
{
    if(!undo_stack.empty()){
        Move_command cmd = undo_stack.top();
        cmd.unexecute();
        undo_stack.pop();
    }
}


}   //namespace model
