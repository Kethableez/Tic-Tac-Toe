#include "Player.h"

//Konstruktor parametryczny

Player::Player(char _c) {
	this->row = -1;
	this->col = -1;
	this->Sign = _c;
}

/*
	Metoda odpowiadaj¹ca za pobieranie informacji o ruchu gracza;
	Ruch jest przechowywany jako indeks macierzy 3x3, i jest numerowany od
	0 do SIZE - 1, w tym wypadku od 0 do 2
*/
void Player::GetMove(Board* B) {
	int r, c;
	bool move_happened = true;

	while (move_happened) {
		std::cout << "Wprowadz ruch!\n";
		std::cout << "Rzad: ";
		while (true) {
			if (!(std::cin >> r) || r < 0 || r > SIZE) {
				std::cin.clear();
				std::cin.sync();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.sync();
				std::cout << "Blad! Niepoprawna wartosc, sprobuj ponownie\n";
				std::cout << "Rzad: ";
			}
			else break;
		}

		std::cout << "Kolumna: ";
		while (true) {
			if (!(std::cin >> c) || c < 0 || c > SIZE - 1) {
				std::cin.clear();
				std::cin.sync();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::cin.sync();
				std::cout << "Blad! Niepoprawna wartosc, sprobuj ponownie! \n";
				std::cout << "Kolumna: ";
			}
			else break;
		}

		if (!B->isAlready(r, c)) move_happened = false;
		else std::cout << "Ruch juz sie pojawil, sprobuj ponownie! \n";
	}
	
	this->row = r;
	this->col = c;
}

//Metoda odpowiada za przekazywanie ruchu do wstawienia na planszê
void Player::PutMove(Board* B) {
	B->PutOnBoard(this->row, this->col, this->Sign);
}