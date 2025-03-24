// AUTORE FILE: Piai Luca

#include "../include/Computer.h"

#include <cstdlib>

constexpr char Computer::kRows[];

void Computer::init_unit(Battlefield& b1, NavalUnit* u, std::ofstream& log) {
    while (true) {
        Coordinate bow{"00"};
        Coordinate stern{"00"};
        std::vector<Coordinate> pos;

        // genero la prua
        while (!b1.is_inside(bow) || b1.check_position(bow))
            bow = get_random_coordinate();

        // scelgo se verticale o orizzontale
        int vertical = rand() % 2;

        // genero la poppa
        if (vertical) {
            int i = b1.row(bow.x()) + u->size()-1; // index di rows[]
            if (i<1 || i>12) continue;
            stern = Coordinate(kRows[i], bow.y());
        }
        else stern = Coordinate(bow.x(), bow.y()+u->size()-1);

        // creo il vettore positions
        pos = generate_inline_position(bow, stern);

        // se non sono il linea
        if (pos.empty()) continue;

        // controlo che siano tutte interne
        if (!b1.is_inside(pos)) continue;

        // controllo che siano tutte vuote
        if (b1.check_position(pos)) continue;

        // setto le posizioni
        u->set_positions(pos);
        // inserisco tra le navi inizializzate
        alive_units_.push_back(u);
        // inserisco nel battefield
        b1.insert(u);

        // salvo la mossa
        log << bow << " " << stern << std::endl;

        break; // esco dal ciclo
    }
}

int Computer::turn(Battlefield& b1, Battlefield& b2, std::ofstream& log) {
    if (alive_units_.empty()) return 0;
    if (b1.is_empty()) return 0;

    NavalUnit* unit = nullptr;
    while (!unit) {
        // scelta di una unità random tra le disponibili
        int rnd_u = std::rand() % alive_units_.size();
        unit = b1.choose_unit(alive_units_[rnd_u]->get_cm());

        //rimuovo l'unità affondata da inizialized_units_
        if (!unit) {
            auto itr = alive_units_.begin() + rnd_u;
            alive_units_.erase(itr);
        }
    }

    // scelta del target
    Coordinate target = get_random_coordinate();

    // salvo la mossa
    log << unit->get_cm() << " " << target << std::endl;

    // azione nave
    unit->action(b1, b2, target);

    return 1;
}

Coordinate Computer::get_random_coordinate() {
    int rnd_x = std::rand() % 12 + 1;
    int rnd_y = std::rand() % 12 + 1;
    return Coordinate(kRows[rnd_x], rnd_y);
}
