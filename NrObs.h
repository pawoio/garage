#ifndef NROBS_H
#define NROBS_H

#include "Observer.h"
#include <stddef.h>


class NrObs : public Observer
{
    public:
        NrObs();
        virtual bool  notify(Vehicle& vhl);
        virtual ~NrObs();
    protected:
    private:
    size_t lentNr;
    enum{maxLent=2};

};

#endif // NROBS_H
