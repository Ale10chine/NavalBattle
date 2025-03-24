// AUTORE FILE: Chinello Alessandro

#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "NavalUnit.h"

class BattleShip : public NavalUnit{
public:
	BattleShip();
	void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};

#endif
