//Mateusz Jachna
#include "Polynomial.h"
#include <stdlib.h>
using namespace std;
Polynomial::Polynomial():
DE(0){
TAB=(float*)malloc(4);
TAB[0]=0;
}
Polynomial::Polynomial(int inDE,bool clean):
   DE(inDE){
   TAB=(float*)malloc((DE+1)<<2);
   if(clean) clear_elements();
}
Polynomial::Polynomial(double inValue):
   DE(0){
   TAB=(float*)malloc(4);
   TAB[0]=(float)inValue;
}
Polynomial::Polynomial(int inDE,float *tab):
   DE(inDE){
   TAB=(float*)malloc((DE+1)<<2);
   for(int i=0;i<=DE;i++)
     TAB[i] = tab[i];
}
Polynomial::Polynomial(int inDE,double *tab):
   DE(inDE){
   TAB=(float*)malloc((DE+1)<<2);
   for(int i=0;i<=DE;i++)
     TAB[i] = (float)tab[DE-i];
}
Polynomial::Polynomial(const Polynomial &nowy):
   DE(nowy.DE){
      TAB=(float*)malloc((DE+1)<<2);
      for(int i=0;i<=DE;i++)
         TAB[i] = nowy.TAB[i];
}
Polynomial::Polynomial(int DE1,float *TAB1,char sing,int DE2,float *TAB2)
{
   if(DE1>=DE2){
      DE=DE1;
      TAB=(float*)malloc((DE+1)<<2);
      for(int i=0;i<=DE;i++)
         TAB[i]=TAB1[i];
      if(sing =='+') {
         for(int i=0;i<=DE2;i++)
            TAB[i]+=TAB2[i];
      }  else {
         for(int i=0;i<=DE2;i++)
            TAB[i]-=TAB2[i];
      }
   } else{
      DE=DE2;
      TAB=(float*)malloc((DE+1)<<2);
      if(sing =='+'){
         for(int i=0;i<=DE2;i++)
            TAB[i]=TAB2[i];
         for(int i=0;i<=DE1;i++)
            TAB[i]+=TAB1[i];
         } else{
         clear_elements();
         for(int i=0;i<=DE1;i++)
            TAB[i]=TAB1[i];
         for(int i=0;i<=DE;i++)
            TAB[i]-=TAB2[i];
         }
   }
}
Polynomial::~Polynomial(){
   free(TAB);
}
void Polynomial::clear_elements(int a){
   for(int i=a;i<=DE;i++)
      TAB[i] = 0;
}
int Polynomial::degree()const{
   int index=0;
   for(int i=0; i<=DE;i++)
      if(TAB[i]!=0) index = i;
   return index;
}
float Polynomial::Horner(int x,int i) const{
    if(i==DE)
      return TAB[i];
    else
      return Horner(x,i+1)*x+TAB[i];
}
void Polynomial::reduction()const{
   if(degree()<DE)
   {
      int d = degree();
      TAB=(float*)realloc(TAB,(d+1)<<2);
      DE = d;
   }
}
float& Polynomial::operator[](int a){
   if(a>DE){
      TAB=(float*)realloc(TAB,(a+1)<<2);
      int b=DE+1;
      DE = a;
      clear_elements(b);
   }
   return TAB[a];
}
float Polynomial::operator[](int a) const{
   if(a>DE) return 0;
   return TAB[a];
}
float Polynomial::operator()(int x) const{
   return Horner(x);
}
Polynomial Polynomial::operator=(double a){
   free(TAB);
   TAB=(float*)malloc(4);
   DE=0;
   TAB[0]=(float)a;
   return *this;
}
Polynomial& Polynomial::operator=(Polynomial p){
   free(TAB);
   DE = p.DE;
   TAB=(float*)malloc((DE+1)<<2);
   for (int i=0;i<=p.DE;i++)
      TAB[i]=p.TAB[i];
   return *this;
}
Polynomial operator+(const Polynomial &p1,const Polynomial &p2){
   if(p1.DE==0 and p2.DE==0) return Polynomial(p1.TAB[0]+p2.TAB[0]);
   return Polynomial(p1.DE,p1.TAB,'+',p2.DE,p2.TAB);
}
Polynomial operator-(const Polynomial &p1,const Polynomial &p2){
   if(p1.DE==0 and p2.DE==0) return Polynomial(p1.TAB[0]-p2.TAB[0]);
   return Polynomial(p1.DE,p1.TAB,'-',p2.DE,p2.TAB);
}
Polynomial operator*(const Polynomial &p1,const Polynomial &p2){
   p1.reduction();p2.reduction();
   Polynomial nowy(p1.DE+p2.DE);
   for(int i=0;i<=p1.DE;i++)
         for(int j=0;j<=p2.DE;j++)
            nowy.TAB[i+j]+=p1.TAB[i]*p2.TAB[j];
   nowy.reduction();
   return nowy;
}
Polynomial operator-(double a,Polynomial &p1){
   Polynomial nowy(p1);
   for(int i=0;i<=p1.DE;i++)
         nowy.TAB[i]=-nowy.TAB[i];
   nowy.TAB[0]+=(float)a;
   return nowy;
}
Polynomial operator*(Polynomial &p1,double a){
   if(!a)return Polynomial(0);
   if(a==1) return Polynomial(p1);
   Polynomial nowy(p1);
   for(int i=0;i<=nowy.DE;i++) nowy.TAB[i]*=(float)a;
   return nowy;
}
Polynomial operator+=(Polynomial &p1,const Polynomial &p2){
      if(p1.DE>=p2.DE){
      for(int i=0;i<=p2.DE;i++) p1.TAB[i]+=p2.TAB[i];
   } else{
      p1.TAB=(float*)realloc(p1.TAB,(p2.DE+1)<<2);
      for(int i=0;i<=p1.DE;i++)
         p1.TAB[i] += p2.TAB[i];
      for(int i=p1.DE+1;i<=p2.DE;i++)
         p1.TAB[i] = p2.TAB[i];
      p1.DE = p2.DE;
   }
   return p1;
}
Polynomial operator-=(Polynomial &p1,const Polynomial &p2){
   if(p1.DE>=p2.DE){
      for(int i=0;i<=p2.DE;i++) p1.TAB[i]-=p2.TAB[i];
   } else{
      p1.TAB=(float*)realloc(p1.TAB,(p2.DE+1)<<2);
      for(int i=0;i<=p1.DE;i++)
         p1.TAB[i] -= p2.TAB[i];
      for(int i=p1.DE+1;i<=p2.DE;i++)
         p1.TAB[i] = p2.TAB[i];
   }
   return p1;
}
Polynomial operator*=(Polynomial &p1,Polynomial &p2){
   Polynomial tmp(p1.DE+p2.DE);
   tmp.clear_elements();
   for(int i=0;i<=p1.DE;i++)
   {
         for(int j=0;j<=p2.DE;j++)
            tmp.TAB[i+j]+=p1.TAB[i]*p2.TAB[j];
   }
   p1.TAB=(float*)realloc(p1.TAB,(tmp.DE+1)<<2);
   for(int i=0;i<=tmp.DE;i++)
      p1.TAB[i] = tmp.TAB[i];
   p1.DE = tmp.DE;
   return p1;
}
const Polynomial& operator++(Polynomial& p){
   p.TAB[0]++;
   return p;
}
const Polynomial operator++(Polynomial& p,int){
   Polynomial nowy(p);
   p.TAB[0]++;
   return nowy;
}
const Polynomial& operator--(Polynomial& p){
   p.TAB[0]--;
   return p;
}
const Polynomial operator--(Polynomial& p,int){
   Polynomial nowy(p);
   p.TAB[0]--;
   return Polynomial(p);
}
bool operator==(const Polynomial& p1,const Polynomial& p2){
   if(p1.DE != p2.DE) return 0;
   for(int i=0;i<=p1.DE;i++){
      if(p1.TAB[i]!=p2.TAB[i]) return 0;
   }
   return 1;
}
bool operator!=(const Polynomial& p1,const Polynomial& p2){
   if(p1.DE != p2.DE) return 1;
   for(int i=0;i<=p1.DE;i++){
      if(p1.TAB[i]!=p2.TAB[i]) return 1;
   }
   return 0;
}
ostream& operator<<(ostream& wypisz,Polynomial const &p){
   p.reduction();
   wypisz <<"[ "<<p.DE<<" : ";
   for(int i=0;i<=p.DE;i++)
      wypisz<<p.TAB[p.DE-i]<<" ";
   wypisz<<"]";
   return wypisz;
}
istream& operator>>(istream &we, Polynomial &p){
         char a;
         we>>a>>p.DE>>a;
         p.TAB = (float*) malloc((p.DE+1)<<2);
         p.clear_elements();
         for(int i=0;i<=p.DE;i++) we>>p.TAB[p.DE-i];
         we>>a;
         return we;
}
