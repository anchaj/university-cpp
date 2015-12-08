//Mateusz Jachna
#ifndef Source_cpp
#define Source_cpp

#include "Piekarz.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
class Konkurs{
   enum State{niezdecydowany=0,przypisany,wykluczony};

   class Graf{
   public:
   Piekarz *p;
   State stan;
   short  id_up,
          *id_down,
          down_long;
   Graf():
      down_long(0),
      id_up(0),
      stan(niezdecydowany){
      id_down=(short*)malloc(2);
      id_down[0]=0;
   }
   ~Graf() {
      free(id_down);
      down_long=0;
   }
};
public:
   Graf tab[101];
   short ile;
   Konkurs(): ile(0){}
   ~Konkurs(){}
   bool dolacz(Piekarz* p1,Piekarz* p2)
   {
      if(ile>100) return 0;
      if(tab[p1->id].stan != niezdecydowany) return 0;
      if(p2==0){
         tab[ile+1].p=p1;
         tab[ile+1].p->id=ile+1;
         ile++;
         return 1;
      }  else{
         if(p2->id==0 and tab[p2->id].stan == niezdecydowany) {
            tab[ile+1].stan = przypisany;
            tab[ile+1].p=p1;
            tab[ile+1].p->id=ile+1;
            ile++;
            tab[ile+1].p=p2;
            tab[ile+1].p->id=ile+1;
            ile++;
            tab[p1->id].id_up=tab[p2->id].p->id;
            tab[p2->id].down_long++;
            tab[p2->id].id_down=(short*)realloc(tab[p2->id].id_down,
                                                2*(tab[p2->id].down_long));
            tab[p2->id].id_down[0]=p1->id;
         }  else{
            tab[ile+1].stan = przypisany;
            tab[ile+1].p=p1;
            tab[ile+1].p->id=ile+1;
            ile++;
            tab[p1->id].id_up=tab[p2->id].p->id;
            tab[p2->id].down_long++;
            tab[p2->id].id_down=(short*)realloc(tab[p2->id].id_down,
                                                2*(tab[p2->id].down_long));
            tab[p2->id].id_down[tab[p2->id].down_long-1]=p1->id;
         }
         aktualizuj(p1->id,p1->id);
         return 1;
      }

   }
   bool sympatyzuj (Piekarz* p1,Piekarz* p2)
   {
      if(p2->id==0 or p1->id==0) return 0;
      if(tab[p1->id].stan!= niezdecydowany) return 0;
      else {
         tab[p1->id].id_up=tab[p2->id].p->id;
         tab[p2->id].down_long++;
         tab[p2->id].id_down=(short*)realloc(tab[p2->id].id_down,
                                             2*(tab[p2->id].down_long));
         tab[p2->id].id_down[tab[p2->id].down_long-1]=p1->id;
      }
   }
   void wypisz(Piekarz* p1){
      wypisz(p1->id);
   }
   void wypisz(int id){
      if(id!=0 and tab[id].stan!=wykluczony and id<=ile){
           cout<<tab[id].p->id<<" "<<tab[id].p->punkty<<endl;
           for(int i=0;i<tab[id].down_long;i++){
               if(tab[tab[id].id_down[i]].stan!=wykluczony)wypisz(tab[id].id_down[i]);
           }
      }
}
   void punkty(Piekarz* p)
   {
      if(p->id != 0)
         cout<<p->id<<" "<<p->punkty<<endl;
      else cout<<"brak\n";
   }
   void punkty(int id)
   {
      if(tab[id].p->id != 0 and id<=ile)
         cout<<tab[id].p->id<<" "<<tab[id].p->punkty<<endl;
      else cout<<"brak\n";
   }
   void wyklucz(Piekarz* p1)
   {
      if(p1->id!=0)
      {
         p1->punkty=0;
         tab[p1->id].id_up=0;
         tab[p1->id].stan=wykluczony;
         wykluczanie(p1->id);
         ///p1->id=0; powoduje blad!! a powinno tak byc :D
      }
   }
   void wykluczanie(int id)
   {
      if(tab[id].down_long!=0) {
         tab[id].id_up=0;
         tab[id].stan = niezdecydowany;
         for(int i=tab[id].down_long-1;i>=0;i--){
            wykluczanie(tab[id].id_down[i]);
            if(i==0){
                  free(tab[id].id_down);
                  tab[id].down_long=0;
            }
         }

      }
   }
   Piekarz* zwyciezca()
   {
      short id=1;
      for(int i=1;i<=ile;i++)
         if(tab[id].p->punkty<tab[i].p->punkty)id=i;
      cout<<tab[id].p->id<<" "<<tab[id].p->punkty<<endl;
      return tab[id].p;
   }

   void wypisz()
   {
      cout<<"ilosc piekarzy to: "<<ile<<endl;
      for(int i=1;i<=ile;i++)
      {
         cout<<tab[i].p->id<<" "<<tab[i].p->punkty<<" [ "
             <<tab[i].id_up<<" ][ "<<tab[i].down_long<<": ";
         for(int j=0;j<tab[i].down_long;j++)
            cout<<tab[i].id_down[j]<<" ";

         cout<<"]\n";
      }
   }
   void aktualizuj(int id,const int start,int n=0)
   {
      if(id!=start)
      {
         if(tab[id].stan != wykluczony) tab[id].p->punkty+=pow(2,-n);

         if(tab[id].id_up!=0) aktualizuj(tab[id].id_up,start,n+1);
      }
      else aktualizuj(tab[id].id_up,start,0);
   }
};
#endif // Source_cpp
