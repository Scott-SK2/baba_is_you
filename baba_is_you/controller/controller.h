#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"
#include "view/console/view.h"

namespace model{

class Controller{

    Game game_;
    View view_;

    //the token that user will write in
    std::string keyboard;
    bool game_is_over;

public:
    Controller();
    void play();

    /**
     * @brief Controller this Controller for initial a level saved
     * @param game
     */
    Controller(Game game);

private:
    void execute_cmd_of_player();
};


}

#endif // CONTROLLER_H
