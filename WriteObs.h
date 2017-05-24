#ifndef WRITEOBS_H
#define WRITEOBS_H

#include "Observer.h"


class WriteObs : public Observer
{
    public:
        WriteObs();
        bool virtual notify(unique_ptr<Vehicle> vhl);
        virtual ~WriteObs();
    protected:
    private:
};

#endif // WRITEOBS_H
