//Mateusz Jachna
#include "Polynomial.h"
using namespace std;
Polynomial Polynomial::operator=(Polynomial *copy)
{
        copy->Degree = Degree;
        for(int i = 0; i <= Degree; ++i)
                copy->Elements[i] = Elements[i];
        return *copy;
}

Polynomial Polynomial::operator=(double number)
{
        Degree = 0;
        Elements[0] = number;
        return *this;
}
Polynomial::Polynomial():
   Degree(0){
   Elements = new double[1];
   Elements[0]=0;
}
oPolynomial::Polynomial(int inDegree,bool clean):
   Degree(inDegree){
      Elements = new double[Degree+1];
      if(clean) clear_elements();
}
Polynomial::Polynomial(double inValue):
   Degree(0){
   Elements = new double[1];
   Elements[0] = inValue;
}
Polynomial::Polynomial(int inDegree,double *tab):
   Degree(inDegree){
   Elements = new double[Degree+1];
   for(int i=0;i<=Degree;i++)
   {
      Elements[i] = tab[Degree-i];
   }
}
Polynomial::Polynomial(Polynomial &nowy){
   if(&nowy != this) {
      Degree=nowy.Degree;
      Elements = new double[Degree+1];
      for(int i=0;i<=Degree;i++)
      {
         Elements[i] = nowy.Elements[i];
      }
   }
}
Polynomial::~Polynomial(){
   delete[] Elements;
}
void Polynomial::clear_elements(){
   for(int i=0;i<=Degree;i++)
   {
      Elements[i] = 0;
   }
}
int Polynomial::degree () const{
   int index=0;
   for(int i=0; i<=Degree;i++)
   {
      if(Elements[i]!=0) index = i;
   }
   return index;
}
double Polynomial::Horner(int x,int i) const{
    if(i==Degree)
      return Elements[i];
    else
      return Horner(x,i+1)*x+Elements[i];
}
void Polynomial::reduction(){
   if(degree()<Degree)
   {
      int d = degree();
      //redukuj dlugosc wielomianu
      double *tmp = new double[d+1];
      for(int i=0;i<=d;i++)
         tmp[i] = Elements[i];
      delete[] Elements;
      Elements = new double[d+1];
      for(int i=0;i<=d;i++)
         Elements[i] = tmp[i];
      delete[] tmp;
      Degree = d;
   }
}
double& Polynomial::operator[](int a){
   if(a>Degree){
         if(a>10000000) return Elements[0];
      double *tmp = new double[Degree+1];
      for(int i=0;i<=Degree;i++) tmp[i] = Elements[i];
      delete[] Elements;
      Elements = new double[a+1];

      int temp=Degree;
      Degree = a;
      clear_elements();

      for(int i=0;i<=temp;i++) Elements[i] = tmp[i];
      delete[] tmp;
   }
   return Elements[a];
}
double Polynomial::operator[](int a) const{
   if(a>Degree) return 0;
   return Elements[a];
}
double Polynomial::operator()(int x) const{
   return Horner(x);
}

