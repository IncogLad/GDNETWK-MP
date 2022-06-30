#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startUI(){  //Displays the start and pokemon list
	
	printf("\n\t\t\tPokemon Duel Simulator\n");
	printf("Greetings Trainers! We are trying to develop a simulator in order to learn more about pokemon.");
	printf("\nAs of now we currently have 7 pokemon in the system with two different moves\nWe ask that two of you do a battle simulation with a pokemon of your choosing");
	printf("\n\nHere are the available pokemon : \n\n");
	printf("\t[1] - Entei\t[4] - Pikachu\t[7] - Stunfisk\n");
	printf("\t[2] - Milotic\t[5] - Groudon\n");
	printf("\t[3] - Torterra\t[6] - Lapras\n\n");	
	
	printf("The Starting turn is decided randomly by the system. Have fun!\n\n");
}

// Gives all the data to the players
void pokemonData(int *p1, int *p2, int *hp1, int *hp2, int *p1m1, int *p1m2, int *p2m1, int *p2m2, char *p1tp1, char *p1tp2, char *p2tp1, char *p2tp2){

// Fire - r | Water - u  | Grass - g | Ground - b | Ice - w | Electric - y | None - n

	switch(*p1){
		case 1: //Entei
				*hp1 = 150;
				*p1m1 = 5;
				*p1m2 = 5;
				*p1tp1 = 'r';
				*p1tp2 = 'n';
				break;
				
		case 2://Milotic
				*hp1 = 200;
				*p1m1 = 7;
				*p1m2 = 7;
				*p1tp1 = 'u';
				*p1tp2 = 'n';
				break;
				
		case 3://Torterra
				*hp1 = 220;
				*p1m1 = 7;
				*p1m2 = 5;
				*p1tp1 = 'g';
				*p1tp2 = 'b';
				break;
			
		case 4://Pikachu
				*hp1 = 120;
				*p1m1 = 10;
				*p1m2 = 7;
				*p1tp1 = 'y';
				*p1tp2 = 'n';
				break;
			
		case 5://Groudon
				*hp1 = 150;
				*p1m1 = 5;
				*p1m2 = 5;
				*p1tp1 = 'g';
				*p1tp2 = 'n';
				break;
			
		case 6://Lapras;
				*hp1 = 190;
				*p1m1 = 7;
				*p1m2 = 7;
				*p1tp1 = 'w';
				*p1tp2 = 'u';
				break;
			
		case 7://Stunfisk
				*hp1 = 130;
				*p1m1 = 10;
				*p1m2 = 5;
				*p1tp1 = 'b';
				*p1tp2 = 'y';
				break;
	}

	switch(*p2){
			case 1: //Entei
				*hp2 = 150;
				*p1m1 = 5;
				*p1m2 = 5;
				*p2tp1 = 'r';
				*p2tp2 = 'n';
				break;
				
		case 2://Milotic
				*hp2 = 200;
				*p2m1 = 7;
				*p2m2 = 7;
				*p2tp1 = 'u';
				*p2tp2 = 'n';
				break;
			
		case 3://Torterra
				*hp2 = 220;
				*p2m1 = 7;
				*p2m2 = 5;
				*p2tp1 = 'g';
				*p2tp2 = 'b';
				break;
			
		case 4://Pikachu
				*hp2 = 120;
				*p2m1 = 10;
				*p2m2 = 7;
				*p2tp1 = 'y';
				*p2tp2 = 'n';
				break;
			
		case 5://Groudon
				*hp2 = 150;
				*p2m1 = 5;
				*p2m2 = 5;
				*p2tp1 = 'g';
				*p2tp2 = 'n';
				break;
			
		case 6://Lapras;
				*hp2 = 190;
				*p2m1 = 7;
				*p2m2 = 7;
				*p2tp1 = 'w';
				*p2tp2 = 'u';
				break;
			
		case 7://Stunfisk
				*hp2 = 130;
				*p2m1 = 10;
				*p2m2 = 5;
				*p2tp1 = 'b';
				*p2tp2 = 'y';
				break;
	}
}

