#ifndef RULE_H
#define RULE_H

#include <vector>
#include "position.h"
#include "element.h"

namespace model {

//Déclaration participé
class Board;

/**
 * @brief The Rule class It is the class that manages the rules of the game
 * And change state or Type of element if tehre is any rule indicates change
 */
class Rule
{
    //the type that we will change his state or type
    ElementType type_;
    //the new type of element if there is rule for it
    ElementType new_type_;

    Board *board_;
    //the new state of element if there is rule for it
    State new_state_;

    bool there_is_state_tochange(Position position);
    bool there_is_type_tochange(Position position);

    /**
     * @brief check_and_applies_rule check if there is rule
     * to applies if there is applies it
     * @param position Position of text that we check if there
     * is rule to applies
     */
    void check_and_applies_rule(Position position);

    /**
     * @brief applies_rule take the state or type and applies it
     * to an element Type
     * @param p1 Position of connector
     * @param p2 Position of type or state
     */
    void applies_rule(Position p1, Position p2);

    std::pair<ElementType, ElementType> type_is_change;

public:
    Rule(Board &board);

    /**
     * @brief chack_and_applies Take all the positions of text,
     * for each text check the state and applie the rule
     */
    void applies_all_rules();

    /**
     * @brief unapplies_rules remove the last rule
     */
    void unapplies_rules();

};

}// namespace model

#endif // RULE_H