/*Polynomial Polynomial::operator=(double a){
   delete[] Elements;
   Elements = new double[1];
   Degree=0;
   Elements[0]=a;
}*/
Polynomial operator+(const Polynomial &p1,const Polynomial &p2){
   Polynomial nowy;
   int min;
   if(p1.Degree>p2.Degree)
   {
      min = p2.Degree;
      nowy.Degree = p1.Degree;
      nowy.Elements = new double[nowy.Degree+1];
      for(int i=min;i<=nowy.Degree;i++) nowy.Elements[i] = p1.Elements[i];
   }
   else
   {
      min = p1.Degree;
      nowy.Degree = p2.Degree;
      nowy.Elements = new double[nowy.Degree+1];
      for(int i=min;i<=nowy.Degree;i++) nowy.Elements[i] = p2.Elements[i];
   }
   for(int i=0;i<=min;i++)
   {
      nowy.Elements[i] = p1.Elements[i]+p2.Elements[i];
   }
   nowy.reduction();
   return nowy;
}
Polynomial operator-(const Polynomial &p1,const Polynomial &p2){
   Polynomial nowy;
   int min;
   if(p1.Degree>p2.Degree)
   {
      min = p2.Degree;
      nowy.Degree = p1.Degree;
      nowy.Elements = new double[nowy.Degree+1];
      for(int i=min;i<=nowy.Degree;i++) nowy.Elements[i] = p1.Elements[i];
   }
   else
   {
      min = p1.Degree;
      nowy.Degree = p2.Degree;
      nowy.Elements = new double[nowy.Degree+1];
      for(int i=min;i<=nowy.Degree;i++) nowy.Elements[i] = p2.Elements[i];
   }
   for(int i=0;i<=min;i++)
   {
      nowy.Elements[i] = p1.Elements[i]-p2.Elements[i];
   }
   nowy.reduction();
   return nowy;
}
Polynomial operator*(const Polynomial &p1,const Polynomial &p2){
   Polynomial nowy(p1.Degree+p2.Degree);
   for(int i=0;i<=p1.Degree;i++)
   {
         for(int j=0;j<=p2.Degree;j++)
            nowy.Elements[i+j]+=p1.Elements[i]*p2.Elements[j];
   }
   nowy.reduction();
   return nowy;
}
Polynomial operator+(Polynomial &p1,double a){
   Polynomial nowy(p1);
   nowy.Elements[0]+=a;
   nowy.reduction();
   return nowy;
}
Polynomial operator-(Polynomial &p1,double a){
   Polynomial nowy(p1);
   nowy.Elements[0]-=a;
   nowy.reduction();
   return nowy;
}
Polynomial operator-(double a,Polynomial &p1){
   Polynomial nowy(p1);
   for(int i=0;i<=p1.Degree;i++)
         nowy.Elements[i]=-nowy.Elements[i];
   nowy.Elements[0]+=a;
   nowy.reduction();
   return nowy;
}
Polynomial operator*(Polynomial &p1,double a){
   Polynomial nowy(p1);
   for(int i=0;i<=nowy.Degree;i++) nowy.Elements[i]*=a;
   nowy.reduction();
   return nowy;
}
Polynomial operator+=(Polynomial &p1,const Polynomial &p2){
      if(p1.Degree>=p2.Degree){
      for(int i=0;i<=p2.Degree;i++) p1.Elements[i]+=p2.Elements[i];
   } else{ // p1.Degree < p2.Degree;
      Polynomial tmp(p2.Degree);
      for(int i=0;i<=p1.Degree;i++)
         tmp.Elements[i] = p1.Elements[i] + p2.Elements[i];
      for(int i=p1.Degree+1;i<=p2.Degree;i++)
         tmp.Elements[i] = p2.Elements[i];
      delete[] p1.Elements;
      p1.Elements = new double[tmp.Degree+1];
      p1.Degree = tmp.Degree;
      for(int i=0;i<=p1.Degree;i++)
         p1.Elements[i] = tmp.Elements[i];
   }
   p1.reduction();
   return p1;
}
Polynomial operator-=(Polynomial &p1,const Polynomial &p2){
   if(p1.Degree>=p2.Degree){
      for(int i=0;i<=p2.Degree;i++) p1.Elements[i]-=p2.Elements[i];
   } else{
      Polynomial tmp(p2.Degree);
      for(int i=0;i<=p1.Degree;i++)
         tmp.Elements[i] = p1.Elements[i] - p2.Elements[i];
      for(int i=p1.Degree+1;i<=p2.Degree;i++)
         tmp.Elements[i] = p2.Elements[i];
      delete[] p1.Elements;
      p1.Elements = new double[tmp.Degree+1];
      p1.Degree = tmp.Degree;
      for(int i=0;i<=p1.Degree;i++)
         p1.Elements[i] = tmp.Elements[i];
   }
   p1.reduction();
   return p1;
}
Polynomial operator*=(Polynomial &p1,const Polynomial &p2){
   Polynomial tmp(p1.Degree+p2.Degree);
   tmp.clear_elements();
   for(int i=0;i<=p1.Degree;i++)
   {
         for(int j=0;j<=p2.Degree;j++)
            tmp.Elements[i+j]+=p1.Elements[i]*p2.Elements[j];
   }
   delete[] p1.Elements;
   p1.Elements = new double[tmp.Degree+1];
   for(int i=0;i<=tmp.Degree;i++)
      p1.Elements[i] = tmp.Elements[i];
   p1.Degree = tmp.Degree;
   p1.reduction();
   return p1;
}
const Polynomial& operator++(Polynomial& p){
   p.Elements[0]++;
   p.reduction();
   return p;
}
const Polynomial operator++(Polynomial& p,int){

   Polynomial nowy(p);
   p.Elements[0]++;
   p.reduction();
   nowy.reduction();
   return nowy;
}
const Polynomial& operator--(Polynomial& p){
   p.Elements[0]--;
   p.reduction();
   return p;
}
const Polynomial operator--(Polynomial& p,int){
   Polynomial nowy(p);
   p.Elements[0]--;
   nowy.reduction();
   p.reduction();
   return nowy;
}
bool operator==(const Polynomial& p1,const Polynomial& p2){
   if(p1.Degree != p2.Degree) return false;
   for(int i=0;i<=p1.Degree;i++){
      if(p1.Elements[i]!=p2.Elements[i]) return false;
   }
   return true;
}
bool operator!=(const Polynomial& p1,const Polynomial& p2){
   if(p1.Degree != p2.Degree) return true;
   for(int i=0;i<=p1.Degree;i++){
      if(p1.Elements[i]!=p2.Elements[i]) return true;
   }
   return false;
}
ostream& operator<<(ostream& wypisz,Polynomial const &p){
   wypisz <<"[ "<<p.Degree<<" : ";
   for(int i=0;i<=p.Degree;i++)
   {
      wypisz<<p.Elements[p.Degree-i]<<" ";
   }
   wypisz<<"]";
   return wypisz;
}
istream& operator>>(istream &strumien_we, Polynomial &p){
         char a;
         strumien_we >> a;
         strumien_we >> p.Degree;
         strumien_we >> a;
         p.Elements = new double[p.Degree+1];
         p.clear_elements();
         for(int i=0;i<=p.Degree;i++) cin>>p.Elements[p.Degree-i];
         strumien_we >> a;
         return strumien_we;
}
