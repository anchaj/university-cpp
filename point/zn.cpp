#include "zn.h"
using namespace std;

Zn::Zn(int a, int n) : liczba(a%n), n(n){}

int Zn::getN() const{
   return n;
}
int Zn::getLiczba()  const{
   return liczba;
}
const Zn& operator++(Zn& p){
   p.liczba++;
   if(p.liczba==p.n) p.liczba=0;
   return p;
}
const Zn& operator++(Zn& p,int){
   Zn nowy(p.liczba,p.n);
   p.liczba++;
   if(p.liczba==p.n) p.liczba=0;
   return nowy;
}
Zn operator+(const Zn &p1,const Zn &p2){
   return Zn(p1.getLiczba() + p2.getLiczba(), p1.getN());
}
