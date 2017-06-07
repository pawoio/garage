#ifndef INTERFACE_H
#define INTERFACE_H

#include "Garage.h"

class Interface
{
    public:
        Interface(Garage& garage_):garagePtr(garage_) {};
        virtual ~Interface();
        void start();

    protected:
    private:
    Garage& garagePtr;

    void createMotor();
    void createCar();
    void createTruck();

    std::string getString ();
    size_t getDigit(size_t maxi);
    char getOneChar();
    void cleanBufor();
    //void construct();
    void addVehicle();
    bool removeVehicle();
    bool borrowVehicle();
    bool returnVehicle();
    bool writeObjects();
    bool readObjects();
    char firstMenu();
    char vehicleMenu();

};

#endif // INTERFACE_H
