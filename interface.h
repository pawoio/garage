#ifndef INTERFACE_H
#define INTERFACE_H

#include "interface.h"

class Interface
{
    public:
        Interface(Garage);
        virtual ~Interface();
        void start();

    protected:
    private:
    Garage* garagePtr;
    void construct();
    void addVehicle();
    bool removeVehicle();
    bool lendVehicle();
    bool returnVehicle();
    bool writeObjects();
    bool readObjects();
    char menu();

};

#endif // INTERFACE_H
