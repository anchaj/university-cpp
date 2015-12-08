#include "Polka.h"
#include "Przedmiot.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

   Polka::Polka(int max_width,int max_load)
   : max_width(max_width), max_load(max_load), load(0), width(0),ilosc(0)
   {
      cout<<"Konstruktor polki o szerokosci "<<max_width <<" i maksymalnym obciazeniu " << max_load<<endl;
      tab = (Przedmiot**)malloc(0) ;
   }
   void Polka::addItem(Przedmiot* item)
   {
      if (load+item->load<max_load and width+item->width<max_width)
      {
         cout<<"Pomyslnie dodano element na polke\n";
         tab[ilosc]=item;
         ilosc++;
         tab = (Przedmiot**)realloc(tab,ilosc*sizeof(Przedmiot*));
      }
      else {
         if(load+item->load>max_load) cout<<"Blad polka jest zbytnio obciazona\n";
         if(width+item->width>max_width) cout<<"Blad brak miejsca na polce\n";
      }
      load += item->load;
      width += item->width;
   }
