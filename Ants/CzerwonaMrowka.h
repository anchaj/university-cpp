//Mateusz Jachna
#ifndef CZERWONAMROWKA
#define CZERWONAMROWKA

#include <iostream>
#include "Mrowka.h"

using namespace std;

class CzerwonaMrowka: public Mrowka{
	public:
	   static int ilosc_walk,ilosc_walk_agresywne;
	   int walcz()
	   {
	      ilosc_walk++;
	      int wynik = Mrowka::walcz();
	      if(wynik<0)
            Mrowka::odejmijPewnosci();
         return wynik;
	   }
};

#endif

