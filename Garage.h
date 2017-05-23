#ifndef GARAGE_H
#define GARAGE_H

#include "vehicle.h"
#include "motorcycle.h"
#include "Car.h"

#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;
class Garage
{
    public:

        explicit Garage(vector<unique_ptr<Vehicle>>);
        virtual ~Garage();
        void addVehicle(unique_ptr<Vehicle>);
        bool removeVehicle(unique_ptr<Vehicle>);
        bool lendVehicle(unique_ptr<Vehicle>);
        bool returnVehicle(unique_ptr<Vehicle>);
    protected:
    private:
        vector<unique_ptr<Vehicle>> vehicleBase;



};

#endif // GARAGE_H
