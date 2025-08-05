#ifndef GAME_H
#define GAME_H

#include "observer/observable.h"
#include "board.h"
#include "command_manager.h"


namespace model {


enum class Game_State
{
    PLAY,
    END_OF_LEVEL
};

class Game : public Observable
{
    Board board_;
    Game_State game_state_;
    Command_Manager cmd_mng_;
    int level_;

public:
    /**
     * @brief Game Constructor create the game with the board
     * and level in parametre
     * @param level
     */
    Game();

    /**
     * @brief Game Constructor with board that we will use when
     * replay the level saved
     * @param board
     */
    Game(Board board);

    /**
     * @brief game_state getter of the state of the game
     * @return Game_State
     */
    Game_State game_state();

    /**
     * @brief change_state_of_game change the state of the game
     */
    void change_state_of_game();

    /**
     * @brief move_you_position move all the element that have state you
     * @param direction where we are goig to playe the elements
     */
    void move_you_position(Direction direction);

    /**
     * @brief next_level Change board to the next_level
     */
    void next_level();

    /**
     * @brief previous_level Change board to the previous level
     */
    void previous_level();

    /**
     * @brief replay Replay the same level
     */
    void replay();

    /**
     * @brief undo Cancel the last command
     */
    void undo();

    /**
     * @brief board Getter of the Board that we will use to display
     * the map of the game
     * @return Board board_
     */
    Board board() const;

    /**
     * @brief save_level Save the level that the player is playing
     */
    void save_level();

};

}   //namespace model

#endif // GAME_H
