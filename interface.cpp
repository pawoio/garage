#include "interface.h"
#include <string>
#include <limits>
#include <time.h>

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);

/*Interface::Interface(Garage grg)
{
    Garage* garagePtr= grg;
}*/

Interface::~Interface()
{
    //dtor
}
void Interface::cleanBufor()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char Interface::getOneChar()
{

    std::string input;

    while(true)
    {
        std::cout<<"Insert one letter:\n";
        std::cin>>input;

        if (std::cin.fail())
        {

            cleanBufor();
            continue;
        }
        if (input.length() != 1)
        {

            cleanBufor();
            continue;
        }
       cleanBufor();
        break;

    }
    return input[0];

}

size_t Interface::getDigit(size_t maxi)
{
    size_t i;
    while(true)
    {
        std::cin>>i;
        if(std::cin.fail())
        {
            cleanBufor();
            std::cout<<"Write number \n";
            continue;
        }else if(i>maxi||i<=0)
            {
                std::cout<<"Write positive number and less or even then "<<maxi<<std::endl;
               cleanBufor();
                continue;
            }else
            cleanBufor();
            return i;

    }
}

std::string Interface::getString()
{

    std::string s;
    while(!(std::cin>>s))
    {
        cleanBufor();
    }
    cleanBufor();
    return s;
}



void Interface::start()
{

    char ch;
    while((ch=firstMenu())!='q')
    {

        switch(ch)
        {
            case 'a': Interface::addVehicle();
            break;
            case 'b': Interface::removeVehicle();
            break;
            case 'c': Interface::borrowVehicle();
            break;
            case 'd': Interface::returnVehicle();
            break;
            case 'e': Interface::writeObjects();
            break;
            case 'f': Interface::readObjects();
            break;
            case 'g':
            {
                if(garagePtr.baseSize()==0)
                    std::cout<<"No vehicle in base\n";
                else
                    garagePtr.viewVehicles();
            }
            break;
            default : std::cout<<"Menu error\n";
        }
    }



}

