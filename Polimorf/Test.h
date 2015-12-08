#ifndef TEST_H
#define TEST_H

#include <string>
#include <sstream>
#include "Osoba.h"
#include "Pytanie.h"
#include "OceniaczPojedynczyWybor.h"
using namespace std;

class Test
{

public:
    Test(int iloscPytan, Pytanie *pytania, Osoba *osoba);
    Pytanie getPytanie(int i);
    string getOsoba();
    void setPytanie(int i, Pytanie p);
private:
    int iloscPytan;
    Osoba *osoba;
    Pytanie *pytania;

};

#endif

