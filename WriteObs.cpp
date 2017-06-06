#include "WriteObs.h"
#include <time.h>
#include <fstream>

WriteObs::WriteObs()
{
    //ctor
}

WriteObs::~WriteObs()
{
    //dtor
}

bool WriteObs::notify(Vehicle*& vhl)
{
    std::ofstream fout("lendHistory.txt", std::ios_base::out|std::ios_base::app);
    struct tm * ptr;
    if(!fout)
        return false;
    if(vhl->isAvailable())
    {
        fout<< asctime( ptr )<<"Vehicle"<<vhl->getLicenseNr()<<"return/n";
    }else
        fout<< asctime( ptr )<<"Vehicle"<<vhl->getLicenseNr()<<"lend/n";
   fout.close();
   if(!fout)
        return false;
    else
        return true;
}
