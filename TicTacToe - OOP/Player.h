#pragma once

#include "Move.h"

class Player : public Move {
	char Sign;
public:
	Player(char _c);
	virtual void GetMove(Board* B);
	virtual void PutMove(Board* B);

};