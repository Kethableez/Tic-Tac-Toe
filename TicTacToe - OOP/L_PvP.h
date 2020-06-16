#pragma once

#include <iostream>
#include <string>


class L_PvP{
	std::string P1_name;
	std::string P2_name;
	int score;
	int rounds;
public:

	// Przeci¹zenie operatora wyœwietlania klasy L_PvP
	friend std::ostream& operator << (std::ostream& stream, L_PvP& datas) {
		stream << "Player1 name: " << datas.P1_name << "| Player2 name: " << datas.P2_name <<
			"| Score: " << datas.score << "| Rounds amount: " << datas.rounds << "\n";
		
		return stream;
	}

	L_PvP();
	L_PvP(std::string n1, std::string n2, int sc, int rn);

	//Gettery dla klasy L_PvP

	std::string Name1_Getter() {
		return this->P1_name;
	}

	std::string Name2_Getter() {
		return this->P2_name;
	}

	int Sc_Getter() {
		return this->score;
	}

	int Rn_Getter() {
		return this->rounds;
	}

	//Puttery dla klasy L_PvP

	void Name1_Putter(std::string n) {
		this->P1_name = n;
	}

	void Name2_Putter(std::string n) {
		this->P2_name = n;
	}

	void Score_Putter(int sc) {
		this->score = sc;
	}

	void Round_Putter(int rn) {
		this->rounds = rn;
	}
};

