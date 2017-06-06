#ifndef GARAGE_H
#define GARAGE_H

#include "vehicle.h"
#include "motorcycle.h"
#include "Car.h"
#include "Truck.h"
#include "NrObs.h"
#include "WriteObs.h"
#include "Observer.h"

#include <vector>
#include <memory>
#include <fstream>


using std::vector;
using std::unique_ptr;
class Garage
{
    public:

        explicit Garage(vector<unique_ptr<Vehicle>>);
        Garage();
        virtual ~Garage();
        void addVehicle(unique_ptr<Vehicle>);
        bool removeVehicle(size_t i);
        bool lendVehicle(int i);
        bool returnVehicle(int i);
        bool writeObjects(std::string);
        bool readObjects(std::string);
        void viewVehicles();
        size_t baseSize();
        void addObs(unique_ptr<Observer> );
    protected:
    private:
        vector<unique_ptr<Observer>> observerCollection;
        vector<unique_ptr<Vehicle>> vehicleBase;
        bool ifRepeat(std::string str);




};

#endif // GARAGE_H
