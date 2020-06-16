#include "Board.h"
#include "Player.h"
#include "Computer.h"
#include "Menu.h"
#include "Leaderboard.h"

int main() {
	//Deklaracja tablicy
	Board* B = new Board();
	
	/*
		Deklaracja ruchów:
		m - WskaŸnik polimorficzny
		c, p1, p2 - ruchy komputera oraz graczy.
	*/
	Move* m;
	Computer c(0);
	Player p1(PLAYER);
	Player p2(OPPONENT);

	/*
		Deklaracja listy wyników:
		LB - WskaŸnik na klasê listy.
		l1, l2 - obiekty posiadaj¹ce dane o wygranej rundzie
	*/
	Leaderboard* LB = new Leaderboard();
	L_PvC l1;
	L_PvP l2;

	/*
		Deklaracja pozosta³ych zmiennych
		dl - poziom trudnosci
		round - numer rundy
		score - wynik
		Game_over - czy gra zosta³a zakoñczona
		opt - opcja
		name1, name2 - imie lub nick gracza
	*/
	int dl = 0;
	int round = 0;
	int score = 0;
	bool Game_Over = false;
	int opt;

	std::string name1, name2;

	while (!Game_Over) {
		Menu();
		opt = Option();


		switch (opt) {
			/*
				Opcja numer 1:
				Grcz vs Komputer
			*/

		case 1:
			dl = Diff();
			name1 = Get_Name();
			c.Diff_Putter(dl);
			round = 1;

			while (round < 10 and score == 0) {
				B->Show();
				std::cout << std::endl;

				Rounds(round);
				if (round % 2 == 1) m = &p1;
				else m = &c;

				m->GetMove(B);
				m->PutMove(B);
				score = B->Evaluate();
				round++;
			}
			B->Show();
			Statement(score, name1);

			l1.Name_Putter(name1);
			l1.Diff_Putter(dl);
			l1.Round_Putter(round-1);
			l1.Score_Putter(score);
			LB->Add_To_LB(l1);


			round = 0;
			dl = 0;
			score = 0;
			B->Clear();
			break;

		/*
			Opcja numer 1:
			Gracz vs Gracz
		*/

		case 2:
			std::cout << "Podaj imie pierwszego gracza\n";
			name1 = Get_Name();

			std::cout << "Podaj imie drugiego gracza\n";
			name2 = Get_Name();

			round = 1;
			while (round < 10 and score == 0) {
				B->Show();
				std::cout << std::endl;

				Rounds(round);
				if (round % 2 == 1) m = &p1;
				else m = &p2;

				m->GetMove(B);
				m->PutMove(B);
				score = B->Evaluate();
				round++;
			}
			B->Show();
			Statement(score, name1, name2);

			l2.Name1_Putter(name1);
			l2.Name2_Putter(name2);
			l2.Round_Putter(round);
			l2.Score_Putter(score);
			LB->Add_To_LB(l2);

			round = 0;
			score = 0;
			B->Clear();
			break;

			/*
				Wyswietlenie tablicy wynikow
			*/
		
		case 3:
			LB->Read();
			LB->Write();


			std::cout << "---------------------------------------\n";
			std::cout << "TABLICA WYNIKOW: Gracz kontra komputer \n";
			std::cout << "---------------------------------------\n";
			LB->Show_Leaderboard_1();
			std::cout << "---------------------------------------\n";
			std::cout << "TABLICA WYNIKOW: Gracz kontra gracz	 \n";
			std::cout << "---------------------------------------\n";
			LB->Show_Leaderboard_2();
			LB->Clear();
			break;

			/*
				Koniec dzialania programu
			*/

		case 4:
			Game_Over = true;
			break;

		default:
			std::cout << "Niepoprawna opcja! \n";
			break;
		}
	}

	delete B;
}