#include "Calculations.h"

bool Calculations::ResolveMove(Pokemon currPlayer, Pokemon opponent, int move)
{
	switch (move) {
		case 1:
		case 2:
			if (opponent.isProtectedState() == true) cout << "Your damage was prevented!" << endl;
			else opponent.setHP(DMGCalculation(currPlayer, opponent, move - 1));

			currPlayer.setMoveTP(move);
			break;

		case 3:
			if (currPlayer.isProtectedState() == false) {
				currPlayer.setProtectState(true);
				currPlayer.setProtectNum();
			}
			else cout << "You used protect last turn!" << endl;
			break;

		case 4:
			currPlayer.setChargeState(true);
			currPlayer.setChargeNum();
			break;
		default:
			cout << "Invalid move. Try again" << endl << endl;
			return false;
	}
	return true;
}

float Calculations::StabCheck(Pokemon attacker, int moveType)
{
	if (attacker.getType(0) == moveType || attacker.getType(1) == moveType) return 1.5f;
	else return 1.0f;
}

float Calculations::EffectivenessCheck(int moveType, Pokemon defender)
{
	// Fire - r | Water - u  | Grass - g | Ground - b | Ice - w | Electric - y | None - n

	switch (moveType) {
		case fire:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == fire || defender.getType(i) == water || defender.getType(i) == ground) return 0.5;
				else if (defender.getType(i) == grass || defender.getType(i) == ice) return 2;
			}
			break;

		case water:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == water || defender.getType(i) == grass) return 0.5;
				else if (defender.getType(i) == fire || defender.getType(i) == ground) return 2;
			}
			break;

		case grass:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == fire || defender.getType(i) == grass) return 0.5;
				else if (defender.getType(i) == water || defender.getType(i) == ground) return 2;
			}
			break;

		case electric:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == grass) return 0.5;
				else if (defender.getType(i) == water) return 2;
				else if (defender.getType(i) == ground) return 0;
			}
			break;

		case ground:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == water || defender.getType(i) == grass || defender.getType(i) == ice) return 0.5;
				else if (defender.getType(i) == fire || defender.getType(i) == electric) return 2;
			}
			break;

		case ice:
			for (int i = 0; i < 2; i++) {
				if (defender.getType(i) == fire) return 0.5;
				else if (defender.getType(i) == water || defender.getType(i) == grass || defender.getType(i) == ground) return 2;
			}
			break;

		return 1;
	}

}

int Calculations::DMGCalculation(Pokemon attacker, Pokemon defender, int move)
{
	int dmg = attacker.getMoveDMG(move);

	if (attacker.isChargeState() == true) dmg *= 2;

	dmg *= StabCheck(attacker, attacker.getMoveType(move));
	dmg *= EffectivenessCheck(attacker.getMoveType(move), defender);

	cout << "You inflicted " << dmg << " points of damage!" << endl;

	return dmg;
}
