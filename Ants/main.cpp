#include <iostream>

#include "Mrowka.h"
#include "CzarnaMrowka.h"
#include "RozszerzonaCzarnaMrowka.h"
#include "CzerwonaMrowka.h"
#include "AgresywnaCzerwonaMrowka.h"
#include "LatajacaCzerwonaMrowka.h"
#include "Robotnica.h"
#include "Zolnierz.h"
#include "StatystykaCzerwonejMrowki.h"

using namespace std;

int main()
{
   RozszerzonaCzarnaMrowka m1;
   CzarnaMrowka m2;
   Mrowka m0;
   CzerwonaMrowka m3;
   AgresywnaCzerwonaMrowka m4;
   LatajacaCzerwonaMrowka m5;
   Robotnica m6;
   Zolnierz m7;


   m1.uciekaj();

    return 0;
}
