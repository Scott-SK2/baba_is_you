#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public :

    /**
     * @brief update This method is called whenever the observed object is changed.
     */
    virtual void update() = 0;
};

#endif // OBSERVER_H
