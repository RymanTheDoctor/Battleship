#include "ShipBoard.h"
#include <iostream>

using namespace std;

ShipBoard::ShipBoard()
{
	bool retry, chosenRotation;
	int chosenSize, chosenX, chosenY, spotcheck;
	for (int i = 1;i <= 5;i++) { //For each ship (there are 5)
		retry = true;
		//Make the right size ship based on what iteration this is
		if (i < 3) {
			chosenSize = i + 1;
		}
		else {
			chosenSize = i;
		}
		while (retry) { //While the ship has not been placed
			//Choose a rotation and position for the ship
			if (rand() % 2) {
				chosenRotation = true;
				chosenX = ((rand() % (10 - chosenSize)) + 1);
				chosenY = (rand() % (10) + 1);
			}
			else {
				chosenRotation = false;
				chosenX = (rand() % (10) + 1);
				chosenY = (rand() % (10 - chosenSize) + chosenSize + 1);
			}
			switch (i) //Depending on which ship this is, place it
			{
			case 1:
				destroyer.setlocation(chosenX, chosenY, 2, chosenRotation);
				retry = false;
				break;
			case 2:
				cruiser.setlocation(chosenX, chosenY, 3, chosenRotation);
				spotcheck = 0;
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 3;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX + j, chosenY)) {
							//cout << "Destroyer occupies " << chosenX + j << ", " << chosenY << " so cruiser cannot.\n";
						}
						else {
							//cout << "Destroyer does not occupy " << chosenX + j << ", " << chosenY << " so cruiser can.\n";
							spotcheck++;
						}
					}
				}
				else { //Vertical
					for (int j = 0;j < 3;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX, chosenY - j)) {
							//cout << "Destroyer occupies " << chosenX << ", " << chosenY - j << " so cruiser cannot.\n";
						}
						else {
							//cout << "Destroyer does not occupy " << chosenX << ", " << chosenY - j << " so cruiser can.\n";
							spotcheck++;
						}
					}
				}
				if (spotcheck == 3) {
					retry = false;
				}
				break;
			case 3:
				submarine.setlocation(chosenX, chosenY, 3, chosenRotation);
				spotcheck = 0;
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 3;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX + j, chosenY) || cruiser.doesshipoccupy(chosenX + j, chosenY)) {
							//cout << "Destroyer or Cruiser occupies " << chosenX + j << ", " << chosenY << " so submarine cannot.\n";
						}
						else {
							//cout << "Destroyer and Cruiser do not occupy " << chosenX + j << ", " << chosenY << " so submarine can.\n";
							spotcheck++;
						}
					}
				}
				else { //Vertical
					for (int j = 0;j < 3;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX, chosenY - j) || cruiser.doesshipoccupy(chosenX, chosenY - j)) {
							//cout << "Destroyer or Cruiser occupies " << chosenX << ", " << chosenY - j << " so submarine cannot.\n";
						}
						else {
							//cout << "Destroyer and Cruiser do not occupy " << chosenX << ", " << chosenY - j << " so submarine can.\n";
							spotcheck++;
						}
					}
				}
				if (spotcheck == 3) {
					retry = false;
				}
				break;
			case 4:
				battleship.setlocation(chosenX, chosenY, 4, chosenRotation);
				spotcheck = 0;
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 4;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX + j, chosenY) || cruiser.doesshipoccupy(chosenX + j, chosenY) || submarine.doesshipoccupy(chosenX + j, chosenY)) {
							//cout << "Destroyer, Cruiser, or Submarine occupies " << chosenX + j << ", " << chosenY << " so battlehsip cannot.\n";
						}
						else {
							//cout << "Destroyer, Cruiser, and Submarine do not occupy " << chosenX + j << ", " << chosenY << " so battlehsip can.\n";
							spotcheck++;
						}
					}
				}
				else { //Vertical
					for (int j = 0;j < 4;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX, chosenY - j) || cruiser.doesshipoccupy(chosenX, chosenY - j) || submarine.doesshipoccupy(chosenX, chosenY - j)) {
							//cout << "Destroyer, Cruiser, or Submarine occupies " << chosenX << ", " << chosenY - j << " so battlehsip cannot.\n";
						}
						else {
							//cout << "Destroyer, Cruiser, and Submarine do not occupy " << chosenX << ", " << chosenY - j << " so battlehsip can.\n";
							spotcheck++;
						}
					}
				}
				if (spotcheck == 4) {
					retry = false;
				}
				break;
			case 5:
				aircraftCarrier.setlocation(chosenX, chosenY, 5, chosenRotation);
				spotcheck = 0;
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 5;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX + j, chosenY) || cruiser.doesshipoccupy(chosenX + j, chosenY) || submarine.doesshipoccupy(chosenX + j, chosenY) || battleship.doesshipoccupy(chosenX + j, chosenY)) {
							//cout << "Destroyer, Cruiser, Submarine, or Battleship occupies " << chosenX + j << ", " << chosenY << " so Aircraft Carrier cannot.\n";
						}
						else {
							//cout << "Destroyer, Cruiser, Submarine, and Battleship do not occupy " << chosenX + j << ", " << chosenY << " so Aircraft Carrier can.\n";
							spotcheck++;
						}
					}
				}
				else { //Vertical
					for (int j = 0;j < 5;j++) { //For each peg of the ship
						if (destroyer.doesshipoccupy(chosenX, chosenY - j) || cruiser.doesshipoccupy(chosenX, chosenY - j) || submarine.doesshipoccupy(chosenX, chosenY - j) || battleship.doesshipoccupy(chosenX, chosenY - j)) {
							//cout << "Destroyer, Cruiser, Submarine, or Battleship occupies " << chosenX << ", " << chosenY - j << " so Aircraft Carrier cannot.\n";
						}
						else {
							//cout << "Destroyer, Cruiser, Submarine, and Battleship do not occupy " << chosenX << ", " << chosenY - j << " so Aircraft Carrier can.\n";
							spotcheck++;
						}
					}
				}
				if (spotcheck == 5) {
					retry = false;
				}
				break;
			}
		}
	}
}


