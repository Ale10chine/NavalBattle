// AUTORE FILE: Chinello Alessandro

#include "../include/BattleShip.h"
#include "../include/Battlefield.h"

BattleShip::BattleShip() { 
    hp_ = 5;
    size_ = 5;
    type_ = 'C';
    for (int i=0; i<5; i++)
        positions_.push_back(Coordinate{"00"});
    cm_ = positions_[2];
}

void BattleShip::action(Battlefield& b1, Battlefield& b2, const Coordinate& t) { 
	if (!b2.is_inside(t)) return; 

	char hit  = 'O';
    // controllo se la posizione target è occupata da un pezzo di una nave
	if (b2.check_position(t)) {
        hit = 'X';

        // risalgo al proprietario della coordinata colpita
        NavalUnit* owner = b2.get_coordinate_owner(t);

        // controllo che la posizione non sia già stata colpita
        for (Coordinate& p : owner->get_positions())
            if (p == t && p.is_marked()) return;

        // decremento la vita della nave colpia e aggiorno la griglia di difesa nemica
        owner->decrease_life(t);
        b2.refresh_defence();
    }
	
	// aggiorno la mia griglia di attacco
	b1.mark_attack(t, hit);
}
