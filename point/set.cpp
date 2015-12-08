#include "set.h"
using namespace std;
Set::Set():
   dlugosc(0)
{
   tab = new char[1];
   for(int i=0;i<26;i++)
   {
      litery[i]=0;
   }
}
Set::Set(int a):
   dlugosc(a)
{
   tab = new char[a];
   for(int i=0;i<26;i++)
   {
      litery[i]=0;
   }
}
Set::Set(const char napis[])
{
   int i=0;
   while(napis[i]!=0){
      i++;
   }
   dlugosc = i;
   tab = new char[dlugosc];
   for(int i=0;i<dlugosc;i++){
      tab[i]=napis[i];
   }
   for(int i=0;i<26;i++)
   {
      litery[i]=0;
   }
   zlicz();
}

void Set::zlicz() const
{
   for(int i=0;i<dlugosc;i++)
   {
      if(tab[i] > 64 and tab[i] < 91 )
         litery[tab[i]-65]=1;
      if(tab[i] > 96 and tab[i] < 123 )
         litery[tab[i]-97]=1;
   }
}
void Set::wypisz()
{
   for(int i=0;i<dlugosc;i++)
   {
      cout<<tab[i];
   }
}
Set& Set::operator*=(const Set &a)  {
   /// zliczanie
   a.zlicz();
   int iloczyn=0;
   for(int i=0;i<26;i++)
   {
      if(litery[i]==a.litery[i]) iloczyn++;
   }

   cout<<"iloczyn "<<iloczyn;
}

Set& Set::operator=(char a)
{
   delete[] tab;
   tab = new char[1];
   tab[0]=a;
   return *this;
}
Set& Set::operator=(const char napis[])
{
   delete[] tab;
   int i=0;
   while(napis[i]!=0) i++;
   tab=new char [i];
   dlugosc = i;
   for(int j=0;j<i;j++)
   {
      tab[j]=napis[j];
   }
}
bool Set::operator[](char szukana) const{
   for(int i=0;i<dlugosc;i++)
   {
      if (tab[i]==szukana) return true;
   }
   return false;
}
