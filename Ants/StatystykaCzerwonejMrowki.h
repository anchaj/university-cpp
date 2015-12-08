//Mateusz Jachna
#ifndef S_CZERWONAMROWKA
#define S_CZERWONAMROWKA

#include <iostream>
#include "CzerwonaMrowka.h"

using namespace std;

class StatystykaCzerwonejMrowki: public CzerwonaMrowka{
	public:
        int pobierzIloscWalk()
        {
            return CzerwonaMrowka::ilosc_walk - CzerwonaMrowka::ilosc_walk_agresywne;
        }
        int pobierzSumarycznaIloscWalk()
        {
            return CzerwonaMrowka::ilosc_walk_agresywne;
        }
};

int CzerwonaMrowka::ilosc_walk=0;
int CzerwonaMrowka::ilosc_walk_agresywne=0;
#endif

