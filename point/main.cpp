#include "punkt.h"
#include "zn.h"
#include "set.h"

using namespace std;
int main()
{
   Punkt A;
   Punkt B(1,2);
   cout << B << endl;

/// ///////////////////////////////////////////////////////////
   Zn a(2,7);
   Zn b(2,7);
   Zn c = a++ ;
   Zn d = ++b ;

   cout<<a.getLiczba()<<" "<<b.getLiczba()<<" "<<c.getLiczba()<<" "<<d.getLiczba()<<endl;

   Zn e = a++ + a++;

   cout<< e.getLiczba();
/// /////////////////////////////////////////////////////////////
   cout<<endl;
   const char al[]="costamcos";
   const char bd[]="dadsa";
   Set AA(al);
   AA.wypisz();
   Set BB=bd;

   AA*=BB;

   return 0;
}