char Interface::firstMenu()
{
    std::cin.clear();

    char ch;
    std::cout<<"Choose what to do:\n"
             <<"a.Add vehicle          b.Delete vehicle\n"
             <<"c.Borrow vehicle       d.Return vehicle\n"
             <<"e.Write down vehicles  f.Read vehicles from file\n"
             <<"g.View garage          q.Quit\n";

    while(ch=getOneChar())
    {

        if(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'&&ch!='e'&&ch!='f'&&ch!='g'&&ch!='q')
        {
            std::cout<<"Put a,b,c,d,e,f,g or q\n";

                continue;
        }else if(ch==EOF)
        {

                ch='q';
            return ch;
        }return ch;

    }
}

void Interface::addVehicle()
{
    char ch;
    while(ch=vehicleMenu())

        switch(ch)
        {
            case 'a': Interface::createMotor();
            return;
            case 'b': Interface::createCar();
            return;
            case 'c': Interface::createTruck();
            return;
        }
}

char Interface::vehicleMenu()
{
    std::cout<<"Choose vehicle type:\n"
                 <<"a.Motorcycle      b.Car\n"
                 <<"c.Truck"<<std::endl;
        while(true)
        {
            char ch=getOneChar();
            if(ch!='a'&&ch!='b'&&ch!='c')
            {
                std::cout<<"Put a,b or c\n";
                continue;
            }else
                return ch;

        }

}

void Interface::createMotor()
{
    std::cout<<"Write motor license number: \n";
    std::string licenseNr;
    while(true)
    {
        licenseNr=getString();
        if(!garagePtr.ifRepeat(licenseNr))
            break;
        std::cout<<"You have vehicle with the same license number. Write sth else\n";
    }
    std::cout<<"Write year of production: \n";
    size_t year = aTime->tm_year + 1900;
    size_t productionYear=getDigit(year);
    std::cout<<"Write engine power: \n";
    size_t enginePower=getDigit(std::numeric_limits<std::size_t>::max());
    garagePtr.addVehicle(unique_ptr<Vehicle> (new Motorcycle(licenseNr,productionYear,enginePower)));

}

void Interface::createCar()
{
    std::cout<<"Write Car license number: \n";
    std::string licenseNr;
    while(true)
    {
        licenseNr=getString();
        if(!garagePtr.ifRepeat(licenseNr))
            break;
        std::cout<<"You have vehicle with the same license number. Write sth else\n";
    }
    std::cout<<"Write year of production: \n";
    size_t year = aTime->tm_year + 1900;
    size_t productionYear=getDigit(year);
    std::cout<<"Write engine power: \n";
    size_t enginePower=getDigit(std::numeric_limits<std::size_t>::max());
    std::cout<<"Write door number: \n";
    size_t doorNumber=getDigit(10);
    garagePtr.addVehicle(unique_ptr<Vehicle> (new Car(licenseNr,productionYear,enginePower,doorNumber)));
}
void Interface::createTruck()
{
    std::cout<<"Write truck license number: \n";
    std::string licenseNr;
    while(true)
    {
        licenseNr=getString();
        if(!garagePtr.ifRepeat(licenseNr))
            break;
        std::cout<<"You have vehicle with the same license number. Write sth else\n";
    }
    std::cout<<"Write year of production: \n";
    size_t year = aTime->tm_year + 1900;
    size_t productionYear=getDigit(year);
    std::cout<<"Write engine power: \n";
    size_t enginePower=getDigit(std::numeric_limits<std::size_t>::max());
    std::cout<<"Write wheel number: \n";
    size_t wheelNr_=getDigit(100);
    garagePtr.addVehicle(unique_ptr<Vehicle> (new Truck(licenseNr,productionYear,enginePower,wheelNr_)));
}


bool Interface::removeVehicle()
{
    if(garagePtr.baseSize()==0)
    {
        std::cout<<"No vehicles in base"<<std::endl;
        return false;
    }
    garagePtr.viewVehicles();
    std::cout<<"\nChoose vechicle to remove <write numer>:"<<std::endl;
    size_t n;
    n=getDigit(garagePtr.baseSize());
    return garagePtr.removeVehicle(n-1);
}
bool Interface::borrowVehicle()
{
    if(garagePtr.baseSize()==0)
    {
        std::cout<<"No vehicles in base"<<std::endl;
        return false;
    }
    garagePtr.viewVehicles();
    std::cout<<"Choose vechicle to  lend <write numer>: "<<std::endl;
    size_t n;
    n=getDigit(garagePtr.baseSize());
    if(!garagePtr.lendVehicle(n-1))
        {
            std::cout<<"You cannot lend this vehicle"<<std::endl;
            return false;
        }else

    return true;
}

bool Interface::returnVehicle()
{
    if(garagePtr.baseSize()==0)
    {
        std::cout<<"No vehicles in base"<<std::endl;
        return false;
    }

    garagePtr.viewVehicles();
    std::cout<<"Choose vechicle to  return <write numer>: "<<std::endl;
    size_t n;
    n=getDigit(garagePtr.baseSize());
    if(!garagePtr.returnVehicle(n-1))
        {
            std::cout<<"You cannot return this vehicle"<<std::endl;
            return false;
        }
    return true;
}

bool Interface::writeObjects()
{
    if(garagePtr.baseSize()==0)
        {
            std::cout<<"No vehicles in base"<<std::endl;
            return false;
        }

    std::cout<<"Write name of file to write into:"<<std::endl;
    std::string s=getString();
    if(!garagePtr.writeObjects(s))
    {
        std::cout<<"fail with base saving"<<std::endl;
        return false;
    }
    return true;
}

bool Interface::readObjects()
{
    std::cout<<"Write name of file to load:"<<std::endl;
    std::string s=getString();
    if(!garagePtr.readObjects(s))
    {
        std::cout<<"fail with base saving"<<std::endl;
        return false;
    }
    return true;
}