int pokemonList(int select){ //Returns what user inputs for pokemon

	switch(select){
		
		case 1: printf("Entei");				
				return 1;
				
		case 2:printf("Milotic");	
				return 2;
				
		case 3:printf("Torterra");
				return 3;
				
		case 4:printf("Pikachu");
				return 4 ;
				
		case 5:printf("Groudon");
				return 5 ;
				
		case 6:printf("Lapras");
				return 6;
				
		case 7:printf("Stunfisk");
				return 7;
				
		default: 
				printf("an invalid option.\n");
				system("Pause");
				system("CLS");
				return 0;	
	}	
}

void pokemonSelect(int *p1, int *p2){ //Asks for user input on what pokemon

	do{
		startUI();

		printf("Choose a Pokemon Player 1 : ");
		scanf("%d", p1);
		printf("Player 1 has chosen ");
		*p1 = pokemonList(*p1);
		if(*p1 != 0){	
	
			printf("!\n\nChoose a Pokemon Player 2 : ");
			scanf("%d", p2);
			if(*p2 == *p1){
				
				printf("You can't select the same pokemon as Player One\n");
				system("Pause");
				system("CLS");	
				*p2 = 0;
				
			}else{
			
			printf("Player 2 has chosen ");
			*p2 = pokemonList(*p2);
			if(*p2 != 0){
			printf("!\n\n");
			system("Pause");
				}	
			}
		}
		getchar();
	}while(*p1 == 0 || *p2 == 0);
}

int stabCheck(char playerType1, char playerType2, char moveType, float dmg){ //Checks for STAB Damage
	
	if(playerType1 == moveType || playerType2 == moveType){
		
	//	printf("STAB BONUS EFFECT! Bonus 1.5 damage multiplier\n");
		return dmg * 1.5;
		
	}else return dmg;
}

int effectCheck(char moveType, char enemyType1, char enemyType2, float dmg){ //Calculates Multipliers
	
	switch(moveType){
		
		case 'r':
			if(enemyType1 == 'r' || enemyType1 == 'u' || enemyType1 == 'b') dmg = dmg / 2 ;
			else if(enemyType1 == 'g' || enemyType1 == 'w') dmg = dmg * 2;
			else dmg = dmg * 1;
			
			if(enemyType2 == 'r' || enemyType2 == 'u' || enemyType2 == 'b') dmg = dmg / 2 ;
			else if(enemyType2 == 'g' || enemyType2 == 'w') dmg = dmg * 2;
			else dmg = dmg * 1;
			
			break;
			
		case 'u':
			if(enemyType1 == 'u' || enemyType1 == 'g' ) dmg = dmg / 2 ;
			else if(enemyType1 == 'r' || enemyType1 == 'b')  dmg = dmg * 2;
			else  dmg = dmg * 1;
			
			if(enemyType2 == 'u' || enemyType2 == 'g') dmg = dmg / 2 ;
			else if(enemyType2 == 'r' || enemyType2 == 'b')  dmg = dmg * 2;
			else  dmg = dmg * 1;
			
			break;
			
		case 'g':
			if(enemyType1 == 'r' || enemyType1 == 'g')  dmg = dmg / 2;
			else if(enemyType1 == 'u' || enemyType1 == 'b')  dmg = dmg * 2;
			else  dmg = dmg * 0;
			
			if(enemyType2 == 'r' || enemyType2 == 'g')  dmg = dmg /  2;
			else if(enemyType2 == 'u' || enemyType2 == 'b')  dmg = dmg * 2;
			else  dmg = dmg * 0;
			
			break;
			
		case 'y':
			if(enemyType1 == 'g' )  dmg = dmg / 2;
			else if(enemyType1 == 'u')  dmg = dmg * 2;
			else if (enemyType1 == 'b')  dmg = dmg * 0;
			else dmg = dmg * 1;
			
			if(enemyType2 == 'g')  dmg = dmg / 2;
			else if(enemyType2 == 'u')  dmg = dmg * 2;
			else if (enemyType2 == 'b')  dmg = dmg * 0;
			else dmg = dmg * 1;
			
			break;
			
		case 'b':
			if(enemyType1 == 'u' || enemyType1 == 'g' || enemyType1 == 'w') dmg = dmg / 2 ;
			else if(enemyType1 == 'r' || enemyType1 == 'y') dmg = dmg * 2;
			else  dmg = dmg * 1;
			
			if(enemyType2 == 'u' || enemyType2 == 'g' || enemyType2 == 'w')  dmg = dmg / 2;
			else if(enemyType2 == 'r' || enemyType2 == 'y')  dmg = dmg * 2;
			else  dmg = dmg * 1;
			
			break;
			
		case 'w':
			if(enemyType1 == 'r')  dmg = dmg / 2;
			else if(enemyType1 == 'u' || enemyType1 == 'g' || enemyType1 == 'b')  dmg = dmg * 2;
			else dmg = dmg * 1;
			
			if(enemyType2 == 'r')  dmg = dmg / 2;
			else if(enemyType2 == 'u' || enemyType2 == 'g' || enemyType2 == 'b')  dmg = dmg * 2;
			else dmg = dmg * 1;
			
			break;
	}
	return dmg;
}

