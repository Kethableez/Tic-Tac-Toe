#include "L_PvC.h"

//Konstruktor klasy
L_PvC::L_PvC() {
	this->P_name = " ";
	this->diff_level = 0;
	this->rounds = 0;
	this->score = 0;
}

//Konstruktor parametryczny
L_PvC::L_PvC(std::string name, int diff, int sc, int rn) {
	this->P_name = name;
	this->diff_level = diff;
	this->score = sc;
	this->rounds = rn;
}
