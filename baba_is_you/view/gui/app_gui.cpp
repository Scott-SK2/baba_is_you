#include "app_gui.h"
#include "option.h"
#include "model/direction.h"

namespace view_gui
{

App_Gui::App_Gui()
    : view_{nullptr}, reception_{nullptr}
{
    initial_application();
}

void App_Gui::update()
{
    if(game_.game_state() == model::Game_State::END_OF_LEVEL){
        game_.next_level();
    }

    delete view_;
    view_ = new QBoard;
    this->setLayout(view_);
    view_->display_world(game_.board().map());
}

void App_Gui::display_reception()
{
    reception_ = new Reception;
    reception_->initial_reception();
    this->setLayout(reception_);
    add_action_btn();
}


void App_Gui::initial_game()
{
    view_ = new QBoard;
    view_->display_world(game_.board().map());
    this->setLayout(view_);
    game_.registered(this);

}

void App_Gui::replay_level()
{
    model::Board board(5); //level5 is the registered level
    game_ = model::Game(board);
    initial_game();
}

void App_Gui::initial_application()
{
    this->setWindowTitle("baba is you");
    this->setWindowIcon(QIcon("./images/baba.png"));
    this->setStyleSheet("QWidget { background-color: black; }");
    this->show();
}

void App_Gui::start_game()
{

    display_reception();
}


void App_Gui::keyPressEvent(QKeyEvent *event)
{
    if(view_ != nullptr)
    {
        switch(event->key())
        {
        case Qt::Key_Left :
            game_.move_you_position(model::Direction::LEFT);
            break;
        case Qt::Key_Right :
            game_.move_you_position(model::Direction::RIGHT);
            break;
        case Qt::Key_Up :
            game_.move_you_position(model::Direction::UP);
            break;
        case Qt::Key_Down :
            game_.move_you_position(model::Direction::DOWN);
            break;
        case Qt::Key_Z :
            game_.undo();
            break;
        case Qt::Key_R :
            game_.replay();
            break;
        case Qt::Key_N :
            game_.next_level();
            break;
        case Qt::Key_P :
            game_.previous_level();
            break;
        case Qt::Key_Escape :
            game_.save_level();
            this->close();
            break;
        }
    }

    QWidget::keyPressEvent(event);
}


void App_Gui::add_action_btn(){
    QObject::connect(&reception_->replay_btn(), &QPushButton::clicked, [this]() {
        delete reception_;
        replay_level();
    });

    QObject::connect(&reception_->play_btn(), &QPushButton::clicked, [this]() {
        delete reception_;
        initial_game();
    });

    QObject::connect(&reception_->option_btn(), &QPushButton::clicked, [this]() {
        Option * op = new Option;
        op->display_option();
    });
}

}   //namespace view_gui