//Calculates Total Damage
int calculateDmg(int player, char playerType1, char playerType2, int move, char enemyType1, char enemyType2, int charge){

	float dmg;
	char moveType;
	
	switch(player){
		case 1://Entei
			if(move == 1){	// Fire blast | Fire
					dmg = 30;
					moveType = 'r';
				}else{ //Earthquake | Ground
					dmg = 30;
					moveType = 'b';
				}break;
			
		case 2://Milotic
			if(move == 1){	// Scald | Water
					dmg = 20;
					moveType = 'u';
			}else{ 	//Ice Beam | Ice
					dmg = 20;
					moveType = 'w';
			}break;
			
			
		case 3://Torterra
			if(move == 1){// Dig | Ground
					dmg = 20;
					moveType = 'b';
			}else{ //Leaf Storm | Grass
					dmg = 40;
					moveType = 'g';
				}break;
			
		case 4://Pikachu
			if(move == 1){//Thunderbolt | Electric
					dmg = 10;
					moveType = 'y';
			}else {//Dig | Ground
					dmg = 20;
					moveType = 'b';
				}break;
			
		case 5://Groudon
			if(move == 1){//Fissure | Ground
					dmg = 40;
					moveType = 'b';
			}else { //Fire Blast | Fire
					dmg = 30;
					moveType = 'r';
					}break;
			
		case 6://Lapras
			if(move == 1){//Ice Beam | Ice
					dmg = 20;
					moveType = 'w';
				}else{ //Scald | Water
					dmg = 20;
					moveType = 'u';
					}break;
			
		case 7://Stunfisk
			if(move == 1){//Water Gun | Water
					dmg = 10;
					moveType = 'u';
			}else{ // Earthquake  | Ground
					dmg = 30;
					moveType = 'b';
				}break;
			
		}
	

	if(charge == 1) dmg = dmg * 2;
	
	dmg = stabCheck(playerType1, playerType2, moveType, dmg);
	
	return effectCheck(moveType, enemyType1, enemyType2, dmg);
}

void moveList(int pokemon, int pp1, int pp2){//Presents Movelist for Selected Pokemon
	
	switch(pokemon){
		case 1://Entei
			printf("[1]\tFire Blast (30 Bp | %d pp)\n", pp1);
			printf("[2]\tEarthquake (30 Bp | %d pp)\n", pp2);
			break;	
			
		case 2://Milotic
			printf("[1]\tScald (20 Bp | %d pp)\n", pp1);
			printf("[2]\tIce Beam (20 Bp | %d pp)\n", pp2);
			break;
			
		case 3://Torterra
			printf("[1]\tDig (20 Bp | %d pp)\n", pp1);
			printf("[2]\tLeaf Storm (40 Bp | %d pp)\n", pp2);
			break;
			
		case 4://Pikachu
			printf("[1]\tThunderbolt (10 Bp | %d pp)\n", pp1);
			printf("[2]\tDig (20 Bp | %d pp)\n", pp2);
			break;
			
		case 5://Groudon
			printf("[1]\tFissure (40 Bp | %d pp)\n", pp1);
			printf("[2]\tFire Blast (30 Bp | %d pp)\n", pp2);
			break;
			
		case 6://Lapras
			printf("[1]\tIce Beam (20 Bp | %d pp)\n", pp1);
			printf("[2]\tScald (20 Bp | %d pp\n)", pp2);
			break;
			
		case 7://Stunfisk
			printf("[1]\tWater Gun (10 Bp | %d pp)\n", pp1);
			printf("[2]\tEarthquake (30 Bp | %d pp)\n", pp2);
			break;
	}
}

