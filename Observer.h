#ifndef OBSERVER_H
#define OBSERVER_H

#include "Garage.h"

class Observer
{
    public:
        Observer();
        bool virtual notify(unique_ptr<Vehicle> vhl)=0;
        virtual ~Observer();
    protected:
    private:
};

#endif // OBSERVER_H
