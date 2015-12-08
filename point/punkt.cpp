#include "punkt.h"
using namespace std;

Punkt::Punkt(double newX, double newY):
   x(newX), y(newY){}
Punkt::Punkt():x(0),y(0){}
Punkt operator+(const Punkt& a, const Punkt& b)
{
     return Punkt(a.x+b.x,a.y+b.y);
}
Punkt operator-(const Punkt& a, const Punkt& b)
{
     return Punkt(a.x-b.x,a.y-b.y);
}
bool operator==(const Punkt& p1,const Punkt& p2){
   if (p1.x==p2.x and p1.y == p2.y)   return true;
   else return false;
}
bool operator!=(const Punkt& p1,const Punkt& p2){
   if (p1.x==p2.x and p1.y == p2.y)   return false;
   else return true;
}

bool operator<(const Punkt& p1,const Punkt& p2){
   if (p1.x<p2.x or (p1.x == p2.x and p1.y < p2.y))   return true;
   else return false;
}
bool operator>(const Punkt& p1,const Punkt& p2){
   if (p1.x>p2.x or (p1.x == p2.x and p1.y > p2.y))   return true;
   else return false;
}
bool operator<=(const Punkt& p1,const Punkt& p2){
   if (p1.x<=p2.x or p1.y <= p2.y) return true;
   else return false;
}
bool operator>=(const Punkt& p1,const Punkt& p2){
   if (p1.x>=p2.x or p1.y >= p2.y) return true;
   else return false;
}
ostream& operator<<(ostream& wypisz,Punkt const &p){
   wypisz <<"("<<p.x<<","<<p.y<<")";
   return wypisz;
}
