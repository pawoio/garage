#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
    public:
        Truck(const std::string& ln="none",size_t prodYear=0,double engPow=0,size_t whNr=8,bool avail=true):Vehicle(ln,prodYear,engPow,avail),wheelNr(whNr){};
        virtual ~Truck();
        char vehicleType(){return 't';};
        size_t getWheelNr(){return wheelNr;};
        virtual size_t viewAdditionalInfo();

    protected:
    private:
    size_t wheelNr;
};

#endif // TRUCK_H
