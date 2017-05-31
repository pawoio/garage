#include "Garage.h"

Garage::Garage(vector<unique_ptr<Vehicle>>  vhlBase)
{
    vehicleBase=std::move(vhlBase);
    WriteObs writeObs;
    NrObs nrObs;
    observerCollection.push_back(unique_ptr<Observer> (new WriteObs));
    observerCollection.push_back(unique_ptr<Observer> (new NrObs));
}
Garage::Garage()
{
    WriteObs writeObs;
    NrObs nrObs;
    observerCollection.push_back(unique_ptr<Observer> (new WriteObs));
    observerCollection.push_back(unique_ptr<Observer> (new NrObs));
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

bool Garage::writeObjects(std::string filename)
{
    std::ofstream fout(filename, std::ios_base::out|std::ios_base::binary);
    for(size_t i=0;i<baseSize();i++)
    {
        char typ = vehicleBase[i]->vehicleType();
        fout.write(reinterpret_cast<const char*>( &typ ), sizeof(char));
        fout.write( vehicleBase.begin()[i]->getLicenseNr().c_str(), vehicleBase.begin()[i]->getLicenseNr().size() + 1 );
        size_t prodYear=vehicleBase.begin()[i]->getProductionYear();
        fout.write(reinterpret_cast<const char*>(&prodYear), sizeof(size_t));
        size_t engine=vehicleBase.begin()[i]->getEnginePower();
        fout.write(reinterpret_cast<const char*>(&engine), sizeof(size_t));
        size_t addInf=vehicleBase.begin()[i]->viewAdditionalInfo();
        fout.write(reinterpret_cast<const char*>(&addInf), sizeof(vehicleBase.begin()[i]->viewAdditionalInfo()));


    }
    fout.close();
    return true;

}

size_t Garage::baseSize()
{
    return vehicleBase.size();
}

void Garage::viewVehicles()
{
    for(size_t i=0;i<baseSize();i++)
    {
        std::cout<<i+1<<"# \n "<<"\t license number: "<<vehicleBase.begin()[i]->getLicenseNr()<<"\n\t production year: "
                <<vehicleBase.begin()[i]->getProductionYear()<<"\n\t enigine power: "<< vehicleBase.begin()[i]->getEnginePower();
        if(vehicleBase.begin()[i]->vehicleType()=='c')
        {
            std::cout<<"\n\t door number: "<< vehicleBase.begin()[i]->viewAdditionalInfo()<<std::endl;
        }else if(vehicleBase.begin()[i]->vehicleType()=='t')
        {
            std::cout<<"\n\t wheel number: "<< vehicleBase.begin()[i]->viewAdditionalInfo()<<std::endl;
        }
        if(vehicleBase.begin()[i]->isAvailable())
            std::cout<<"\n\t Available\n";
        else
            std::cout<<"\n\t Not available\n";

    }
}

bool Garage::readObjects(std::string fileName)
{
    std::ifstream fin(fileName,std::ios_base::in|std::ios_base::binary);
    char q;
    while(fin>>q)
    {
        std::string str;
        getline( fin, str, '\0' );
        size_t prodYear;
        fin.read(reinterpret_cast<char*>(&prodYear), sizeof(size_t));
        size_t engine;
        fin.read(reinterpret_cast<char*>(&engine), sizeof(size_t));
        size_t addInf;
        fin.read(reinterpret_cast<char*>(&addInf), sizeof(size_t));
        if(q=='c')
            addVehicle(unique_ptr<Vehicle> (new Car(str,prodYear,engine,addInf)));
        else if(q=='m')
            addVehicle(unique_ptr<Vehicle> (new Motorcycle(str,prodYear,engine)));
        else if(q=='t')
            addVehicle(unique_ptr<Vehicle> (new Truck(str,prodYear,engine,addInf)));
        return true;
    }
    fin.close();
    return true;
}




