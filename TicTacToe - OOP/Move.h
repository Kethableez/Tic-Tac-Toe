#pragma once

#include <iostream>

#include "Board.h"

#define PLAYER 'X'
#define OPPONENT 'O'

class Move {
public:
	/*
		row i col atrybuty zmienne w kazdej rundzie
		dlatego s¹ publiczne
	*/

	int row = -1;
	int col = -1;

	virtual void GetMove(Board* B) = 0;
	virtual void PutMove(Board* B) = 0;
};
