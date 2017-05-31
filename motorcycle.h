#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"


class Motorcycle : public Vehicle
{
    public:
        Motorcycle(const std::string& ln="none",size_t prodYear=0,size_t engPow=0,bool avail=true):Vehicle(ln,prodYear,engPow,avail){};
        virtual ~Motorcycle();
        virtual char vehicleType(){return 'm';};
        virtual size_t viewAdditionalInfo();

    protected:
    private:

};

#endif // MOTORCYCLE_H
