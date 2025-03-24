#include <iostream>

#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "include/Battlefield.h"
#include "include/SupportVessel.h"
#include "include/Coordinate.h"
#include "include/BattleShip.h"
#include "include/Submarine.h"
#include "include/Computer.h"
#include "include/Human.h"

void battle_test();
void random_test();
void computer_test();

int main() {
    //battle_test();
    //random_test();
    computer_test();
    return 0;
}

void battle_test() {
    BattleShip bs1, bs2, bs3;
    SupportVessel sup1, sup2, sup3;
    Submarine s1, s2;

    BattleShip enemy_bs;

    Battlefield b1;
    Battlefield b2;

    bs1.set_positions(generate_inline_position(Coordinate("D5"), Coordinate("D9")));
    bs2.set_positions(generate_inline_position(Coordinate("F5"), Coordinate("F9")));
    bs3.set_positions(generate_inline_position(Coordinate("G7"), Coordinate("M7")));

    enemy_bs.set_positions(generate_inline_position(Coordinate("D7"), Coordinate("H7")));

    b1.insert(&bs1);
    b1.insert(&bs2);
    b1.insert(&bs3);

    b2.insert(&enemy_bs);

    sup1.set_positions(generate_inline_position(Coordinate("F4"), Coordinate("H4")));
    sup2.set_positions(generate_inline_position(Coordinate("M2"), Coordinate("M4")));
    sup3.set_positions(generate_inline_position(Coordinate("B10"), Coordinate("B12")));

    b1.insert(&sup1);
    b1.insert(&sup2);
    b1.insert(&sup3);

    s1.set_positions(generate_inline_position(Coordinate("C3"), Coordinate("C3")));
    s2.set_positions(generate_inline_position(Coordinate("M11"), Coordinate("M11")));

    b1.insert(&s1);
    b1.insert(&s2);

    cout << b1 << endl;
    cout << b2 << endl;

    // azioni da rivedere tutte
    //s1.action(b1, b2, Coordinate("G6")); //DA RIVEDERE
    //enemy_bs.action(b2, b1, Coordinate("I7"));
    sup1.action(b1, b2, Coordinate("H4"));

    cout << b1 << endl;
    cout << b2 << endl;
}

void random_test() {
    static constexpr char rows[] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', '\0' };

    // scelta di una unità random tra le disponibili
    std::srand(std::time(nullptr));
    int rnd_u = std::rand() % 7 + 1;

    // scelta del target
    int rnd_x = std::rand() % 12 + 1;
    int rnd_y = std::rand() % 12 + 1;

    cout << "Posizione vector: " << rnd_u << endl
         << "Posizione rows = " << rnd_x << endl
         << "y = " << rnd_y << endl;
    cout << Coordinate(rows[rnd_x], rnd_y) << endl;
}

void computer_test() {
    std::srand(time(0)); // setto il seed

    ofstream log("log.txt", std::ofstream::out);

    // navi giocarore 1
    BattleShip bs1, bs2, bs3;
    SupportVessel sup1, sup2, sup3;
    Submarine s1, s2;

    // navi giocarore 2
    BattleShip Ebs1, Ebs2, Ebs3;
    SupportVessel Esup1, Esup2, Esup3;
    Submarine Es1, Es2;

    // campi da battaglia
    Battlefield b1;
    Battlefield b2;


    Computer g1;
    g1.init_unit(b1, &bs1, log);
    g1.init_unit(b1, &bs2, log);
    g1.init_unit(b1, &bs3, log);
    g1.init_unit(b1, &sup1, log);
    g1.init_unit(b1, &sup2, log);
    g1.init_unit(b1, &sup3, log);
    g1.init_unit(b1, &s1, log);
    g1.init_unit(b1, &s2, log);

    Computer g2;
    g2.init_unit(b2, &Ebs1, log);
    g2.init_unit(b2, &Ebs2, log);
    g2.init_unit(b2, &Ebs3, log);
    g2.init_unit(b2, &Esup1, log);
    g2.init_unit(b2, &Esup2, log);
    g2.init_unit(b2, &Esup3, log);
    g2.init_unit(b2, &Es1, log);
    g2.init_unit(b2, &Es2, log);

    cout << b1 << endl;
    cout << b2 << endl;

    int i = 1;
    while (!b1.is_empty() && !b2.is_empty()) {
        cout << "TURNI = " << i++ << endl;
        g1.turn(b1, b2, log);
        g2.turn(b2, b1, log);
        cout << "GIOCATORE 1" << endl;
        cout << b1 << endl;
        cout << "GIOCATORE 2" << endl;
        cout << b2 << endl;
    }
    if (!b1.is_empty() && !b2.is_empty())
        cout << "Partita finita in stallo" << endl;
    else if (b2.is_empty())
        cout << "Player1 ha vinto!" << endl;
    else if (b1.is_empty())
        cout << "Player2 ha vinto!" << endl;
}
