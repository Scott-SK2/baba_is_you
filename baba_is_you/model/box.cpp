#include "box.h"

namespace model
{

Box::Box() : size_(1)
{
    //Always there is earth on the box
    box_.push_back(Element{});
}

Element Box::last_element()
{
    return box_.at(size_-1);
}

ElementType Box::type(State state)
{
    for(auto e : box_){
        if(e.state() == state){
            return e.type();
        }
    }
    return ElementType::EARTH;
}

unsigned Box::size()
{
    return size_;
}

void Box::add_element(Element element)
{
    if(element.type() == ElementType::EARTH)
        throw std::invalid_argument("You can't add this Element");
    box_.push_back(element);
    ++size_;
}

void Box::drop_last()
{
    if(size_ == 1)
        throw std::invalid_argument("You can't drop the element in the box");
    //we drop the last element at the box
    box_.pop_back();
    --size_;
}

void Box::drop_element(ElementType type)
{
    int index = element_index(type);
    if(size_ == 1 || index == -1 || type == ElementType::EARTH)
        throw std::invalid_argument("You can't drop the element in the box2");
    box_.erase(box_.begin() + index);
    --size_;
}

State Box::state(ElementType type)
{
    return box_.at(element_index(type)).state();
}


int Box::element_index(ElementType type){
    for(unsigned i{}; i < box_.size(); ++i)
    {
        if(box_[i].type() == type)  return i;
    }
    return -1;
}


bool Box::contains(ElementType type)
{
    for(auto e : box_){
        if(e.type() == type) return true;
    }
    return false;
}

bool Box::contains(State state)
{
    for(auto e : box_){
        if(e.state() == state) return true;
    }
    return false;

}

unsigned Box::quantity_you(){
    if(!contains(State::YOU)){
        throw std::invalid_argument("The element YOU does not existe on the Box");
    }
    unsigned number_of_you {};
    for(auto e : box_){
        if(e.state() == State::YOU)
            number_of_you++;
    }
    return number_of_you;
}

void Box::change_state(ElementType type,State state)
{
    //if the box doesn't contains this type
    if(!contains(type) || type == ElementType::EARTH)
        throw std::invalid_argument("You can not change the state");
    for(auto &e : box_){
        if(e.type() == type){
            e.state(state);
        }
    }
}

void Box::change_type(ElementType type1,ElementType type2)
{
    //if the box doesn't contains this type
    if(!contains(type1) || type1 == ElementType::EARTH)
        throw std::invalid_argument("You can not change the type");
    for(auto &e : box_){
        if(e.type() == type1){
            e.type(type2);
        }
    }
}

std::vector<ElementType> Box::elements_type()
{
    std::vector<ElementType> types;
    if(size_ > 1){
        for(unsigned i{1}; i < box_.size(); ++i){
            types.push_back(box_.at(i).type());
        }
    }
    return types;
}


}//namespace model

