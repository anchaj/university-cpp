//Mateusz Jachna
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class MayCal{
protected:
   double liczba;
public:
   MayCal()
   {
      liczba=0.0;
   }
   MayCal(double l)
   {
      liczba=l;
      checkDate(*this);
   }
   friend ostream& operator<<(ostream&,const MayCal&);
   friend istream& operator>>(istream&,MayCal&);

   friend void checkDate(MayCal&);
};

ostream& operator<<(ostream& wyjscie,const MayCal &m)
{
    wyjscie<<m.liczba;
    return wyjscie;
}
istream& operator>>(istream &wejscie,MayCal &m){
   wejscie>>m.liczba;
   checkDate(m);
   return wejscie;
}
void checkDate(MayCal &n)
{
      if(n.liczba<-3114)
      {
         n.liczba = -3114;
         cout<<"Time error!";
      }
      else if(n.liczba>2012)
      {
         n.liczba=2012;
         cout<<"Time error!";
      }
}

