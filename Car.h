#ifndef CAR_H
#define CAR_H

#include "vehicle.h"


class Car : public Vehicle
{
    public:
        Car(const std::string ln="none",size_t prodYear=0,double engPow=0,size_t dNr=5,bool avail=true):Vehicle(ln,prodYear,engPow,avail),doorNr(dNr){};
        virtual ~Car(){};
        size_t getDoorNr(){return doorNr;};
        virtual char vehicleType(){return 'c';};
        virtual size_t viewAdditionalInfo(){return getDoorNr();};

        //void setDoorNr();
    protected:
    private:
        size_t doorNr;

};

#endif // CAR_H
