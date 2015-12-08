//Mateusz Jachna
#ifndef L_CZERWONAMROWKA
#define L_CZERWONAMROWKA

#include <iostream>
#include "CzerwonaMrowka.h"

using namespace std;

class LatajacaCzerwonaMrowka: public CzerwonaMrowka{
	public:
	   int idz(char * cel){
	      return CzerwonaMrowka::lec(cel);
	   }
};

#endif



