#ifndef NROBS_H
#define NROBS_H

#include "Observer.h"
#include <stddef.h>


class NrObs : public Observer
{
    public:
        NrObs();
        bool virtual notify(unique_ptr<Vehicle> vhl);
        virtual ~NrObs();
    protected:
    private:
    size_t lentNr;
    enum{N=100};

};

#endif // NROBS_H
