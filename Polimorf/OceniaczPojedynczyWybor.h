#ifndef OCENIACZ_P_H
#define OCENIACZ_P_H

#include "Oceniacz.h"

class OceniaczPojedynczyWybor : public Oceniacz
{

public:

    OceniaczPojedynczyWybor(Pytanie &pytanie);

protected:

    virtual void zliczPkt(Pytanie &pytanie);

};

#endif
