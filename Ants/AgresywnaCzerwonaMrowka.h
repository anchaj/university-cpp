//Mateusz Jachna
#ifndef A_CZERWONAMROWKA
#define A_CZERWONAMROWKA

#include <iostream>
#include "CzerwonaMrowka.h"

using namespace std;

class AgresywnaCzerwonaMrowka: public CzerwonaMrowka{
	public:
		int walcz()
		{
		   ilosc_walk_agresywne++;
		   int wynik = CzerwonaMrowka::walcz();
		   if(wynik>0){
            CzerwonaMrowka::jedz("mrowka");
            CzerwonaMrowka::dodajPewnosci();
		   }
		   return wynik;
		}
};

#endif


