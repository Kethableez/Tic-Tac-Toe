#pragma once

#include <iostream>
#include <string>

class L_PvC{
	std::string P_name;
	int diff_level;
	int score;
	int rounds;

public:
	// Przeci¹zenie operatora wyœwietlania klasy L_PvC
	friend std::ostream& operator << (std::ostream& stream, L_PvC& datas) {
		stream << "Player1 name: " << datas.P_name << "| Difficult: " << datas.diff_level<<
			"| Score: " << datas.score << "| Rounds amount: " << datas.rounds << "\n";

		return stream;
	}

	L_PvC();
	L_PvC(std::string name, int diff, int sc, int rn);

	//Gettery dla klasy L_PvC

	std::string Name_Getter() {
		return this->P_name;
	}

	int Diff_Getter() {
		return this->diff_level;
	}

	int Sc_Getter() {
		return this->score;
	}

	int Rn_Getter() {
		return this->rounds;
	}
	
	//Puttery dla klasy L_PvC

	void Name_Putter(std::string n) {
		this->P_name = n;
	}

	void Diff_Putter(int diff) {
		this->diff_level = diff;
	}

	void Score_Putter(int sc) {
		this->score = sc;
	}

	void Round_Putter(int rn) {
		this->rounds = rn;
	}
};

