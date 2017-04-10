#include "ShotBoard.h"
#include <iostream>
using namespace std;

ShotBoard::ShotBoard()
{
}


ShotBoard::~ShotBoard()
{
}

void ShotBoard::recordshot(int x, int y)
{
	//Determine if ship part has been hit
	/*if (who.ships.battleship.doesshipoccupy(x, y)) { //If the battleship is here
		who.ships.battleship.gethit(x, y);
		shotboard[x - 1][y - 1] = 2;
	}
	else if (who.ships.aircraftCarrier.doesshipoccupy(x, y)) { //If the aircraft carrier is here
		who.ships.aircraftCarrier.gethit(x, y);
		shotboard[x - 1][y - 1] = 2;
	}
	else if (who.ships.submarine.doesshipoccupy(x, y)) { //If the submarine is here
		who.ships.submarine.gethit(x, y);
		shotboard[x - 1][y - 1] = 2;
	}
	else if (who.ships.cruiser.doesshipoccupy(x, y)) { //If the cruiser is here
		who.ships.cruiser.gethit(x, y);
		shotboard[x - 1][y - 1] = 2;
	}
	else if (who.ships.destroyer.doesshipoccupy(x, y)) { //If the destroyer is here
		who.ships.destroyer.gethit(x, y);
		shotboard[x - 1][y - 1] = 2;
	}
	else {
		shotboard[x - 1][y - 1] = 1;
	}*/
}

void ShotBoard::showshotstaken()
{
	cout << "Shots you've taken." << endl;
	cout << "  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 1;i <= 10;i++) { //For each row
		cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
		if (i < 10) {
			cout << i << " |  ";
		}
		else {
			cout << i << "|  ";
		}
		for (int j = 1;j <= 10;j++) { //For each column
			if (shotboard[j - 1][i - 1] == 2) { //If you've hit on a shot here
				cout << "H  |  ";
			}
			else if (shotboard[j - 1][i - 1] == 1) { //If you've missed on a shot here
				cout << "M  |  ";
			}
			else {
				cout << "   |  ";
			}
		}
		cout << endl;
		cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}

bool ShotBoard::hasshotbeentaken(int x, int y)
{
	if (shotboard[x - 1][y - 1] > 0) {
		return true;
	}
	else {
		return false;
	}
}
