
#include "osoba.h"
Osoba::Osoba(string imie, string nazwisko) : imie(imie), nazwisko(nazwisko) {}


string Osoba::getImie()
{
   return imie;
}
string Osoba::getNazwisko()
{
   return nazwisko;
}
