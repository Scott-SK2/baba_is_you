#include "element.h"

namespace model{

Element::Element(ElementType type){
    type_ = type;
    //if the element is text
    if(to_int() > 8){
        state_ = State::PUSHABLE;
    }
}

Element::Element(ElementType type, State state){
    type_ = type;
    state_ = state;
}

//setters
void Element::state(State state){
    state_ = state;
}

void Element::type(ElementType type){
    type_ = type;
}

//getters
State Element::state(){
    return state_;
}

ElementType Element::type(){
    return type_;
}

int Element::to_int()
{
    return static_cast<int>(type_);
}

State Element::text_state()
{
    switch(type_){
    case ElementType::KILL:
        return State::KILLING;
    case ElementType::YOU:
        return State::YOU;
    case ElementType::WIN:
        return State::WINING;
    case ElementType::STOP:
        return State::STOP;
    case ElementType::SINK:
        return State::SINKING;
    case ElementType::PUSH:
        return State::PUSHABLE;
    default:
        return State::TRAVERSABLE;
    }
}

ElementType Element::reference_to()
{
    switch (type_) {
    case ElementType::TWATER:
        return ElementType::WATER;
    case ElementType::TWALL:
        return ElementType::WALL;
    case ElementType::TFLAG:
        return ElementType::FLAG;
    case ElementType::TROCK:
        return ElementType::ROCK;
    case ElementType::TLAVA:
        return ElementType::LAVA;
    default:
        return ElementType::BABA;
    }
}

//to string
std::string const Element::to_string()const
{
    switch(type_){
        case ElementType::BABA:
        return "BABA";
    case ElementType::TBABA:
        return "TXBA";
    case ElementType::FLAG:
        return "FLAG";
    case ElementType::TFLAG:
        return "TXFG";
    case ElementType::GRASS:
        return "GRAS";
    case ElementType::IS:
        return " IS ";
    case ElementType::KILL:
        return "KILL";
    case ElementType::LAVA:
        return "LAVA";
    case ElementType::WALL:
        return "WALL";
    case ElementType::TWALL:
        return "TXWL";
    case ElementType::TLAVA:
        return "TLVA";
    case ElementType::WATER:
        return "WATR";
    case ElementType::TWATER:
        return "TXWA";
    case ElementType::WIN:
        return "WIN_";
    case ElementType::ROCK:
        return "ROCK";
    case ElementType::TROCK:
        return "TXRC";
    case ElementType::METAL:
        return "METL";
    case ElementType::PUSH:
        return "PUSH";
    case ElementType::SINK:
        return "SINK";
    case ElementType::STOP:
        return "STOP";
    case ElementType::YOU:
        return "YOU_";
    default:
        return "    ";
    }
}

bool operator==(const Element &e1, const Element &e2)
{
    return e1 == e2;
}

std::ostream & operator<<(std::ostream & out, const Element & element)
{
    return out << element.to_string();
}


} //namespace model
