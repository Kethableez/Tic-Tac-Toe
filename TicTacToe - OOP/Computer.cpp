#include "Computer.h"

//Konstruktor parametryczny wstawiajacy poziom trudnosci
Computer::Computer(int diff) {
	this->difficult = diff;
}

//Metoda odpowiadajaca za pobranie najlepzego mozliwego ruchu dla komputera
void Computer::GetMove(Board* B) {
	int bestVal = INF;
	int depth = this->difficult;

	this->row = -1;
	this->col = -1;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (!B->isAlready(i, j)) {
				B->PutOnBoard(i, j, OPPONENT);
				int best = minimax(B, depth, true);
				B->PutOnBoard(i, j, ' ');

				if (best < bestVal) {
					bestVal = best;
					this->row = i;
					this->col = j;
				}
			}
		}
	}
}

//Metoda odpowiadajaca za wstawienie ruchu na plansze 
void Computer::PutMove(Board* B) {
	B->PutOnBoard(this->row, this->col, OPPONENT);
}

/*
	Algorytm Minimax w wersji podstawowej do znaleznienia najlepszego ruchu.
	Zwraca	0 w przypadku remisu
			10 w przypadku gracza maksymalizujacego
			-10 w przyapdku gracza minimalizujacego
*/
int Computer::minimax(Board* B, int depth, bool isMaximizing) {
	int result = B->Evaluate();

	if (result == 10) return result;
	if (result == -10) return result;
	
	if (B->isMoveLeft() == false or depth == 0) return 0;

	if (isMaximizing) {
		int best = nINF;

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (!B->isAlready(i, j)) {

					B->PutOnBoard(i, j, PLAYER);
					best = std::max(best, minimax(B, depth - 1, !isMaximizing));
					B->PutOnBoard(i, j, ' ');
				}
			}
		}
		return best;
	}

	else {
		int best = INF;

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (!B->isAlready(i, j)) {

					B->PutOnBoard(i, j, OPPONENT);
					best = std::min(best, minimax(B, depth - 1, !isMaximizing));
					B->PutOnBoard(i, j, ' ');
				}
			}
		}
		return best;
	}
}