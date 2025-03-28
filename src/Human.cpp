// AUTORE FILE: Chinello Alessandro

#include "../include/Human.h"

#include <iostream>
#include <string>

void Human::init_unit(Battlefield& b1, NavalUnit* u, std::ofstream& log) {
	while(true){
		std::cout << "Quali sono le coordinate per " << get_unit_name() << "?" << std::endl;
		std::string input1{""}, input2{""};
		std::cin >> input1 >> input2;

		// controllo che la stringa inserita sia valida
		if (input1.empty() || input2.empty() || input1.size()>3 || input2.size()>3) continue;
		
        // inizializzo le coordinate di prua e poppa della nave
		Coordinate bow = Coordinate(input1);
		Coordinate stern = Coordinate(input2);
		
        // genero le posizioni della nave
		std::vector<Coordinate> positions = generate_inline_position(bow, stern);

		// controllo che non sia diverso dalla size effettiva di quella data NavalUnit
		if (positions.size() != u->size()) {
			std::cout << "Lunghezza della barca non coincide" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
			continue;
		}
		
		// controllo che le coordinate siano tutte interne al battlefield
		if(!b1.is_inside(positions)) {
			std::cout << "Le posizioni inserite non sono totalmente interne" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
			continue;
		}
		
		// controllo che non sovrascriviamo delle barche sul battlefield
		if(b1.check_position(positions)) {
			std::cout << "Le posizioni inserite sono già occupate alemeno in parte" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
			continue;
		}
		
		// Settaggio delle posizioni
		u->set_positions(positions);
		
		// Inserimento barca
		b1.insert(u);
		
		// Aggiorno il contatore delle barche inizializzate
		initialized_units_++; 
		
		// inserico le coordinate di poppa e prua nel file di log
		log << input1 << " " << input2 << std::endl; 
		
		// esco dal ciclo della barca i-esima
		break; 
	}
}
	
int Human::turn(Battlefield& b1 , Battlefield& b2, std::ofstream& log){
	while(true){
		std::cout<<"E' il tuo turno, seleziona la barca per compiere una nuova mossa, e imponi la coordinata di target!"<<std::endl;
		std::string input1{""}, input2{""};
		std::cin >> input1 >> input2;
		
		// controllo che la stringa inserita sia valida
		if(input1.empty() || input2.empty() || input1.size()>3 || input2.size()>3 ) continue;

        // controlle se è un comando speciale
        if (special_commands(b1, input1, input2)) continue;

        // creo le coordinate del cm e di target
		Coordinate unit_cm = Coordinate(input1);
		Coordinate target = Coordinate(input2);
		
		// seleziono la barca con cui fare la mossa
		NavalUnit* unit = b1.choose_unit(unit_cm);
		
		// controllo che sia stato selezionato correttamente un centro di massa
		// di una navae presente nel campo di battaglia
		if(!unit){
			std::cout << "La coordinata selezionata non corrisponde al cm di nessuna barca" << std::endl;
			continue;
		}

        // salvo la mossa nel log
		log << input1 << " " << input2 << std::endl;
		
		// eseguo l'azione specifica della nave
		unit->action(b1, b2, target);

		break; 
	}
	return 1;
}

std::string Human::get_unit_name() {
	switch(initialized_units_){
		case 1: return "Corazzata 1";
		case 2: return "Corazzata 2";
		case 3: return "Corazzata 3";
		case 4: return "SupportVessel 1";
		case 5: return "SupportVessel 2";
		case 6: return "SupportVessel 3";
		case 7: return "Submarine 1";
		case 8: return "Submarine 2";
		default : break;
	}
	return nullptr; 
}

bool Human::special_commands(Battlefield& b, const std::string& in1, const std::string& in2) {
    // pulizia avvistamenti sonar
	if(in1 == "AA" && in2 == "AA"){
		b.clean_attack('Y');
		return true;
	}

    // pulizia colpi andati a segno
	if(in1 == "BB" && in2 == "BB"){
		//seleziono il tipo di "pulizia"
		b.clean_attack('X');
		return true;
	}

    // pulizia colpi a vuoto
	if(in1 == "CC" && in2 == "CC"){
		//seleziono il tipo di "pulizia"
		b.clean_attack('O');
		return true;
	}

    // visualizzo le griglie di attacco e difesa
	if(in1 == "XX" && in2 == "XX"){
		std::cout << b << std::endl;
		return true;
	}

	return false;
}
