#include <iostream>
#include "interface.h"

using namespace std;

int main()
{
    Garage garage;
    Interface interface(garage);
    interface.start();
    return 0;
}
