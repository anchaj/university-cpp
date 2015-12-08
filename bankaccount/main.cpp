#include <iostream>
#include <string>
using namespace std;
class RachunekBankowy
{
public:
   string imie,nazwisko,adres;
   string IBAN;

   enum RodzajKonta{ROR=0,LOKATA,JUNIOR,SENIOR,VIP,STUDENT};

   double stanKonta,oprocentowanie,debet,oprocentowanieDebet;
   void wplac(double a)
   {
      stanKonta += a;
   }
   bool wyplac(double a)
   {
      if(debet<0) debet=-debet;

      if(stanKonta-a< -debet ) return false;
      else stanKonta-=a;
   }
   void nalicz_odsetki()
   {
      if(stanKonta>0) stanKonta += (stanKonta*oprocentowanie);
      else stanKonta -= (stanKonta*oprocentowanieDebet);
   }
};

int main()
{

   return 0;
}
