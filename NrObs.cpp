#include "NrObs.h"



NrObs::NrObs()
{
    lentNr=0;
}

NrObs::~NrObs()
{
    //dtor
}

bool NrObs::notify(Vehicle& vhl)

{
    if(vhl.isAvailable())
    {
        if(lentNr<=maxLent)
        {
            lentNr++;
            return true;
        }else
        return false;

    }
    else
    {
        --lentNr;
        return true;
    }

}
