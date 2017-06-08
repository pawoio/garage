

#pragma once
#include <memory>
#include "vehicle.h"

using std::unique_ptr;

class Observer
{
    public:
        Observer(){};
        virtual bool notify(Vehicle& vhl){return true;};

        virtual ~Observer(){};
    protected:
    private:
};

