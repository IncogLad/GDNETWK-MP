#include "Pokemon.h"

void Pokemon::GivePokemonData(int input)
{
	switch (input)
	{
	case 1: //Entei

		name = "Entei";
		hp = 150;

		type[0] = fire;
		type[1] = none;

		moveName[0] = "Fire Blast";
		moveDmg[0] = 30;
		moveType[0] = fire;
		moveTP[0] = 5;

		moveName[1] = "Earthquake";
		moveDmg[1] = 30;
		moveType[1] = ground;
		moveTP[1] = 5;
		break;

	case 2: //Milotic

		name = "Milotic";
		hp = 200;

		type[0] = water;
		type[1] = none;

		moveName[0] = "Scald";
		moveDmg[0] = 20;
		moveType[0] = water;
		moveTP[0] = 7;

		moveName[1] = "Ice Beam";
		moveDmg[1] = 20;
		moveType[1] = ice;
		moveTP[1] = 7;
		break;

	case 3: //Torterra

		name = "Torterra";
		hp = 220;

		type[0] = grass;
		type[1] = ground;

		moveName[0] = "Dig";
		moveDmg[0] = 20;
		moveType[0] = ground;
		moveTP[0] = 7;

		moveName[1] = "Leaf Storm";
		moveDmg[1] = 40;
		moveType[1] = grass;
		moveTP[1] = 5;
		break;

	case 4: //Pikachu

		name = "Pikachu";
		hp = 120;

		type[0] = electric;
		type[1] = none;

		moveName[0] = "Thunderbolt";
		moveDmg[0] = 10;
		moveType[0] = electric;
		moveTP[0] = 10;

		moveName[1] = "Dig";
		moveDmg[1] = 20;
		moveType[1] = ground;
		moveTP[1] = 7;
		break;

	case 5: //Groudon

		name = "Groudon";
		hp = 150;

		type[0] = grass;
		type[1] = none;

		moveName[0] = "Fissure";
		moveDmg[0] = 40;
		moveType[0] = ground;
		moveTP[0] = 5;

		moveName[1] = "Fire Blast";
		moveDmg[1] = 30;
		moveType[1] = fire;
		moveTP[1] = 5;
		break;

	case 6: //Lapras;

		name = "Lapras";
		hp = 190;

		type[0] = ice;
		type[1] = water;

		moveName[0] = "Ice Beam";
		moveDmg[0] = 20;
		moveType[0] = ice;
		moveTP[0] = 7;

		moveName[1] = "Scald";
		moveDmg[1] = 20;
		moveType[1] = water;
		moveTP[1] = 7;
		break;

	case 7: //Stunfisk

		name = "Stunfisk";
		hp = 130;

		type[0] = ground;
		type[1] = electric;

		moveName[0] = "Water Gun";
		moveDmg[0] = 10;
		moveType[0] = water;
		moveTP[0] = 10;

		moveName[1] = "Earthquake";
		moveDmg[1] = 30;
		moveType[1] = ground;
		moveTP[1] = 5;
		break;
	}
}

#pragma region Getters
int Pokemon::getID()
{
	return id;
}

string Pokemon::getName()
{
	return name;
}

int Pokemon::getType(int index)
{
	switch (index)
	{
		case 0:
			return type[0];
			break;
		case 1:
			return type[1];
			break;
	}
}

int Pokemon::getHP()
{
	return hp;
}

string Pokemon::getMoveName(int index)
{
	switch (index)
	{
		case 0:
			return moveName[0];
			break;
		case 1:
			return moveName[1];
			break;
	}
}

int Pokemon::getMoveDMG(int index)
{
	switch (index)
	{
		case 0:
			return moveDmg[0];
			break;
		case 1:
			return moveDmg[1];
			break;
	}
}

int Pokemon::getMoveTP(int index)
{
	switch (index)
	{
		case 0:
			return moveTP[0];
			break;
		case 1:
			return moveTP[1];
			break;
	}
}

int Pokemon::getMoveType(int index)
{
	switch (index)
	{
		case 0:
			return moveType[0];
			break;
		case 1:
			return moveType[1];
			break;
	}
}

int Pokemon::getChargeNum()
{
	return chargeN;
}

int Pokemon::getProtectNum()
{
	return protectN;
}

bool Pokemon::isChargeState()
{
	return chargeState;
}

bool Pokemon::isProtectedState()
{
	return protectState;
}
#pragma endregion

#pragma region Setters
void Pokemon::setID(int newID)
{
	id = newID;
}

void Pokemon::setHP(int dmg)
{
	hp -= dmg;
}

void Pokemon::setMoveTP(int index)
{
	switch (index) 
	{
		case 0:
			moveTP[0] -= 1;
			break;
		case 1:
			moveTP[1] -= 1;
			break;
	}
}

void Pokemon::setChargeNum()
{
	chargeN -= 1;
}

void Pokemon::setProtectNum()
{
	protectN -= 1;
}

void Pokemon::setChargeState(bool newState)
{
	chargeState = newState;
}

void Pokemon::setProtectState(bool newState)
{
	protectState = newState;
}
#pragma endregion