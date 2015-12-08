//Mateusz Jachna
#ifndef ZOLNIERZ
#define ZOLNIERZ

#include <iostream>
#include "RozszerzonaCzarnaMrowka.h"

using namespace std;

class Zolnierz: public RozszerzonaCzarnaMrowka{
	public:
		int uciekaj()
		{
		   if(RozszerzonaCzarnaMrowka::uciekaj()==0)
            return -1;
         else{
            cout<<"Za Krolowa\n";
            return RozszerzonaCzarnaMrowka::uciekaj();
         }
		}
};

#endif



