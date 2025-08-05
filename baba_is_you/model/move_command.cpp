#include "move_command.h"
#include "direction.h"

namespace model {

Move_command::Move_command(Board &board, Direction direction)
    : board_{board}, dir_(direction){}


void Move_command::execute()
{
    text_pushed = false;
    move_you();
    kill();
    sink();
    execute_rule();
}

void Move_command::unexecute(){
    unsink();
    unkill();
    back();
    unexecute_rule();
}

void Move_command::move_you() {
    if( board_.positions_of_element(State::YOU).empty()){
        return ;
    }
    //initialize the ElementType of you_
    you_ = board_.type(board_.positions_of_element(State::YOU).at(0), State::YOU);
    for(auto old_pos : board_.positions_of_element(State::YOU))
    {
        Position next_pos = old_pos.next(dir_);
        if(in_table_and_not_stop(next_pos)){
            //if the next position there is element pushable
            if(board_.contains(next_pos, State::PUSHABLE))
            {
                Position final_pos = final_position(next_pos);
                //if we can push the element
                if(final_pos.row() != -1){
                    you_to_move_.push_back(std::pair(old_pos,next_pos));
                    element_to_push_.push_back(std::pair(next_pos, final_pos));
                    //if we are pushed the text
                    if(text_is_pushed(next_pos)){
                        text_pushed = true;
                    }
                }
            }else{
                you_to_move_.push_back(std::pair(old_pos,next_pos));
                //if we are pushed the text
                if(text_is_pushed(next_pos)){
                    text_pushed = true;
                }
            }
        }
    }
    move_and_push();
    put_in_the_vector(State::SINKING);
    put_in_the_vector(State::KILLING);

}


void Move_command::move_element(Position position_initial, Position next_pos, State state){
    ElementType elem = board_.type(position_initial, state);
    board_.set_element(next_pos, Element{elem});
    board_.drop_element(elem, position_initial);
}

void Move_command::push_element(Position position_initial, Position position_final, State state, Direction dir)
{
    if(!(position_initial == position_final)){
        Position pos = position_initial.next(dir);
        move_element(position_initial, pos, state);
        push_element(pos, position_final, state, dir);
    }
}

Position Move_command::final_position(Position position)
{
    position = position.next(dir_);
    while(in_table_and_not_stop(position))
    {
        //if we can push the element to the position
        if(!board_.contains(position, State::PUSHABLE))
            return position;
        position = position.next(dir_);
    }
    return Position{-1,-1};
}

void Move_command::put_in_the_vector(State state){
    for(auto pos : board_.positions_of_element(state)){
        //si il y'a un autre etat que sinking
        if(auto e = board_.last_element(pos);
                e.state() != state && e.to_int() < 9){
            if(state == State::KILLING){
                element_to_kill_.push_back(std::pair(e.type(), pos));
            }else{
                ElementType elment_sink = board_.type(pos, state);
                element_to_sink_.push_back(std::pair(pos, std::pair(e.type(), elment_sink)));
            }
        }
    }
}
void Move_command::put_in_many_you_to_move()
{
    if(!you_to_move_.empty()){
        for(unsigned i{}; i < you_to_move_.size(); i++) {
            Position pos_you = you_to_move_.at(i).first;
            //if there is + than 1 you
            if(unsigned quantity = board_.numbers_of_you_(pos_you);
                    quantity > 1){
                many_you_to_move_.push_back(std::pair(
                        //add quantity to move and positions of element to move
                        quantity, std::pair(pos_you, you_to_move_.at(i).second)));
                you_to_move_.erase(you_to_move_.begin() + i);
                i--;
            }
        }
    }
}

void Move_command::execute_rule()
{
    if(text_pushed){
        board_.applies_rules();
    }
}

void Move_command::unexecute_rule(){
    if(text_pushed){
        board_.unexecute_rule();
    }
}

void Move_command::sink(){
    if(!element_to_sink_.empty()){
        for(auto e : element_to_sink_){
            board_.drop_last(e.first);
            board_.drop_last(e.first);
        }
    }
}

void Move_command::unsink(){
    if(!element_to_sink_.empty()){
        for(auto e : element_to_sink_){
            board_.set_element(e.first, Element{e.second.first});
            board_.set_element(e.first, Element{e.second.second});
        }
    }
}

void Move_command::kill(){
    if(!element_to_kill_.empty()){
        for(auto e : element_to_kill_){
            //we kill just le you if he is in KILL
            if(board_.contains(e.second, State::YOU)){
                board_.drop_element(e.first, e.second);
            }
        }
    }
}

void Move_command::unkill(){
    if(!element_to_kill_.empty()){
        for(auto e : element_to_kill_){
            board_.set_element(e.second, e.first);
        }
    }
}

void Move_command::move_and_push(){
    put_in_many_you_to_move();
    if(!many_you_to_move_.empty()){
        for(auto e : many_you_to_move_){
            for(unsigned i{}; i < e.first; ++i){
                move_element(e.second.first, e.second.second, State::YOU);
            }
        }
    }
    if(!you_to_move_.empty()){
        for(auto e : you_to_move_){
            move_element(e.first, e.second, State::YOU);
        }
    }
    if(!element_to_push_.empty()){
        for(auto e : element_to_push_){
            push_element(e.first, e.second, State::PUSHABLE, dir_);
        }
    }
}

void Move_command::back()
{
    if(!many_you_to_move_.empty()){
        for(auto e : many_you_to_move_){
            for(unsigned i{}; i < e.first; ++i){
                move_element(e.second.second, e.second.first, State::YOU);
            }
        }
    }
    if(!you_to_move_.empty()){
        //if the element you was droped
        board_.change_state(you_, State::YOU);
        for(auto e : you_to_move_){

            move_element(e.second, e.first, State::YOU);
        }
    }
    if(!element_to_push_.empty()){
        for(auto e : element_to_push_){
            push_element(e.second, e.first, State::PUSHABLE, oposite(dir_));
        }
    }
}

bool Move_command::in_table_and_not_stop(Position position){
    return board_.position_in_the_map(position)
            && !board_.contains(position, State::STOP);
}

bool Move_command::text_is_pushed(Position next_pos)
{
    return board_.last_element(next_pos).to_int() >= 9;
}
} // namespace model

