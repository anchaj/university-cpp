#include "Test.h"

Test::Test(int iloscPytan, Pytanie *pytania, Osoba *osoba)
: iloscPytan(iloscPytan), pytania(pytania), osoba(osoba) {}

Pytanie Test::getPytanie(int i)
{
    return pytania[i];
}

void Test::setPytanie(int i, Pytanie p)
{
    pytania[i] = p;
}

string Test::getOsoba()
{
    ostringstream r;
    for(int i = 0; i < iloscPytan; i++)
    {
        OceniaczPojedynczyWybor oc(pytania[i]);
        r << "Pytanie " << i << ": " << oc.getPkt() << endl;
    }
    r << osoba->getImie() << " " << osoba->getNazwisko() << endl;
    return r.str();
}
