#include "Ksiazka.h"

#include <iostream>
using namespace std;

   Ksiazka::Ksiazka() : Przedmiot()
   {
      cout<<"i konstruktor b.arg ksiazki\n";
   }
   Ksiazka::Ksiazka(string name) : Przedmiot(name)
   {
      cout<<"i konstruktor string ksiazki o nazwie "<<name <<endl;
   }
