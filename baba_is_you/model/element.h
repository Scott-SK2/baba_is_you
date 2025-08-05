#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

namespace model {


/**
 * @brief The State enum the state of an element on the board
 */
enum class State
{
    PUSHABLE,
    STOP,
    YOU,
    KILLING,
    WINING,
    SINKING,
    TRAVERSABLE
};

/**
 * @brief The ElementType enum type of an element on the board
 */
enum class ElementType
{
    EARTH,
    LAVA,
    FLAG,
    ROCK,
    WALL,
    GRASS,
    METAL,
    BABA,
    WATER,
    //Element can change state
    KILL,   //9
    YOU,
    WIN,
    STOP,
    PUSH,
    SINK,   //14
    //connector
    IS,
    //Text
    TWATER, //16
    TBABA,
    TWALL,
    TFLAG,
    TROCK,
    TLAVA
};


/**
 * @brief The Element class the elements that build the board of the game
 */
class Element
{
    //the default state is PUSHABLE
    State state_{State::TRAVERSABLE};
    ElementType type_;

public:
    /**
     * @brief Element Contructor of element
     * with his type in parametre
     * @param type ElementType that we will give to the elment
     */
    Element(ElementType type);
    //default constructor
    Element() = default;
    /**
     * @brief Element Constructor of element
     * with the type and the state on parametre
     * @param type ElementType that we will set to the elment
     * @param state State that we will set to the element
     */
    Element(ElementType type, State state);


    //setters
    void state(State state);
    void type(ElementType type);
    //getters
    State state();
    ElementType type();
    //to string
    std::string const to_string()const;

    /**
     * @brief to_int Convert the type_ to int
     * @return Integer the value of enum ElementType
     */
    int to_int();

    /**
     * @brief text_reference_to The element type Text
     * do the reference to which object
     * TBABA -> BABA  || TWALL -> WALL || TFLAG -> FLAG...
     * @param type The text that we check his reference
     * @return ElementType that text do the reference to
     */
    ElementType reference_to();

    /**
     * @brief text_state Look for the state that ElementType
     * will change
     * (ElementType=PUSH -> return PUSHABLE / (ElementType=KILL -> return KILLING...)
     */
    State text_state();

};

bool operator==(const Element &e1, const Element &e2);
std::ostream & operator<<(std::ostream & out, const Element & element);
}   //namespace model

#endif // ELEMENT_H
