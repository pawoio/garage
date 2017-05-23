#ifndef WRITEOBS_H
#define WRITEOBS_H

#include <Observer.h>


class WriteObs : public Observer
{
    public:
        WriteObs();
        void virtual notify();
        virtual ~WriteObs();
    protected:
    private:
};

#endif // WRITEOBS_H
