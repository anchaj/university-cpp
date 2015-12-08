#ifndef Polka_h
#define Polka_h
#include <stdlib.h>
#include <string>
#include "Przedmiot.h"

class Polka {
public:
   Polka(int ,int );
   void addItem(Przedmiot*);
   Przedmiot ** tab;
   int ilosc;
private:
   int width,load,max_load,max_width;

};


#endif