int main(){ //Main
	
	int player1, player2, *p1, *p2, pokemonHP1, pokemonHP2, *hp1, *hp2;
	
	int player1moves1, player1moves2, *p1m1, *p1m2;
	int player2moves1, player2moves2, *p2m1, *p2m2;
	
	int charge1 = 5, charge2 = 5, protect1 = 5, protect2 = 5;
	
	char p1type1, p1type2, *p1tp1, *p1tp2;
	char p2type1, p2type2, *p2tp1, *p2tp2;
	
	int protectState1 = 0, protectState2 = 0, chargeState1 = 0, chargeState2 = 0, protectCheck1 = 0, protectCheck2 = 0;
	
	int turn = 0;
	
	p1 = &player1;
	p2 = &player2;
	
	hp1 = &pokemonHP1;
	hp2 = &pokemonHP2;
	
	p1m1 = &player1moves1;
	p1m2 = &player1moves2;
	p2m1 = &player2moves1;
	p2m2 = &player2moves2;
	
	p1tp1 = &p1type1;
	p1tp2 = &p1type2;
	
	p2tp1 = &p2type1;
	p2tp2 = &p2type2;
		
	srand(time(NULL));
	
	turn = rand() % 2;
	
	pokemonSelect(p1, p2);
	
	pokemonData(p1, p2, hp1, hp2, p1m1, p1m2, p2m1, p2m2, p1tp1, p1tp2, p2tp1, p2tp2);
	
	int option;
	int maxhp1 = *hp1, maxhp2 = *hp2;
	
	while(*hp1 > 0 && *hp2 > 0){//Game Start
		
		printf("\nTurn # %d", turn);
		
		option = 0;
		float damage = 0;
		
		if(turn == 0 && *hp1 > 0){//Player One Turn
			
			while(option == 0){//P1 Loop
				
				printf("= = = = = = = = = = = = = = = = = = = = = =\n\n\t");
				pokemonList(*p1);
				printf("%5d / %d HP\n\t", *hp1, maxhp1);
				pokemonList(*p2);
				printf("%5d / %d HP\n\n", *hp2, maxhp2);
			
				printf("\nIt is Player One's turn!\n");
				pokemonList(*p1);
				printf("'s moves are : \n\n");
				moveList(*p1, *p1m1,*p1m2);
				printf("[3]\tProtect (%d pp)\n", protect1);
				printf("[4]\tCharge UP (%d pp)\nPlayer One, choose your move : ", charge1);
				scanf("%d", &option);
				
				if(option == 1 && *p1m1 <= 0 || option == 2 && *p1m2 <= 0) 
					printf("You do not have enough PP to do this move\n");
					
				else if(option == 1 || option == 2){//P1 move check
					if(protectState2 == 0){
					
						damage = calculateDmg(*p1,*p1tp1,*p1tp2,option,*p2tp1,*p2tp2,chargeState1);
						printf("You dealt %.f damage! \n\n", damage);
						*hp2 -= damage;
					
						if(option == 1) *p1m1 -= 1;
						else *p1m2 -= 1;
					
						protectState1 = 0;
						chargeState1 = 0;
						protectCheck1 = 0;
						
					}else {	
						printf("Your damage was prevented!\n");
						chargeState1 = 0;
						protectState2 = 0;
						protectCheck2 = 1;
					}
				
				}else if(option == 3 && protect1 > 0){
					if (protectState1 == 0 && protectCheck1 == 0){
						protectState1 = 1;
						protectCheck1 = 1;
						protect1 -= 1;
					}else {
					printf("You already used protect last turn\n");
					option = 0;
					}
				
				}else if(option == 4 && charge1 > 0){
					chargeState1 = 1;
					charge1 -= 1;
					protectState1 = 0;
					protectCheck1 = 0;
				}else if(p1m1 == 0 && p1m2 == 0 && protect1 >= 0 && charge1 >= 0){
					printf("Your Pokemon is getting desperate and tackles!\n");
					if(protectState2 != 1){
					*hp1 -= 5;
					*hp2 -= 10;
					}
				 }else {
				getchar();
				printf("Your pokemon does not have that move\n");
				 option = 0;
				}
			}
			turn += 1;//Turn Switch
			
		}else if(turn == 1 && *hp2 > 0){//Player Two Turn
			
			while(option == 0){//P2 Loop
			
				option = 0;
				
				printf("= = = = = = = = = = = = = = = = = = = = = =\n\n\t");
				pokemonList(*p1);
				printf("%5d / %d HP\n\t", *hp1, maxhp1);
				pokemonList(*p2);
				printf("%5d / %d HP\n\n", *hp2, maxhp2);
				
				printf("\nIt is Player Two's turn!\n");
				pokemonList(*p2);
				printf("'s moves are : \n\n");
				moveList(*p2,*p2m1,*p2m2);
				printf("[3]\tProtect (%d pp)\n", protect2);
				printf("[4]\tCharge UP (%d pp)\nPlayer Two, choose your move : ", charge2);
				scanf("%d", &option);
				
				if(option == 1 && p1m1 <= 0 || option == 2 && p1m2 <= 0) 
					printf("You do not have enough PP to do this move\n");
						
				else if(option == 1 || option == 2){//P2 Move Check
					if(protectState1 == 0){
						damage = calculateDmg(*p2,*p2tp1,*p2tp2,option,*p1tp1,*p1tp2,chargeState2);
						printf("You dealt %.f damage! \n\n", damage);
						
						*hp1 -= damage;
						
						if(option == 1) *p2m1 -= 1;
						else *p2m2 -= 1;
						
						protectState2 = 0;
						chargeState2 = 0;
						protectCheck2 = 0;
					}else {
					printf("Your damage was prevented!\n");
					chargeState2 = 0;
					protectState1 = 0;
					protectCheck1 = 1;
					}
					
				}else if(option == 3){
					if (protectState2 == 0 && protectCheck2 == 0){
						protectState2 = 1;
						protect2 -= 1;
						protectCheck2 = 1;
						
					}else {
					printf("You already used protect last turn\n");
					option = 0;
					
					}
				}else if(option == 4){
					chargeState2 = 1;
					charge2 -= 1;
					protectState2 = 0;
					protectCheck2 = 0;
					
				}else if(p2m1 == 0 && p2m2 == 0 && protect2 >= 0 && charge2 >= 0){
					printf("Your Pokemon is getting desperate and tackles!\n");
					if(protectState1 != 1){
					*hp2 -= 5;
					*hp1 -= 10;
					}
				 }else{
				getchar();
				printf("Your pokemon does not have that move\n");
				 option = 0;
				}
			}
			
			turn -= 1;//Turn Switch
		}
	
	}// Combat End
	
	
	// Finish Screen
	if(*hp1 < 0) *hp1 = 0;
	else *hp2 = 0;
	
	printf("= = = = = = = = = = = = = = = = = = = = = =\n\n\t");
	pokemonList(*p1);
	printf("%5d / %d HP\n\t", *hp1, maxhp1);
	pokemonList(*p2);
	printf("%5d / %d HP\n\n", *hp2, maxhp2);
		
	printf("= = = = = = = = = = = = = = = = = = = = = =\n\n\t");
	pokemonList(*p1);
	printf("%5d / %d HP\n\t", *hp1, maxhp1);
	pokemonList(*p2);
	printf("%5d / %d HP\n\n", *hp2, maxhp2);	

	if(*hp2 <= 0) printf("Player Two's pokemon has fainted!\nPlayer One WINS!");
	else printf("Player One's pokemon has fainted!\nPlayer Two WINS!\n");
	
	system("pause");
	return 0;
}