ShipBoard::~ShipBoard()
{
}

void ShipBoard::showcontents()
{
	cout << "Your ships' locations:" << endl;
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
			//Output nothing if there is no ship there, a letter if there is, or x if there is and it has been hit
			if (battleship.doesshipoccupy(j, i)) { //If the battleship is here
				if (battleship.haspartbeenhit(j, i)) { //If the part that is here has been hit
					cout << "X  |  ";
				}
				else { //If the ship is here but has not been hit
					cout << "B  |  ";
				}
			}
			else if (aircraftCarrier.doesshipoccupy(j, i)) { //If the aircraft carrier is here
				if (aircraftCarrier.haspartbeenhit(j, i)) { //If the part that is here has been hit
					cout << "X  |  ";
				}
				else { //If the ship is here but has not been hit
					cout << "A  |  ";
				}
			}
			else if (submarine.doesshipoccupy(j, i)) { //If the submarine is here
				if (submarine.haspartbeenhit(j, i)) { //If the part that is here has been hit
					cout << "X  |  ";
				}
				else { //If the ship is here but has not been hit
					cout << "S  |  ";
				}
			}
			else if (cruiser.doesshipoccupy(j, i)) { //If the cruiser is here
				if (cruiser.haspartbeenhit(j, i)) { //If the part that is here has been hit
					cout << "X  |  ";
				}
				else { //If the ship is here but has not been hit
					cout << "C  |  ";
				}
			}
			else if (destroyer.doesshipoccupy(j, i)) { //If the destroyer is here
				if (destroyer.haspartbeenhit(j, i)) { //If the part that is here has been hit
					cout << "X  |  ";
				}
				else { //If the ship is here but has not been hit
					cout << "D  |  ";
				}
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