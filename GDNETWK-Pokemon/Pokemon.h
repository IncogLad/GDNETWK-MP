#pragma once
#include <string>

using namespace std;

class Pokemon
{
public:
	enum ElementalType { fire, water, grass, ground, ice, electric, none };
	void GivePokemonData(int input);

	// Getters for private variables
	int getID();
	string getName();
	int getType(int index);
	int getHP();
	string getMoveName(int index);
	int getMoveDMG(int index);
	int getMoveTP(int index);
	int getMoveType(int index);
	int getChargeNum();
	int getProtectNum();
	bool isChargeState();
	bool isProtectedState();

	// Setters for private variables
	void setID(int newID);
	void setHP(int dmg);
	void setMoveTP(int index);
	void setChargeNum();
	void setProtectNum();
	void setChargeState(bool newState);
	void setProtectState(bool newState);

private:
	int id = 0;
	string name;
	int type[2];

	int hp = 0;

	string moveName[2];
	int moveDmg[2];
	int moveTP[2];
	int moveType[2];

	int chargeN = 5, protectN = 5;
	bool chargeState = false, protectState = false;
};

