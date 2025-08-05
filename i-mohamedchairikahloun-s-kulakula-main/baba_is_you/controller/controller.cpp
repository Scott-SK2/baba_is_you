#include "controller.h"
#include "model/direction.h"

namespace model {

Controller::Controller() : game_is_over(false)
{}

Controller::Controller(Game game): game_is_over(false) , game_(game)
{}

void Controller::play()
{
    if(!game_is_over)
    {
        view_.display_board(game_.board().map());
        if(game_.game_state() == Game_State::END_OF_LEVEL)
        {
            game_.next_level();
            view_.display_end_level();
            view_.display_board(game_.board().map());
        }
        view_.ask_direction();
        std::cin >> keyboard;
        execute_cmd_of_player();
        play();
    }else{
        //sauvegarde la partie
        game_.save_level();
    }

}


void Controller::execute_cmd_of_player()
{
    if(keyboard == "u"){
        game_.move_you_position(Direction::UP);
    }else if(keyboard == "d"){
        game_.move_you_position(Direction::DOWN);
    }else if(keyboard == "r"){
        game_.move_you_position(Direction::RIGHT);
    }else if(keyboard == "l"){
        game_.move_you_position(Direction::LEFT);
    }else if(keyboard == "z"){
        game_.undo();
    }else if(keyboard == "re"){
        game_.replay();
    }else if(keyboard == "n"){
        game_.next_level();
    }else if(keyboard == "h"){
        view_.display_menu();
    }else if(keyboard == "q"){
        game_is_over = true;
    }else if(keyboard == "p"){
        game_.previous_level();
    }else{
        view_.display_error();
    }
}


}//namespace model
