#include "vehicle.h"


/*Vehicle::Vehicle(const std::string licNr ("brak"), size_t prodYear=0, double engPow=0, bool avail=true)
{
    licenseNr=licNr;
    productionYear=prodYear;
    enginePower=engPow;
     available=avail;

}*/

Vehicle::~Vehicle()
{

}

void Vehicle::setAvailable(bool avl)
{
    if(available==avl)
    return;
    else (available=true? false:true);
}

void Vehicle::setEnginePower(double ep)
{
    if(ep>=0)
        enginePower=ep;
    return;
}


void Vehicle::setProductionYear(size_t y)
{
    productionYear=y;
    return;
}

void Vehicle::setLicenseNr(std::string s)
{
    licenseNr=s;
    return;

}






