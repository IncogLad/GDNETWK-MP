#pragma once
#include <iostream>
#include "Pokemon.h"

using namespace std;

class UI
{
public:
	void static StartUI();
	void static PokemonSelect(int player, Pokemon &pokemon);
	void static BattleUI(Pokemon currPlayer, Pokemon opponent, int playerMaxHP, int opponentMaxHP);
	void static GameOver(Pokemon winner, Pokemon loser, int maxhp1, int maxhp2);

private:
	void static PokemonList();
};