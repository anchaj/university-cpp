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
   MayCal& operator=(MayCal m)
   {
      liczba = m.liczba;
      checkDate(*this);
      return *this;
   }
   const MayCal& operator++(){
      liczba++;
      checkDate(*this);
      return *this;
   }
   const MayCal operator++(int){
      MayCal nowy(liczba);
      liczba++;
      checkDate(*this);
      return nowy;
   }
   const MayCal& operator--(){
      liczba--;
      checkDate(*this);
      return *this;
   }
   const MayCal operator--(int){
      MayCal nowy(liczba);
      liczba--;
      checkDate(*this);
      return nowy;
   }
   MayCal& operator-(){
      liczba = -liczba;
      checkDate(*this);
      return *this;
   }
   MayCal& operator+(){
      return *this;
   }
   MayCal operator[](MayCal y){
      MayCal r;
      r.liczba=floor(0.5 + (this->liczba * pow(10,y.liczba)))/pow(10,y.liczba);
   return r;
   }


   friend MayCal operator+(const MayCal&, const MayCal&);
   friend MayCal operator-(const MayCal&, const MayCal&);
   friend MayCal operator*(const MayCal&, const MayCal&);
   friend MayCal operator/(const MayCal&, const MayCal&);

   friend MayCal operator+=(MayCal&,const MayCal&);
   friend MayCal operator-=(MayCal&,const MayCal&);
   friend MayCal operator*=(MayCal&,const MayCal&);
   friend MayCal operator/=(MayCal&,const MayCal&);

   friend bool operator==(const MayCal&,const MayCal&);
   friend bool operator!=(const MayCal&,const MayCal&);
   friend bool operator<=(const MayCal&,const MayCal&);
   friend bool operator>=(const MayCal&,const MayCal&);
   friend bool  operator>(const MayCal&,const MayCal&);
   friend bool  operator<(const MayCal&,const MayCal&);

   friend ostream& operator<<(ostream&,MayCal const&);
   friend istream& operator>>(istream&,MayCal&);

   friend void checkDate(MayCal&);
   friend MayCal sqrt(const MayCal);
};
MayCal operator+(const MayCal &m1,const MayCal &m2){
   MayCal tmp(m1.liczba+m2.liczba);
   return tmp;
}
MayCal operator-(const MayCal &m1,const MayCal &m2){
   return MayCal(m1.liczba-m2.liczba);
}
MayCal operator*(const MayCal &m1,const MayCal &m2){
   return MayCal(m1.liczba*m2.liczba);
}
MayCal operator/(const MayCal &m1,const MayCal &m2){
   if(m2.liczba==0) return MayCal(2012);
   return MayCal(m1.liczba/m2.liczba);
}

MayCal operator+=(MayCal &m1,const MayCal &m2){
   m1.liczba+=m2.liczba;
   checkDate(m1);
   return m1;
}
MayCal operator-=(MayCal &m1,const MayCal &m2){
   m1.liczba-=m2.liczba;
   checkDate(m1);
   return m1;
}
MayCal operator*=(MayCal &m1,const MayCal &m2){
   m1.liczba*=m2.liczba;
   checkDate(m1);
   return m1;
}
MayCal operator/=(MayCal &m1,const MayCal &m2){
   if(m2.liczba==0) m1.liczba=2012;
   else m1.liczba/=m2.liczba;
   checkDate(m1);
   return m1;
}
bool operator==(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba==m2.liczba) return true;
   return false;
}
bool operator!=(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba!=m2.liczba) return true;
   return false;
}
bool operator>=(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba>=m2.liczba) return true;
   return false;
}
bool operator<=(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba<=m2.liczba) return true;
   return false;
}
bool operator<(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba<m2.liczba) return true;
   return false;
}
bool operator>(const MayCal& m1,const MayCal& m2)
{
   if(m1.liczba>m2.liczba) return true;
   return false;
}
ostream& operator<<(ostream& wyjscie,MayCal const &m){
   wyjscie << m.liczba;
   return wyjscie;
}
istream& operator>>(istream &wejscie,MayCal &m){
   wejscie>>m.liczba;
   checkDate(m);
   return wejscie;
}
void checkDate(MayCal &n){
   if(n.liczba<-3114)
   {
      n.liczba = -3114;
      cout<<"Time error!";
   }
   if(n.liczba>2012)
   {
      n.liczba=2012;
      cout<<"Time error!";
   }
}
MayCal sqrt(const MayCal m)
{
   return MayCal(sqrt(m.liczba));
}
MayCal dist(MayCal x1, MayCal y1, MayCal x2, MayCal y2)
{
   MayCal a(1024);
   return a*(sqrt((y1/ a - x1/a)*(y1/a - x1/a) + (y2/a - x2/a)*(y2/a - x2/a)));
}
string shoot(MayCal x1, MayCal y1, MayCal x2, MayCal y2)
{
   MayCal a,b;
   MayCal pom2012(2012);
   MayCal pom3114(-3114);
   MayCal pom1024(1024);
   if ((((x2/pom1024 - y2/pom1024)/sqrt(pom1024))/(x1 /pom1024 -y1 /pom1024))/sqrt(pom1024)<pom3114 /pom1024)
      return "{}";
   else if ((((x2/pom1024 - y2 /pom1024)/sqrt(pom1024))/(x1 / pom1024 - y1 /pom1024))/sqrt(pom1024)>pom2012 /pom1024)
      return "{}";
   else
      a = ((((x2/pom1024 - y2 /pom1024) /sqrt(pom1024))/(x1 /pom1024 - y1 /pom1024))/sqrt(pom1024) * pom1024);

   if((x2/pom1024) - ((a / sqrt(pom1024)) * (x1 / sqrt(pom1024)))<pom3114/pom1024)
      return "{}";
   else if((x2/pom1024) - ((a / sqrt(pom1024) * (x1 / sqrt(pom1024)))) >pom2012/pom1024)
      return "{}";
   else
      b = (((x2/pom1024) - ((a / sqrt(pom1024)) * (x1 / sqrt(pom1024)))) * pom1024);

   stringstream ss;
   string x,y;
   ss << a[2];
   x = ss.str();
   ss.str("");
   ss << b[2];
   y= ss.str();

   return "{" + x + "," + y + "}";
   }
