#include "Garage.h"

Garage::Garage(vector<unique_ptr<Vehicle>>  vhlBase)
{
    vehicleBase=std::move(vhlBase);
    WriteObs writeObs;
    NrObs nrObs;
    observerCollection.push_back(writeObs);
    observerCollection.push_back(nrObs);
}

Garage::~Garage()
{
    //dtor
}

void Garage::addVehicle(unique_ptr<Vehicle> vhl)
{
    vehicleBase.push_back(move(vhl));
}

bool Garage::removeVehicle(size_t i)
{

    if(vehicleBase.size()<i)
        return false;
    else vehicleBase.erase(vehicleBase.begin()+i);
        return true;

}

bool Garage::lendVehicle(int i)
{
    if(vehicleBase.begin()[i]->isAvailable()==true)
    {
        vehicleBase.begin()[i]->setAvailable(false);
        return true;
    }else
        return false;

}

bool Garage::returnVehicle(int i)
{

    if(vehicleBase.begin()[i]->isAvailable()==false)
        {
            vehicleBase.begin()[i]->setAvailable(true);
            return true;
        }else
            return false;
}

bool writeObjects(std::string filename)
{

}







