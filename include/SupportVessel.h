// AUTORE FILE: Chinello Alessandro

#ifndef SUPPORT_VESSEL_H
#define SUPPORT_VESSEL_H

#include "NavalUnit.h"

class SupportVessel : public NavalUnit{
public:
    SupportVessel();
    void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};

#endif
