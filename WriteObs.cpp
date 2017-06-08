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


bool WriteObs::notify(Vehicle& vhl)

{
    std::ofstream fout("lendHistory.txt", std::ios_base::out|std::ios_base::app);
    time_t theTime = time(NULL);
    struct tm * ptr=localtime(&theTime);
    if(!fout)
        return false;
    if(vhl.isAvailable())
    {
        fout<< asctime( ptr )<<"Vehicle "<<vhl.getLicenseNr()<<" lent\n";
    }else
        fout<< asctime( ptr )<<"Vehicle "<<vhl.getLicenseNr()<<" returned\n";
   fout.close();
   if(!fout)
        return false;
    else
        return true;
}
