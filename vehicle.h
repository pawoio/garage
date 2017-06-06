#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>


class Vehicle
{
    public:
        //Vehicle(const std::string licNr("brak"), size_t prodYear=0, double engPow=0, bool avail=true);
        Vehicle(): licenseNr("none"), productionYear(0), enginePower(0), available(true){};
        Vehicle(const std::string& ln,size_t prodYear=0,size_t engPow=0,bool avail=true): licenseNr(ln),productionYear(prodYear),enginePower(engPow),available(avail){};
        virtual ~Vehicle();

        void setLicenseNr( std::string);
        void setProductionYear(size_t);
        void setEnginePower(size_t);
        void setAvailable(bool);

        const std::string& getLicenseNr()const {return licenseNr;};
        size_t getProductionYear(){return productionYear;};
        size_t getEnginePower(){return enginePower;};
        bool isAvailable(){return available;};
        virtual char vehicleType(){return 'v';};
        virtual  size_t viewAdditionalInfo(){return 0;};


    private:

        std::string licenseNr;
        size_t productionYear;
        size_t enginePower;
        bool available;
};

#endif // VEHICLE_H
