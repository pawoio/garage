

#pragma once
#include <memory>
#include "vehicle.h"

using std::unique_ptr;

class Observer
{
    public:
        Observer(){};
        virtual bool notify(unique_ptr<Vehicle> vhl){};
        virtual ~Observer(){};
    protected:
    private:
};

