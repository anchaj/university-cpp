
#ifndef OSOBA_H
#define OSOBA_H

#include <string>
using namespace std;

class Osoba
{

public:
    Osoba(string, string );

    string getImie();
    string getNazwisko();

private:
    string imie;
    string nazwisko;

};

#endif


