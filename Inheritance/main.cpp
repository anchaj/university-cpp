#include <iostream>
#include <stdlib.h>
#include "tablica_double.h"
#include "przedmiot.h"
#include "ksiazka.h"
#include "polka.h"
using namespace std;
class Plyta : Przedmiot{
public:
   Plyta() : Przedmiot()
   {
      cout<<"i konsturktor plyty\n";
   }
   virtual void wypisz_typ() = 0;

};
class CD : Plyta {
public:
   virtual void wypisz_typ()
   {
      cout<<"Plyta CD\n";
   }
};
class DVD : Plyta{
public:
   DVD() : Plyta()
   {

   }
   virtual void wypisz_typ()
   {
      cout<<"Plyta DVD\n";
   }
};
int main()
{
   DVD b;
}
