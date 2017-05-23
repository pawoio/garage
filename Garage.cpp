#include "Garage.h"

Garage::Garage(vector<unique_ptr<Vehicle>>  vhlBase)
{
    vehicleBase=std::move(vhlBase);
}

Garage::~Garage()
{
    //dtor
}

void Garage::addVehicle(unique_ptr<Vehicle> vhl)
{
    vehicleBase.push_back(vhl);
}

bool Garage::removeVehicle(unique_ptr<Vehicle> vhl)
{

    if(std::find(vehicleBase.begin(),vehicleBase.end(),vhl)==vehicleBase.end())
        return false;
    else vector<unique_ptr<Vehicle>>::erase(std::find(vehicleBase.begin(),vehicleBase.end(),vhl));
        return true;

}

bool Garage::lendVehicle(unique_ptr<Vehicle> vhl)
{
        if(vhl->isAvailable()==true)
        {
            vhl->setAvailable(false);
            return true;
        }else
            return false;

}

bool Garage::returnVehicle(unique_ptr<Vehicle> vhl)
{
    if(vhl->isAvailable()==false)
        {
            vhl->setAvailable(true);
            return true;
        }else
            return false;
}








