#pragma once

#include <iostream>

#define SIZE 3

class Board{
	char** B_ptr;

public:
	Board();
	~Board();

	int Evaluate();
	void Show();

	bool isMoveLeft();
	bool isAlready(int row, int col);

	/*
		Metoda do wstawiania znaku do tablicy rozgrywki
	*/

	void PutOnBoard(int row, int col, char s) {
		this->B_ptr[row][col] = s;
	}

	void Clear();
};

