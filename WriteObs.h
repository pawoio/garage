#ifndef WRITEOBS_H
#define WRITEOBS_H

#include "Observer.h"
#include <memory>

class WriteObs: public Observer
{
    public:
        WriteObs();
         virtual bool notify(Vehicle& vhl);
        virtual ~WriteObs();
    protected:
    private:
};

#endif // WRITEOBS_H
