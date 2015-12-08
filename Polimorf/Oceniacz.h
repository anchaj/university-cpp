
#ifndef OCENIACZ_H
#define OCENIACZ_H

#include "Pytanie.h"

class Oceniacz
{

public:

    Oceniacz();
    int getPkt();

protected:

    int pkt;
    virtual void zliczPkt(Pytanie &pytanie) = 0;

};

#endif

