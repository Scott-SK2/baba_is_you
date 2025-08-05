#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "position.h"
#include "box.h"
#include "level.h"

namespace model {

class Board
{
    //vector 2D of boxes
    std::vector<std::vector<Box>> map_;
    Level level_;

    /**
     * @brief box Getter of the box
     * @param position Position where the box is
     * @return Box at position which contains vector of element
     */
    Box & box(Position position);


public:
    /**
     * @brief Board Constructor of the class Board
     * @param level_number number of the level to inizialise
     * a level of the game
     */
    Board(unsigned level_number);

//Getters
    std::vector<std::vector<Box>> map() const;
    /**
     * @brief positions_text All the positions
     * of element has type Text (TWALL, TROCK...)
     * @return vector of positions
     */
    std::vector<Position> positions_text();

    /**
     * @brief positions_of_element return all the positions on the board
     * of type in the parameter
     * @param type Element type that we search on the table
     * @return vector contains all positions of the type
     */
    std::vector<Position> positions_of_element(ElementType type);

    /**
     * @brief positions_of_element return all the positions on the board
     * of state in the parameter
     * @param state State that we search on the table
     * @return vector contains all positions of the state
     */
    std::vector<Position> positions_of_element(State state);

    /**
     * @brief last_element return the last element in the box
     * @param position Position of the box in the board
     * @return Element at Position
     */
    Element last_element(Position position);

    /**
     * @brief type return the type of element in the box
     * has the same state as this is in parameter
     * @param position Position of the box
     * @param state State of element that we search
     * @return ElementType of Element has the state
     */
    ElementType type(Position position, State state);

    /**
     * @brief contains check the box at this Position
     * if it contains this state
     * @param position Position of the Box
     * @param state State that we check if it exicte in the Box
     * @return true if the state in the Box false otherwise
     */
    bool contains(Position position, State state);

    unsigned const height();
    unsigned const width();

    /**
     * @brief level_seved value of the level saved
     */
    unsigned level_seved();

//setters
    /**
     * @brief set_element set element above in the box
     * and initial his state like the others same ElemetType
     * if there existe
     * @param position Position of the box where we are going
     * set the element in
     * @param element the Element that we set
     */
    void set_element(Position position,Element element);

    /**
     * @brief drop_last the last element in the box at this position
     */
    void drop_last(Position position);

    /**
     * @brief drop_element drop element in that position
     * in the box which has this type
     * @param type ElementType that we check to drop his element
     * @param position Position of the box
     */
    void drop_element(ElementType type, Position position);

    /**
     * @brief change_state change state of all element in the boxes
     *  which has the same type on parametre
     * @param type ElementType that we will change his type
     * @param state the new state that we set to the element
     */
    void change_state(ElementType type, State state);

    /**
     * @brief change_type change type of all element in the boxes
     *  which has the same type on parametre and change state
     *  of elements to the same state as the type2
     * @param type1 ElementType that we will change his type
     * @param type2 the new ElementType that we set to the element
     */
    void change_type(ElementType type1, ElementType type2);

    /**
     * @brief applies_rule applies all the rules in the board
     */
    void applies_rules();

    /**
     * @brief unexecute_rule unexecute the rules that we applied
     */
    void unexecute_rule();

    /**
     * @brief position_in_the_map chack if the position is
     * not off the table
     * @param position Position that we chek for it
     * @return true if the position on the table false otherwise
     */
    bool position_in_the_map(Position position);

    /**
     * @brief you_above_win check if the player is in the target
     * @return true if the player in the targer false otherwise
     */
    bool you_above_win();

    /**
     * @brief numbers_of_you_ How many elements have the State YOU at this Position
     * @param position The position that we check how many of you in
     */
    unsigned numbers_of_you_(Position position);

    /**
     * @brief types_at_map vector of pair contains all the elements type
     * and the position
     * @return vector of pair
     */
    std::vector<std::pair<Position, ElementType>> types_at_map();



};

}   //namespace model

#endif // BOARD_H
