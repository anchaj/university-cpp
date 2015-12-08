
#ifndef OCENIACZ_W_H
#define OCENIACZ_W_H

#include "Oceniacz.h"

class OceniaczWielokrotnyWybor : public Oceniacz
{

public:

    OceniaczWielokrotnyWybor(Pytanie &pytanie);

protected:

    virtual void zliczPkt(Pytanie &pytanie);

};

#endif
