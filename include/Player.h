// AUTORE FILE: Piai Luca

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Coordinate.h"
#include "Battlefield.h"

class Player {
public:
    // inizializza l'unità navale passata come parametro
	virtual void init_unit(Battlefield& b1, NavalUnit* u, std::ofstream& log) = 0;

    // viene eseguito un turno
	virtual int turn(Battlefield& b1 , Battlefield& b2, std::ofstream& log) = 0;
};

#endif
