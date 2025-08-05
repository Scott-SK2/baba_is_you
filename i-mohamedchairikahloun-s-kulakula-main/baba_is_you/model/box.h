#ifndef CASE_H
#define CASE_H

#include "element.h"
#include <vector>

namespace model{



class Box
{
    //Box oh the map
    std::vector<Element> box_;
    //How many element in the box(min:1)
    unsigned size_{};

    /**
     * @brief element_index check the index of element that given
     * his type
     * @param type the type of element
     * @return index of element if it existe and -1 otherwise
     */
    int element_index(ElementType type);

public:

    /**
     * @brief Box Contructor initial the size_
     * and push the default element (EARTH) in the box
     */
    Box();

    //Getters
    /**
     * @brief last_element in the box
     * @return Element that is above in the box
     */
    Element last_element();
    /**
     * @brief size of the box
     */
    unsigned size();

    /**
     * @brief state The State of the ElementType on parameter
     * @param type the ElementType that we search for his State
     * @return Sate of the ElementType
     */
    State state(ElementType type);

    /**
     * @brief type return the type which has the same
     * State as this is on parameter
     * @param state State that we search his ElementType
     * @return ElementType
     */
    ElementType type(State state);

    /**
     * @brief add_element push back the element in the box
     * @param elemnt The element that we are going to push
     */
    void add_element(Element elemnt);
    /**
     * @brief drop_element Drop the last element in the box
     * if there is just Earth throw exception
     */
    void drop_last();

    /**
     * @brief drop_element drop element in the box
     * which has this type
     * @param type Element type that we are going to drop
     * his element
     */
    void drop_element(ElementType type);

    /**
     * @brief contains verify if the box contains an element
     * has the same type on parametre
     * @param type ElementType that we search
     * @return true if type in the box false otherwise
     */
    bool contains(ElementType type);

    /**
     * @brief contains verify if the box contains an element
     * has the same state on parametre
     * @param state State that we search
     * @return true if the state in the box false otherwise
     */
    bool contains(State state);

    /**
     * @brief change_state change the state of all the element
     * has the same type as this is on the parameter
     * @param type The ElementType that we will change his State
     */
    void change_state(ElementType type, State state);
    /**
     * @brief change_type all the Element has the same type
     * as type1 to the type2
     * @param type1 ElementType that we will change
     * @param type2 ElementType that we will set to type1
     */
    void change_type(ElementType type1, ElementType type2);

    /**
     * @brief quantity_you return how many of elements have the state
     * YOU on the box
     */
    unsigned quantity_you();

    /**
     * @brief elements_type vector contains all the ElementType
     * in the Box
     * @return vector of ElementType
     */
    std::vector<ElementType> elements_type();


};

}//namespace model

#endif // CASE_H
