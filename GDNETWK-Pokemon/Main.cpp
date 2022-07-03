#include <cstdlib>
#include <iostream>
#include "Pokemon.h"
#include "UI.h"
#include "Calculations.h"

using namespace std;

int main() {

	Pokemon player1, player2;

	srand(time(NULL));
	int turn = rand() % 2;

	UI::StartUI();

	UI::PokemonSelect(1, player1);
	UI::PokemonSelect(2, player2);

	int input;
	int maxhp1 = player1.getHP(), maxhp2 = player2.getHP();

	while (player1.getHP() > 0 && player2.getHP() > 0) {
		cout << endl << " = = = = = Player " << turn + 1 << "'s turn = = = = = " << endl;

		if (turn == 0) {

			player1.setProtectState(false);
			UI::BattleUI(player1, player2, maxhp1, maxhp2);
			cin >> input;
			if (Calculations::ResolveMove(player1, player2, input)) turn = 1;
		}
		else if (turn == 1) {

			player2.setProtectState(false);
			UI::BattleUI(player2, player1, maxhp2, maxhp1);
			cin >> input;
			if (Calculations::ResolveMove(player2, player1, input)) turn = 0;

		}
	} //Combat End
	if (player1.getHP() <= 0) UI::GameOver(player2, player1, maxhp2, maxhp1);
	else UI::GameOver(player1, player2, maxhp1, maxhp2);
}