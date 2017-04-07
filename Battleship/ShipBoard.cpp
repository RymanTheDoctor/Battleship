#include "ShipBoard.h"
#include <iostream>

using namespace std;

ShipBoard::ShipBoard()
{
	bool successfullyPlaced, chosenRotation, notPassedTest;
	int chosenSize, chosenX, chosenY;
	for (int i = 1;i <= 5;i++) { //For each ship (there are 5)
		successfullyPlaced = false;
		//Make the right size ship based on what iteration this is
		if (i < 3) {
			chosenSize = i + 1;
		}
		else {
			chosenSize = i;
		}
		while (!successfullyPlaced) { //While the ship has not been placed
			notPassedTest = true;
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
				successfullyPlaced = true;
				break;
			case 2:
				cruiser.setlocation(chosenX, chosenY, 3, chosenRotation);
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 3;j++) {
						if (destroyer.doesshipoccupy(chosenX+j, chosenY)) {
							notPassedTest = false;
						}
						if (notPassedTest) {
							successfullyPlaced = true;
						}
					}
				}
				else { //Vertical
					for (int j = 0;j < 3;j++) {
						if (destroyer.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				break;
			case 3:
				submarine.setlocation(chosenX, chosenY, 3, chosenRotation);
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 3;j++) {
						if (destroyer.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				else { //Vertical
					for (int j = 0;j < 3;j++) {
						if (destroyer.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				break;
			case 4:
				battleship.setlocation(chosenX, chosenY, 4, chosenRotation);
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 4;j++) {
						if (destroyer.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (submarine.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				else { //Vertical
					for (int j = 0;j < 4;j++) {
						if (destroyer.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (submarine.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				break;
			case 5:
				aircraftCarrier.setlocation(chosenX, chosenY, 5, chosenRotation);
				if (chosenRotation) { //Horizontal
					for (int j = 0;j < 5;j++) {
						if (destroyer.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (submarine.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						if (battleship.doesshipoccupy(chosenX + j, chosenY)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
				}
				else { //Vertical
					for (int j = 0;j < 5;j++) {
						if (destroyer.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (cruiser.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (submarine.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						if (battleship.doesshipoccupy(chosenX, chosenY - j)) {
							notPassedTest = false;
						}
						successfullyPlaced = true;
					}
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