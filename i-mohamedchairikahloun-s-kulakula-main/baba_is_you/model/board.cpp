#include "board.h"
#include "position.h"
#include "rule.h"


namespace model{


Board::Board(unsigned level_number) : level_{level_number}
{
    level_.read_file();
    map_.resize(level_.height(),std::vector<Box>(level_.width()));
    level_.put_the_world(*this);
    Rule rule(*this);
    rule.applies_all_rules();
}
std::vector<std::vector<Box>> Board::map() const
{
    return map_;
}

unsigned const Board::height()
{
    return level_.height();
}
unsigned const Board::width()
{
    return level_.width();
}

unsigned Board::level_seved()
{
    return level_.saved_level_number();
}

void Board::set_element(Position position,Element element)
{
    if(!positions_of_element(element.type()).empty()){
        Position pos = positions_of_element(element.type()).at(0);
        //The same state as the others elements has the same type
        State s = box(pos).state(element.type());
        element.state(s);
    }
    //add the element at the position above the box
    box(position).add_element(element);
}

bool Board::contains(Position position, State state){
    return box(position).contains(state);
}

Element Board::last_element(Position position)
{
    return box(position).last_element();
}

ElementType Board::type(Position position, State state){
    return box(position).type(state);
}

void Board::drop_element(ElementType type, Position position)
{
    box(position).drop_element(type);
}

void Board::drop_last(Position position)
{
    box(position).drop_last();
}

void Board::change_state(ElementType type, State state){
    for(auto &pos : positions_of_element(type)){
        box(pos).change_state(type, state);
    }
}

void Board::change_type(ElementType type1, ElementType type2){
    State s = State::TRAVERSABLE;
    if(!positions_of_element(type2).empty()){
        Position pos = positions_of_element(type2).at(0);
        s = box(pos).state(type2);
    }

    for(auto &pos : positions_of_element(type1)){
        box(pos).change_type(type1, type2);
        box(pos).change_state(type2, s);
    }
}

void Board::applies_rules()
{
    Rule rule(*this);
    rule.applies_all_rules();
}

void Board::unexecute_rule()
{
    Rule rule(*this);
    rule.unapplies_rules();
}

unsigned Board::numbers_of_you_(Position position){
    return box(position).quantity_you();
}

bool Board::position_in_the_map(Position position)
{
    return position.row() < level_.height()
            && position.row() >= 0
            && position.column() < level_.width()
            && position.column() >= 0;
}

std::vector<std::pair<Position, ElementType>> Board::types_at_map()
{
    std::vector<std::pair<Position, ElementType>> types_with_pos;
    for(unsigned i{}; i < map_.size(); ++i){
        for(unsigned j{}; j < map_[i].size(); ++j){
            for(auto type : box(Position(i,j)).elements_type()){
                types_with_pos.push_back(std::pair(Position(i,j), type));
            }
        }
    }
    return types_with_pos;
}

std::vector<Position> Board::positions_of_element(ElementType type)
{
    std::vector<Position> positions;
    for (auto i = 0; i<map_.size(); ++i) {
        for(auto j = 0; j<map_[i].size(); ++j){
            Position pos(i,j);
            //if the box contains the this type
            if(box(pos).contains(type))   positions.push_back(pos);
        }
    }
    return positions;
}

std::vector<Position> Board::positions_of_element(State state)
{
    std::vector<Position> positions;
    for (auto i = 0; i<map_.size(); ++i) {
        for(auto j = 0; j<map_[i].size(); ++j){
            Position pos(i,j);
            //if the box contains the this type
            if(box(pos).contains(state)){
                positions.push_back(pos);
            }
        }
    }
    return positions;
}


bool Board::you_above_win()
{
    std::vector<Position> pos_you = positions_of_element(State::YOU);
    std::vector<Position> pos_win = positions_of_element(State::WINING);

    for(auto e : pos_you){
        for(auto e2 : pos_win){
            if(e == e2) return true;
        }
    }
    return false;
}

std::vector<Position> Board::positions_text()
{
    //vector that we will return
    std::vector<Position> positions;

    for (unsigned i{}; i<map_.size(); ++i) {
        for(unsigned j{}; j<map_[i].size(); ++j){
            Position pos(i,j);
            if(box(pos).last_element().to_int() >= 16){
                positions.push_back(pos);
            }
        }
    }
    return positions;
}

Box & Board::box(Position position){
    return map_[position.row()][position.column()];
}
}//namespace model
