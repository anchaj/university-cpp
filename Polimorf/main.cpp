#include "Pytanie.h"
#include "Test.h"
#include "OceniaczWielokrotnyWybor.h"
#include <iostream>
using namespace std;
int main()
{
   Osoba ja("Mateusz","Jachna");
   Pytanie::Odpowiedzi tab[] = {Pytanie::BAD_MARKED,
                                Pytanie::BAD_MARKED,
                                Pytanie::BAD_UNMARKED,
                                Pytanie::OK_MARKED,
                                Pytanie::OK_UNMARKED};
   Pytanie::Odpowiedzi tab2[]= {Pytanie::BAD_MARKED,
                                Pytanie::BAD_MARKED,
                                Pytanie::BAD_UNMARKED,
                                Pytanie::OK_MARKED,
                                Pytanie::OK_UNMARKED,
                                Pytanie::OK_MARKED,
                                Pytanie::OK_MARKED,};
   Pytanie p(5,tab);
   Pytanie p2(7,tab2);
   OceniaczPojedynczyWybor pojedynczy(p);
   cout<<pojedynczy.getPkt()<<endl;

   OceniaczWielokrotnyWybor wielokrotny(p2);
   cout<<wielokrotny.getPkt()<<endl;

   Test test(1,&p,&ja);
   cout<<test.getOsoba();
   return 0;
}
