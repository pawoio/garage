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
        bool lendVehicle(size_t i);
        bool returnVehicle(size_t i);
        bool writeObjects(std::string);
        bool readObjects(std::string);
        size_t baseSize();

        void viewVehicles();
        bool ifRepeat(std::string str);

        void addObs(unique_ptr<Observer> );
    protected:
    private:
        vector<unique_ptr<Observer>> observerCollection;
        vector<unique_ptr<Vehicle>> vehicleBase;




};

#endif // GARAGE_H
