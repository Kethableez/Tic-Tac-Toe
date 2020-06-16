#include "Menu.h"


//Wyswietlenie dostepnch opcji
void Menu() {
	std::cout << "----------------\n";
	std::cout << "Kolko - Krzyzyk \n";
	std::cout << "----------------\n";
	std::cout << std::endl;
	std::cout << "Dostepne opcje: \n";
	std::cout << "1. Nowa gra przeciwko komputerowi. \n";
	std::cout << "2. Nowa gra dla dwoch graczy. \n";
	std::cout << "3. Tablica wynikow. \n";
	std::cout << "4. Wyjscie z programu. \n";
}

//Pobranie informacji o wybranej opcji przez gracza
int Option() {
	int opt;
	std::cout << "Twoja opcja > ";
	std::cin >> opt;
	return opt;
}

//Pobieranie informacji o poziomie trudnoœci (funkcja rekurencyjna)
int Diff() {
	int lvl;
	std::cout << "Poziom trudnosci: \n";
	std::cout << "1. Latwy \n2. Sredni \n3. Trudny\n";
	std::cin >> lvl;
	if (lvl == 1) return 4;
	else if (lvl == 2) return 5;
	else if (lvl == 3) return 8;
	else {
		std::cout << "Niepoprawna opcja! \n";
		lvl = Diff();
	}
}


//Pobieranie informacji o imieniu gracza
std::string Get_Name() {
	std::string temp;
	std::cout << "Imie > ";
	std::cin >> temp;

	return temp;
}

/*
	Funkcje odpowiadaj¹ce za wyswietlenie stosownego komunikatu
	po zakonczonej rozgrywce.
*/
void Statement(int score, std::string name1, std::string name2) {
	if (score == 10) {
		std::cout << "Wygral gracz " << name1 << std::endl;
	}
	else if (score == -10) {
		std::cout << "Wygral gracz " << name2 << std::endl;
	}
	else {
		std::cout << "Remis" << std::endl;
	}
}

void Statement(int score, std::string name1) {
	if (score == 10) {
		std::cout << "Wygral gracz " << name1 << std::endl;
	}
	else if (score == -10) {
		std::cout << "Wygral komputer" << std::endl;
	}
	else {
		std::cout << "Remis" << std::endl;
	}
}

// Funkcja wyswietlajaca stosowny komunikat o rundzie i turze gracza
void Rounds(int round) {
	std::cout << "------------------------------ \n";
	if (round % 2 == 1) std::cout << "Runda " << round<<" - Tura X" << std::endl;
	else std::cout << "Runda " << round << " - Tura O" << std::endl;
	std::cout << "------------------------------ \n";
}