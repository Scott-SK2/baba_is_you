#include "rule.h"
#include "board.h"

namespace model {

Rule::Rule(Board & board)
{
    board_ = &board;
}

void Rule::applies_all_rules()
{
    //take all positions of the texts
    for(auto position : board_->positions_text())
    {
        check_and_applies_rule(position);
    }
}

void Rule::check_and_applies_rule(Position position)
{
    //Set the type_ that is referenced by text at position (TWALL, TBABA..)
    type_ = board_->last_element(position).reference_to();
    board_->change_state(type_, State::TRAVERSABLE);

    //Check horizontally
    Position p(position.row(),position.column()+1);
    Position p2(position.row(),position.column()+2);
    applies_rule(p, p2);
    //Check vertically
    Position p3(position.row()+1,position.column());
    Position p4(position.row()+2,position.column());
    applies_rule(p3, p4);
}

void Rule::applies_rule(Position p1, Position p2)
{
    if(!board_->position_in_the_map(p1) || !board_->position_in_the_map(p1)){
        return;
    }
    Element is = board_->last_element(p1);
    //if there is the conector is
    if(is.type() == ElementType::IS)
    {
        if(there_is_type_tochange(p2))
        {
            //Set the new_type_element_ that is referenced by text at position (p2) (TWALL, TBABA..)
            new_type_ = board_->last_element(p2).reference_to();
            board_->change_type(type_, new_type_);
            //enregistre the type for undo
            type_is_change = std::pair(type_, new_type_);
        }else if(there_is_state_tochange(p2))
        {
            //The new state that we will set to the type_of_element_
            new_state_ = board_->last_element(p2).text_state();
            board_->change_state(type_, new_state_);
        }
    }
}


void Rule::unapplies_rules()
{
    if(type_is_change.second != ElementType::EARTH){
        board_->change_type(type_is_change.second, type_is_change.first);
    }
    applies_all_rules();
}

bool Rule::there_is_state_tochange(Position position)
{
    //The element type of text convert to int
    int element_to_int = board_->last_element(position).to_int();
    //if the  9 <= int <= 14  so there is state to change
    return element_to_int >= 9 && element_to_int <= 14;
}

bool Rule::there_is_type_tochange(Position position)
{
    //The element type of text convert to int
    int element_to_int = board_->last_element(position).to_int();
    //if the int >= 16 so there is type to change
    return element_to_int >= 16;
}

} //namespace model
