#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

enum type {
	fire, water, grass, ground, ice, electric, none
};

struct pokemon{

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

void pokemonList(){

	cout << "\t[1] - Entei\t[4] - Pikachu\t[7] - Stunfisk" << endl;
	cout << "\t[2] - Milotic\t[5] - Groudon" << endl;
	cout << "\t[3] - Torterra\t[6] - Lapras" << endl << endl;

}

void startUI(){

cout << "Pokemon Duel Simulator" << endl;
cout << "Greetings Trainers! We are trying to develop a simulator in order to learn more about pokemon." << endl;
cout << "As of now we currently have 7 pokemon in the system with two different moves\nWe ask that two of you do a battle simulation with a pokemon of your choosing" << endl;
pokemonList();

cout << "The starting turn is determined randomly" << endl;
}

void givePokemonData(pokemon *pokemon){

	switch(pokemon->id){

		case 1: //Entei

				pokemon->name = "Entei";
				pokemon->hp = 150;

				pokemon->type[0] = fire;
				pokemon->type[1] = none;

				pokemon->moveDmg[0] = 30;
				pokemon->moveDmg[1] = 30;

				pokemon->moveTP[0] = 5;
				pokemon->moveTP[1] = 5;

				pokemon->moveName[0] = "Fire Blast";
				pokemon->moveType[0] = fire;

				pokemon->moveName[1] = "Earthquake";
				pokemon->moveType[1] = ground;
				break;

		case 2://Milotic

				pokemon->name = "Milotic";
				pokemon->hp = 200;

				pokemon->type[0] = water;
				pokemon->type[1] = none;

				pokemon->moveDmg[0] = 20;
				pokemon->moveDmg[1] = 20;

				pokemon->moveTP[0] = 7;
				pokemon->moveTP[1] = 7;

				pokemon->moveName[0] = "Scald";
				pokemon->moveType[0] = water;

				pokemon->moveName[1] = "Ice Beam";
				pokemon->moveType[1] = ice;
				break;

		case 3://Torterra

				pokemon->name = "Torterra";
				pokemon->hp = 220;

				pokemon->type[0] = grass;
				pokemon->type[1] = ground;

				pokemon->moveDmg[0] = 20;
				pokemon->moveDmg[1] = 40;

				pokemon->moveTP[0] = 7;
				pokemon->moveTP[1] = 5;

				pokemon->moveName[0] = "Dig";
				pokemon->moveType[0] = ground;

				pokemon->moveName[1] = "Leaf Storm";
				pokemon->moveType[1] = grass;
				break;

		case 4://Pikachu

				pokemon->name = "Pikachu";
				pokemon->hp = 120;

				pokemon->type[0] = electric;
				pokemon->type[1] = none;

				pokemon->moveName[0] = "Thunderbolt";
				pokemon->moveDmg[0] = 10;
				pokemon->moveType[0] = electric;
				pokemon->moveTP[0] = 10;

				pokemon->moveName[1] = "Dig";
				pokemon->moveDmg[1] = 20;
				pokemon->moveType[1] = ground;
				pokemon->moveTP[1] = 7;
				break;

		case 5://Groudon

				pokemon->name = "Groudon";
				pokemon->hp = 150;

				pokemon->type[0] = grass;
				pokemon->type[1] = none;

				pokemon->moveDmg[0] = 40;
				pokemon->moveDmg[1] = 30;

				pokemon->moveTP[0] = 5;
				pokemon->moveTP[1] = 5;

				pokemon->moveName[0] = "Fissure";
				pokemon->moveType[0] = ground;

				pokemon->moveName[1] = "Fire Blast";
				pokemon->moveType[1] = fire;
				break;

		case 6://Lapras;

				pokemon->name = "Lapras";
				pokemon->hp = 190;

				pokemon->moveDmg[0] = 20;
				pokemon->moveDmg[1] = 20;

				pokemon->moveTP[0] = 7;
				pokemon->moveTP[1] = 7;

				pokemon->type[0] = ice;
				pokemon->type[1] = water;

				pokemon->moveName[0] = "Ice Beam";
				pokemon->moveType[0] = ice;

				pokemon->moveName[1] = "Scald";
				pokemon->moveType[1] = water;
				break;

		case 7://Stunfisk

				pokemon->name = "Stunfisk";
				pokemon->hp = 130;

				pokemon->moveDmg[0] = 10;
				pokemon->moveDmg[1] = 30;

				pokemon->moveTP[0] = 10;
				pokemon->moveTP[1] = 5;

				pokemon->type[0] = ground;
				pokemon->type[1] = electric;

				pokemon->moveName[0] = "Water Gun";
				pokemon->moveType[0] = water;

				pokemon->moveName[1] = "Earthquake";
				pokemon->moveType[1] = ground;
				break;
	}

}

void pokemonSelect(int player, pokemon *pokemon){

	int input;

	cout << "Player " << player << " select a pokemon : ";
	cin >> input;
	
	pokemon->id = input;
	givePokemonData(pokemon);

	cout << "Player " << player << " has chosen " << pokemon->name << endl;

}

float stabCheck(pokemon attacker, int moveType){ //Return multiplier

	if(attacker.type[0] == moveType || attacker.type[1] == moveType) return 1.5;
	else return 1;

}

float effectivenessCheck(int moveType, pokemon defender){ // Return multiplier

// Fire - r | Water - u  | Grass - g | Ground - b | Ice - w | Electric - y | None - n

	switch (moveType) {
		case fire:
			for(int i = 0; i < 2; i++){
				if(defender.type[i] == fire || defender.type[i] == water || defender.type[i] == ground) return 0.5;
				else if(defender.type[i] == grass || defender.type[i] == ice) return 2;
			}
		break;

		case water:
				for(int i = 0; i < 2; i++){
					if(defender.type[i] == water || defender.type[i] == grass) return 0.5;
					else if(defender.type[i] == fire || defender.type[i] == ground) return 2;
				}
		break;

		case grass:
				for(int i = 0; i < 2; i++){
					if(defender.type[i] == fire || defender.type[i] == grass) return 0.5;
					else if(defender.type[i] == water || defender.type[i] == ground) return 2;
				}
		break;

		case electric:
				for(int i = 0; i < 2; i++){
					if(defender.type[i] == grass) return 0.5;
					else if(defender.type[i] == water ) return 2;
				 	else if(defender.type[i] == ground) return 0;
				}
		break;

		case ground:
				for(int i = 0; i < 2; i++){
					if(defender.type[i] == water || defender.type[i] == grass || defender.type[i] == ice) return 0.5;
					else if(defender.type[i] == fire || defender.type[i] == electric) return 2;
				}
		break;

		case ice:
				for(int i = 0; i < 2; i++){
					if(defender.type[i] == fire) return 0.5;
					else if(defender.type[i] == water || defender.type[i] == grass || defender.type[i] == ground) return 2;
				}
		break;

		return 1;
	}

}

int dmgCalculation(pokemon attacker, pokemon defender, int move){
	int dmg = attacker.moveDmg[move];

	if(attacker.chargeState == true) dmg *= 2;

	dmg *= stabCheck(attacker, attacker.moveType[move]);
	dmg *= effectivenessCheck(attacker.moveType[move], defender);

	cout << "You inflicted " << dmg << " points of damage!" << endl;

	return dmg;
}

void battleUI(pokemon currPlayer, pokemon opponent, int playerMaxHP, int opponentMaxHP){

	cout << currPlayer.name << "\t\t" << currPlayer.hp << " / " << playerMaxHP << "HP" << endl;
	cout << opponent.name << "\t\t" << opponent.hp << " / " << opponentMaxHP << "HP" << endl;


	cout << endl<<"What will " << currPlayer.name << " do?" << endl;;
	for(int i = 0; i < 2; i++){
		cout << "["<<i+1<<"] " << currPlayer.moveName[i] << "\t" << currPlayer.moveTP[i] << " pp" << endl;
	}
	cout << "[3] Protect\t" << currPlayer.protectN << "pp" << endl;
	cout << "[4] Charge\t" << currPlayer.chargeN << "pp" << endl;

	cout << "Input : ";
}

bool resolveMove(pokemon *currPlayer, pokemon *opponent, int move){

	switch(move){
		case 1:
		case 2:
			if (opponent->protectState == true) cout << "Your damage was prevented!" << endl;
			else opponent->hp -= dmgCalculation(*currPlayer, *opponent, move-1);

			currPlayer->moveTP[move]--;
			break;

		case 3:
			if(currPlayer->protectState == false){
				currPlayer->protectState = true;
				currPlayer->protectN--;
			}else cout << "You used protect last turn!" << endl;
			break;

		case 4:
			currPlayer->chargeState = true;
			currPlayer->chargeN--;
			break;
		default:
			cout << "Invalid move. Try again" << endl << endl;
			return false;
	}
	return true;
}

void gameOver(pokemon winner, pokemon loser, int maxhp1, int maxhp2) {
	
	cout << endl << " = = = = = GAME OVER = = = = = " << endl;
	cout << winner.name << "\t\t" << winner.hp << " / " << maxhp1 << "HP" << endl;
	cout << loser.name << "\t\t" << "0 / " << maxhp2 << "HP" << endl;
	
	cout << winner.name << " WINS!" << endl;
}

int main(){

	pokemon player1, player2;

	srand(time(NULL));
	int turn = rand() % 2;

	startUI();

	pokemonSelect(1, &player1);
	pokemonSelect(2, &player2);

	int input;
	int maxhp1 = player1.hp, maxhp2 = player2.hp;

	while(player1.hp > 0 && player2.hp > 0){
		cout << endl << " = = = = = Player " << turn+1 << "'s turn = = = = = " << endl;

		if(turn == 0){

			player1.protectState = false;
			battleUI(player1, player2, maxhp1, maxhp2);
			cin >> input;
			if(resolveMove(&player1, &player2, input)) turn = 1;
		}
		else if(turn == 1){

			player2.protectState = false;
			battleUI(player2, player1, maxhp2, maxhp1);
			cin >> input;
			if(resolveMove(&player2, &player1, input)) turn = 0;

		}
	}//Combat End
	if (player1.hp <= 0) gameOver(player2, player1, maxhp2, maxhp1);
	else gameOver(player1, player2, maxhp1, maxhp2);
}
