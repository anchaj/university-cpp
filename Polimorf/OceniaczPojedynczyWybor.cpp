#include "OceniaczPojedynczyWybor.h"

OceniaczPojedynczyWybor::OceniaczPojedynczyWybor(Pytanie &pytanie)
{
    zliczPkt(pytanie);
}

void OceniaczPojedynczyWybor::zliczPkt(Pytanie &pytanie)
{
    if (pytanie.Poprawne() == 1 && pytanie.Puste() == pytanie.getN() - 1)
        pkt = 1;
    else
        pkt = 0;
}

