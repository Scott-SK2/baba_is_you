#ifndef APP_GUI_H
#define APP_GUI_H

#include <QWidget>
#include "board_gui.h"
#include <QKeyEvent>
#include "model/game.h"
#include "reception.h"
#include "./observer/observer.h"


namespace view_gui
{


/**
 * @brief The App_Gui class The class that represent application of the game.
 * Its the responsable of show or delete layout in the application
 */
class App_Gui : public QWidget, public Observer
{

    QBoard * view_;
    Reception * reception_;
    model::Game game_{};

    /**
     * @brief add_action_btn Add the action of QPushButton after the player
     * Click in one of three buttons
     */
    void add_action_btn();

    /**
     * @brief add_elements_application Add the element that always exist
     * with the application (title, background...)
     */
    void initial_application();

    /**
     * @brief display_reception Initial a reception of the game
     */
    void display_reception();

    /**
     * @brief start_game start the game with the 1st level
     */
    void initial_game();

    /**
     * @brief replay_level Restart the game that the player quit
     */
    void replay_level();

public:
    /**
     * @brief Constructor of application
     */
    App_Gui();

    void update() override;

    /**
     * @brief start_game This method is initial reception and add the handle
     * to start/replaye the game or show option window
     */
    void start_game();

protected:

    /**
     * @brief keyPressEvent Getter of the signal key
     * and take the signal that we need
     * @param event
     */
    void keyPressEvent(QKeyEvent *event) override;



};

}   //namespace view_gui

#endif // APP_GUI_H
