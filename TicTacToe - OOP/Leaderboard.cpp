#include "Leaderboard.h"

/*
	Metoda odpowiadaj¹ca za czytanie pliku i wstawianie danych
	do vectora danych tablicy wyników
*/

void Leaderboard::Read() {
	L_PvC l1;
	L_PvP l2;

	int iterator = 0;
	std::string::size_type sz;

	std::ifstream file1("LB1.txt");
	if (file1.is_open()) {
		std::string line;
		while (std::getline(file1, line)) {
			if (line == "") break;

			if (iterator == 0) {
				l1.Name_Putter(line);
				iterator++;
			}

			else if (iterator == 1) {
				int d_temp = std::stoi(line, &sz);
				l1.Diff_Putter(d_temp);
				iterator++;
			}
			else if (iterator == 2) {
				int s_temp = std::stoi(line, &sz);
				l1.Score_Putter(s_temp);
				iterator++;
			}

			else if (iterator == 3) {
				int r_temp = std::stoi(line, &sz);
				l1.Round_Putter(r_temp);
				iterator++;
			}

			if (line == "#") {
				this->Add_To_LB(l1);
				iterator = 0;
			}
		}
		file1.close();
	}

	std::ifstream file2("LB2.txt");
	if (file2.is_open()) {
		std::string line;
		while (std::getline(file2, line)) {
			if (line == "") break;
			if (iterator == 0) {
				l2.Name1_Putter(line);
				iterator++;
			}

			else if (iterator == 1) {
				l2.Name2_Putter(line);
				iterator++;
			}
			else if (iterator == 2) {
				int s_temp = std::stoi(line, &sz);
				l2.Score_Putter(s_temp);
				iterator++;
			}

			else if (iterator == 3) {
				int r_temp = std::stoi(line, &sz);
				l2.Round_Putter(r_temp);
				iterator++;
			}

			if (line == "#") {
				this->Add_To_LB(l2);
				iterator = 0;
			}
		}
		file1.close();
	}
}

/*
	Metoda odpowiadaj¹ca za zapisywanie danych o tablicy wynikow do pliku
*/

void Leaderboard::Write() {
	std::ofstream file("LB1.txt");
	for (int i = 0; i < this->L1.size(); i++) {
		file << L1[i].Name_Getter() << "\n";
		file << L1[i].Diff_Getter() << "\n";
		file << L1[i].Sc_Getter() << "\n";
		file << L1[i].Rn_Getter() << "\n";
		file << "#\n";
	}
	file.close();

	std::ofstream file2("LB2.txt");
	for (int i = 0; i < this->L2.size(); i++) {
		file2 << L2[i].Name1_Getter() << "\n";
		file2 << L2[i].Name2_Getter() << "\n";
		file2 << L2[i].Sc_Getter() << "\n";
		file2 << L2[i].Rn_Getter() << "\n";
		file2 << "#\n";
	}
	file2.close();
}

/*
	Metoda odpowiada za czyszczenie vectorów ¿eby unikn¹æ
	nadpisywania wyników.
*/

void Leaderboard::Clear() {
	this->L1.erase(this->L1.begin(), this->L1.end());
	this->L2.erase(this->L2.begin(), this->L2.end());
}