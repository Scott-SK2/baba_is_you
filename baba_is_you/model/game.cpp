#include "game.h"
#include "move_command.h"

namespace model {

Game::Game()
    :board_{0}, game_state_{Game_State::PLAY}, level_{}
{}

Game::Game(Board board) : board_(board), game_state_{Game_State::PLAY}
{
    level_ = board_.level_seved();
}

Game_State Game::game_state()
{
    return game_state_;
}

void Game::change_state_of_game()
{
    if(board_.you_above_win())
        game_state_ = Game_State::END_OF_LEVEL;
    else
        game_state_ = Game_State::PLAY;

}

void Game::move_you_position(Direction direction)
{
    Move_command move(board_, direction);
    cmd_mng_.add_command(move);
    change_state_of_game();
    notify_observer();
}

void Game::next_level(){
    level_ = (level_+1) % 5;
    board_ = Board(level_);
//    notify_observer();

}

void Game::previous_level()
{
    level_ = (level_-1) == -1 ? 0 : (level_-1);
    board_ = Board(level_);
}

void Game::replay(){
    board_ = Board(level_);
    notify_observer();
}

void Game::undo()
{
    cmd_mng_.undo();
    notify_observer();
}

Board Game::board() const
{
    return board_;
}

void Game::save_level()
{
    Level level;
    level.save_level(board_, level_);
}


}
