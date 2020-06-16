#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "L_PvC.h"
#include "L_PvP.h"

class Leaderboard{
	std::vector<L_PvC> L1;
	std::vector<L_PvP> L2;
public:
	//Metda odpowiadaj¹ca za wstawianie do listy wyników (Gracz kontra komputer)
	void Add_To_LB(L_PvC d) {
		this->L1.push_back(d);
	}

	//Metda odpowiadaj¹ca za wstawianie do listy wyników (Gracz kontra gracz)
	void Add_To_LB(L_PvP d) {
		this->L2.push_back(d);
	}

	//Metoda odpowiadaj¹ca za wyœwietlanie listy wyników (Gracz kontra komputer)
	void Show_Leaderboard_1() {
		for (int i = 0; i < this->L1.size(); i++) {
			std::cout << this->L1[i];
		}
	}

	//Metoda odpowiadaj¹ca za wyœwietlanie listy wyników (Gracz kontra gracz)
	void Show_Leaderboard_2() {
		for (int i = 0; i < this->L2.size(); i++) {
			std::cout << this->L2[i];
		}
	}

	void Clear();
	void Read();
	void Write();
};

