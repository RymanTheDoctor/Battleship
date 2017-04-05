#include "ShipBoard.h"

using namespace std;

ShipBoard::ShipBoard()
{
	bool successfullyPlaced, chosenRotation, passedTest;
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
			passedTest = false;
			//Choose a rotation and position for the ship
			if (rand() % 2) {
				chosenRotation = true;
				chosenX = ((rand() % (10 - chosenSize)) + 1);
				chosenY = (rand() % (10) + 1);
			}
			else {
				chosenRotation = false;
				chosenX = (rand() % (10) + 1);
				chosenY = (rand() % (10 - chosenSize) + 1);
			}
			//Check that the ship's position is valid
			for (int j = 0;j < chosenSize;j++) { //For each x or y slot depending on rotation
				if (chosenRotation) { //Horizontal
					//Make sure there isn't already a ship there!
					if (aircraftCarrier.doesshipoccupy(chosenX+j, chosenY) == true || battleship.doesshipoccupy(chosenX + j, chosenY) == true || submarine.doesshipoccupy(chosenX + j, chosenY) == true || battleship.doesshipoccupy(chosenX + j, chosenY) == true || cruiser.doesshipoccupy(chosenX + j, chosenY) == true || destroyer.doesshipoccupy(chosenX + j, chosenY) == true) {
						//If a ship occupies this position, then...
						break;
					}
					else if (j = chosenSize-1) { //If we passed the no ship there test
						passedTest = true;
					}
				}
				else { //Vertical
					//Make sure there isn't already a ship there!
					if (aircraftCarrier.doesshipoccupy(chosenX, chosenY - j) == true || battleship.doesshipoccupy(chosenX, chosenY - j) == true || submarine.doesshipoccupy(chosenX, chosenY - j) == true || battleship.doesshipoccupy(chosenX, chosenY - j) == true || cruiser.doesshipoccupy(chosenX, chosenY - j) == true || destroyer.doesshipoccupy(chosenX, chosenY - j) == true) {
						//If a ship occupies this position, then...
						break;
					}
					else if (j = chosenSize - 1) { //If we passed the no ship there test
						passedTest = true;
					}
				}
			}
			if (passedTest) {
				switch (i) //Depending on which ship this is, place it, finally
				{
				case 1:
					destroyer.setlocation(chosenX, chosenY, 2, chosenRotation);
					break;
				case 2:
					cruiser.setlocation(chosenX, chosenY, 3, chosenRotation);
					break;
				case 3:
					submarine.setlocation(chosenX, chosenY, 3, chosenRotation);
					break;
				case 4:
					battleship.setlocation(chosenX, chosenY, 4, chosenRotation);
					break;
				case 5:
					aircraftCarrier.setlocation(chosenX, chosenY, 5, chosenRotation);
					break;
				}
				successfullyPlaced = true;
			}
		}
	}
}


ShipBoard::~ShipBoard()
{
}
