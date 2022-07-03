#include "UI.h"

void UI::StartUI()
{
	cout << "Pokemon Duel Simulator" << endl;
	cout << "Greetings Trainers! We are trying to develop a simulator in order to learn more about pokemon." << endl;
	cout << "As of now we currently have 7 pokemon in the system with two different moves\nWe ask that two of you do a battle simulation with a pokemon of your choosing" << endl;
	PokemonList();

	cout << "The starting turn is determined randomly" << endl;
}

void UI::PokemonList()
{
	cout << "\t[1] - Entei\t[4] - Pikachu\t[7] - Stunfisk" << endl;
	cout << "\t[2] - Milotic\t[5] - Groudon" << endl;
	cout << "\t[3] - Torterra\t[6] - Lapras" << endl << endl;
}

void UI::PokemonSelect(int player, Pokemon pokemon)
{
	int input;

	cout << "Player " << player << " select a pokemon : ";
	cin >> input;

	pokemon.setID(input);
	pokemon.GivePokemonData(pokemon.getID());

	cout << "Player " << player << " has chosen " << pokemon.getName() << endl;
}

void UI::BattleUI(Pokemon currPlayer, Pokemon opponent, int playerMaxHP, int opponentMaxHP)
{
	cout << currPlayer.getName() << "\t\t" << currPlayer.getHP() << " / " << playerMaxHP << "HP" << endl;
	cout << opponent.getName() << "\t\t" << opponent.getHP() << " / " << opponentMaxHP << "HP" << endl;


	cout << endl << "What will " << currPlayer.getName() << " do?" << endl;;
	for (int i = 0; i < 2; i++) {
		cout << "[" << i + 1 << "] " << currPlayer.getMoveName(i) << "\t" << currPlayer.getMoveTP(i) << " pp" << endl;
	}
	cout << "[3] Protect\t" << currPlayer.getProtectNum() << "pp" << endl;
	cout << "[4] Charge\t" << currPlayer.getChargeNum() << "pp" << endl;

	cout << "Input : ";
}

void UI::GameOver(Pokemon winner, Pokemon loser, int maxhp1, int maxhp2)
{
	cout << endl << " = = = = = GAME OVER = = = = = " << endl;
	cout << winner.getName() << "\t\t" << winner.getHP() << " / " << maxhp1 << "HP" << endl;
	cout << loser.getName() << "\t\t" << "0 / " << maxhp2 << "HP" << endl;

	cout << winner.getName() << " WINS!" << endl;
}