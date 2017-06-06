#include "NrObs.h"

NrObs::NrObs()
{
    //ctor
}

NrObs::~NrObs()
{
    //dtor
}

bool NrObs::notify(Vehicle*&  vhl)
{
    if(vhl->isAvailable())
    {
        if(lentNr<100)
        {
            lentNr++;
            return true;
        }else

        return false;
    }
    else
        return true;
}
