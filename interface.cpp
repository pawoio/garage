#include "interface.h"


Interface::Interface(Garage grg)
{
    Garage* garagePtr= grg;
}

Interface::~Interface()
{
    //dtor
}

void Interface::start()
{

    char ch;
    while((ch=menu())!=g)
    {
        switch(ch)
        case 'a':Interface::addVehicle();
        break;
        case'b':Interface::removeVehicle();
        break;
        case 'c':Interface::lendVehicle();
        break;
        case 'd':Interface::returnVehicle();
        break;
        case 'e':Interface::writeObjects();
        break;
        case 'f':Interface::readObjects();
        break;
        default:
        std::cout<<"Menu error\n";

    }



}

char Interface::menu()
{
    char ch;
    std::cout<<"Choose what to do:\n"
             <<"a.Add vehicle          b.Delete vehicle\n"
             <<"c.Borrow vehicle       d.Return vehicle\n"
             <<"e.Write down vehicles  f.Read vehicles from file\n"
             <<"q.Quit\n";

    while(std::cin>>ch)
    {
        if(ch!=a&&ch!=b&&ch!=c&&ch!=d&&ch!=e&&ch!=f&&ch!=q)
        {
            std::cout<<"Put a,b,c,d,e,f or q\n"
            while(std::cin.get()!='\n')
                continue;
        }else
        {
            while(std::cin.get()!='\n')
                continue;
            if(ch==EOF)
                ch='g';
            return ch;
        }

    }
}
void Interface::addVehicle()
{
    std::cout<<"Choose vehicle type:\n"
             <<"a.Motorcycle      b.Car\n"
             <<"c.Truck\n";

}
