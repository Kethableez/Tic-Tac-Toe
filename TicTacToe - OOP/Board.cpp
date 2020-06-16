#include "Board.h"

//Konstruktor klasy
Board::Board() {
	this->B_ptr = new char* [SIZE];

	for (int i = 0; i < SIZE; i++) {
		this->B_ptr[i] = new char[SIZE];
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			this->B_ptr[i][j] = ' ';
		}
	}
}

//Czyszczenie tablicy do kolejnych rozgrywek
void Board::Clear() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			this->B_ptr[i][j] = ' ';
		}
	}
}

//Destruktor
Board::~Board() {
	for (int i = 0; i < SIZE; i++) {
		delete[] this->B_ptr[i];
	}
}

//Wyswietlanie stanu rozgrywki
void Board::Show() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			std::cout << this->B_ptr[i][j];
			if (j < 2) std::cout << "|";
		}
		std::cout << std::endl;
		if(i < 2) std::cout << "-+-+- \n";
	}
}

//Metoda sprawdzaj¹ca czy zosta³ do wykonania jakiœ ruch
bool Board::isMoveLeft() {
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (this->B_ptr[i][j] == ' ') counter++;
		}
	}
	if (counter > 0) return true;
	else return false;
}

//Metoda sprawdzaj¹ca czy dany ruch pojawi³ sie ju¿ na planszy 
bool Board::isAlready(int row, int col) {
	if (this->B_ptr[row][col] != ' ') return true;
	else return false;
}

//Metoda odpowiedzialna za przeszukanie tablicy rozgrywki w celu sprawdzenia wygranej
int Board::Evaluate() {
	if (this->B_ptr[0][0] != ' ') {
		for (int i = 1; i < SIZE; i++) {
			if (this->B_ptr[0][0] != this->B_ptr[i][i]) break;
			else if (i == SIZE - 1) {
				if (this->B_ptr[0][0] == 'X') return 10;
				else return -10;
			}
		}
	}

	for (int j = 0; j < SIZE; j++) {
		if (this->B_ptr[0][j] != ' ') {
			for (int i = 1; i < SIZE; i++) {
				if (this->B_ptr[0][j] != this->B_ptr[i][j]) break;
				else if (i == SIZE - 1) {
					if (this->B_ptr[0][j] == 'X') return 10;
					else return -10;
				}
			}
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (this->B_ptr[i][0] != ' ') {
			for (int j = 1; j < SIZE; j++) {
				if (this->B_ptr[i][0] != this->B_ptr[i][j]) break;
				else if (j == SIZE - 1) {
					if (this->B_ptr[i][0] == 'X') return 10;
					else return -10;
				}
			}
		}
	}

	if (this->B_ptr[0][SIZE - 1] != ' ') {
		int j = SIZE - 1;
		for (int i = 0; i < SIZE; i++) {
			if (this->B_ptr[0][SIZE - 1] != this->B_ptr[i][j - i])break;
			else if (i == SIZE - 1) {
				if (this->B_ptr[0][SIZE - 1] == 'X') return 10;
				else return -10;
			}
		}
	}

	return 0;
}