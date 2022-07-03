#pragma once
#include <iostream>
#include "Pokemon.h"

using namespace std;

class Calculations
{
public:
	bool static ResolveMove(Pokemon &currPlayer, Pokemon &opponent, int move);

private:
	enum ElementalType { fire, water, grass, ground, ice, electric, none };

	float static StabCheck(Pokemon attacker, int moveType); //Return multiplier
	float static EffectivenessCheck(int moveType, Pokemon defender); //Return multiplier
	int static DMGCalculation(Pokemon attacker, Pokemon defender, int move);
};