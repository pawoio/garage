#include <iostream>
#include "interface.h"

using namespace std;

int main()
{
    Garage garage;
    unique_ptr<Observer> nrObs(new NrObs);
    unique_ptr<Observer> wrObs(new WriteObs);
    garage.addObs(move(nrObs));
    garage.addObs(move(wrObs));
    Interface interface(garage);
    interface.start();
    return 0;
}
