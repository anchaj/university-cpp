//Mateusz Jachna
#ifndef ROBOTNICA
#define ROBOTNICA

#include <iostream>
#include <string.h>
#include "RozszerzonaCzarnaMrowka.h"

using namespace std;

class Robotnica: public RozszerzonaCzarnaMrowka{
	public:
	   int walcz(){
         return RozszerzonaCzarnaMrowka::uciekaj();
	   }
	   int idz(char * cel)
	   {
	      if(strcmp(cel,"mrowisko")!=0) return -1;
	      return RozszerzonaCzarnaMrowka::idz("mrowisko");
	   }
};

#endif


