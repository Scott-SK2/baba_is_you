#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include "observer.h"

#include <stdexcept>

class Observable
{
private:
    std::set<Observer* > _observers{};
public :


    /**
     * @brief registered Adds an observer to the set of observers for this object
     * @param observer an observer to be added.
     */
    inline void registered(Observer  *observer);

    /**
     * @brief unregistered  Deletes an observer from the set of observers of this object.
     * @param observer an observer to be removed.
     */
    inline void unregistered(Observer *observer);

protected:

    /**
     * @brief notify_observer If this object has changed,
     * then notify all of its observers. and update the observers
     */
    inline void notify_observer() const;
};

//implement
void Observable::registered(Observer * observer){
    if(observer == nullptr){
        throw std::invalid_argument("You observer that you add is null!");
    }
    _observers.insert(observer);
}

void Observable::unregistered(Observer *observer){
    _observers.erase(observer);
}

void Observable::notify_observer() const{
    for(auto * observer : _observers){
        observer->update();
    }
}


#endif // OBSERVABLE_H
