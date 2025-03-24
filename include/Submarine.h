// AUTORE FILE: Chinello Alessandro

#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "../include/NavalUnit.h"

class Submarine : public NavalUnit {
public:
    Submarine();
    void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};


#endif
