//Mateusz Jachna
#ifndef ROZ_CZARNAMROWKA
#define ROZ_CZARNAMROWKA

#include <iostream>
#include "CzarnaMrowka.h"

using namespace std;

class RozszerzonaCzarnaMrowka: public CzarnaMrowka{
	public:
	   int uciekaj()
	   {
	      return CzarnaMrowka::uciekaj()+1;
	   }
	   int jedz(char * pokarm)
		{
		    cout<<"Jem w zasiegu mrowiska!"<<endl;
		    return CzarnaMrowka::jedz(pokarm);
		}
};

#endif

