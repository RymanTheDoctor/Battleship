#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::takeshot(bool whoseturn)
{
	bool retry = true;
	while (retry) { //Input checking
		int xtoshoot, ytoshoot;
		cout << "Where would you like to shoot? [type x space y]: ";
		cin >> xtoshoot >> ytoshoot;
		if (xtoshoot > 10 || ytoshoot > 10 || xtoshoot < 1 || ytoshoot < 1) {
			cout << "That isn't a position on the board! Please try again.\n";
		}
		else if (shots.hasshotbeentaken(xtoshoot, ytoshoot) > 0) {
			cout << "You've already shot there! Please try again.\n";
		}
		else {
			shots.recordshot(xtoshoot, ytoshoot);
			retry = false;
		}
	}
}

bool Player::haslost()
{
	int totalhitstaken = 0;
	for (int i = 1;i <= 10;i++) { //For each row
		for (int j = 1;j <= 10;j++) { //For each column
			//Determine if ship part has been hit
			if (ships.battleship.doesshipoccupy(j, i)) { //If the battleship is here
				if (ships.battleship.haspartbeenhit(j, i)) { //If the part that is here has been hit
					totalhitstaken++;
				}
			}
			else if (ships.aircraftCarrier.doesshipoccupy(j, i)) { //If the aircraft carrier is here
				if (ships.aircraftCarrier.haspartbeenhit(j, i)) { //If the part that is here has been hit
					totalhitstaken++;
				}
			}
			else if (ships.submarine.doesshipoccupy(j, i)) { //If the submarine is here
				if (ships.submarine.haspartbeenhit(j, i)) { //If the part that is here has been hit
					totalhitstaken++;
				}
			}
			else if (ships.cruiser.doesshipoccupy(j, i)) { //If the cruiser is here
				if (ships.cruiser.haspartbeenhit(j, i)) { //If the part that is here has been hit
					totalhitstaken++;
				}
			}
			else if (ships.destroyer.doesshipoccupy(j, i)) { //If the destroyer is here
				if (ships.destroyer.haspartbeenhit(j, i)) { //If the part that is here has been hit
					totalhitstaken++;
				}
			}
		}
	}
	if (totalhitstaken == 17) {
		return true;
	}
	else {
		return false;
	}
}
