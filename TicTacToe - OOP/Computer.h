#pragma once

#include "Move.h"
#include <algorithm>

#define nINF -1000;
#define INF 1000;

class Computer : public Move {
	char Sign = OPPONENT;
	int difficult;
public:
	Computer(int diff);
	virtual void GetMove(Board* B);
	virtual void PutMove(Board* B);
	
	int minimax(Board* B, int depth, bool isMaximizing);

	/*
		Puter klasy Computer, wstawiaj�cy zmienn� diff kt�ra odpowiada
		za poziom trudno�ci
	*/

	void Diff_Putter(int diff){
		this->difficult = diff;
	}
};