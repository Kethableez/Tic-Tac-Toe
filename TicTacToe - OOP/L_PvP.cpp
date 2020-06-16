#include "L_PvP.h"

//Konstruktor klasy
L_PvP::L_PvP() {
	this->P1_name = " ";
	this->P2_name = " ";
	this->rounds = 0;
	this->score = 0;
}

//Konstruktor parametryczny
L_PvP::L_PvP(std::string n1, std::string n2, int sc, int rn) {
	this->P1_name = n1;
	this->P2_name = n2;
	this->score = sc;
	this->rounds = rn;
}
