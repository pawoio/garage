#include "NrObs.h"

NrObs::NrObs()
{
    //ctor
}

NrObs::~NrObs()
{
    //dtor
}

bool NrObs::notify()
{
    if(lentNr<100)
    {
        lentNr++;
        return true;
    }
    else
        return false;
}
