#include "tablica_double.h"
int TablicaDouble::getSize()const{return size;}
int TablicaDouble::getTab(int index)const{return tab[index];}
TablicaDouble::TablicaDouble():
   size(0)
{
   tab = new double[0];
}

TablicaDouble::TablicaDouble(unsigned i):
   size(i)
{
   tab = new double[i];
}
TablicaDouble::TablicaDouble(const TablicaDouble& nowa):
   size(nowa.getSize())
{
   delete[] tab;
   tab = new double[nowa.getSize()];

   for(int i=0;i<size;i++)
   {
      tab[i] = nowa.getTab(i);
   }
}
TablicaDouble::~TablicaDouble()
{
   delete [] tab;
}
TablicaDouble& TablicaDouble::operator=(const TablicaDouble& nowa)
{
   delete [] this->tab;
   size = nowa.getSize();
   tab = new double[size];
   for(int i=0;i<size;i++)
   {
      tab[i] = nowa.getTab(i);
   }
}
double& TablicaDouble::operator[](unsigned index)
{
   return tab[index];
}
double TablicaDouble::operator[](unsigned index) const
{
   return tab[index];
}
void TablicaDouble::resize(unsigned i)
{
   double *tmp = new double[getSize()];
   for(int j=0;j<getSize();j++)
   {
      tmp[j]=tab[j];
   }
   delete[ ] tab;
   tab = new double[i];

   for(int j=0;j<size;j++)
   {
      tab[j]=tmp[j];
   }
   if(size<i)
      for(int j=size;j<i;j++)
         tab[j]=0;
}
