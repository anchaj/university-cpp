
#include "OceniaczWielokrotnyWybor.h"

OceniaczWielokrotnyWybor::OceniaczWielokrotnyWybor(Pytanie &pytanie)
{
    zliczPkt(pytanie);
}

void OceniaczWielokrotnyWybor::zliczPkt(Pytanie &pytanie)
{
    if (pytanie.Bledne() == 0 && pytanie.Puste() == 0)
        pkt = 2;
    else if (pytanie.Poprawne() > 0 && pytanie.Bledne() == 0)
        pkt = 1;
    else if (pytanie.Puste() == pytanie.getN())
        pkt = 0;
    else
        pkt = -1;
}
