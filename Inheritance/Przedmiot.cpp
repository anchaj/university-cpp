#include "Przedmiot.h"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
   Przedmiot::Przedmiot()
   {
      cout<<"Kontruktor b.arg przedmiot\n";
   }
   Przedmiot::Przedmiot(string name):
      name(name)
   {
      cout<<"Kontruktor string przedmiot\n";
   }
   void Przedmiot::setName(string name)
   {
      this->name=name;
   }
   string Przedmiot::getName()
   {
      return name;
   }
   void Przedmiot::setWeight(int load)
   {
      this->load=load;
   }
   int Przedmiot::getWeight()
   {
      return load;
   }
   void Przedmiot::setWidth(int width)
   {
      this->width=width;
   }
   int Przedmiot::getWidth()
   {
      return width;
   }
