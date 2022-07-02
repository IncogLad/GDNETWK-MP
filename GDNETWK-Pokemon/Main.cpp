#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "Pokemon.h"

using namespace std;

int main() {

	Pokemon player1, player2;

	srand(time(NULL));
	int turn = rand() % 2;

	startUI();

	pokemonSelect(1, &player1);
	pokemonSelect(2, &player2);

	int input;
	int maxhp1 = player1.hp, maxhp2 = player2.hp;

	while (player1.hp > 0 && player2.hp > 0) {
		cout << endl << " = = = = = Player " << turn + 1 << "'s turn = = = = = " << endl;

		if (turn == 0) {

			player1.protectState = false;
			battleUI(player1, player2, maxhp1, maxhp2);
			cin >> input;
			if (resolveMove(&player1, &player2, input)) turn = 1;
		}
		else if (turn == 1) {

			player2.protectState = false;
			battleUI(player2, player1, maxhp2, maxhp1);
			cin >> input;
			if (resolveMove(&player2, &player1, input)) turn = 0;

		}
	}//Combat End
	if (player1.hp <= 0) gameOver(player2, player1, maxhp2, maxhp1);
	else gameOver(player1, player2, maxhp1, maxhp2);
}