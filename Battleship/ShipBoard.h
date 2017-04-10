#pragma once
#include "Ship.h"
class ShipBoard
{
public:
	ShipBoard();
	~ShipBoard();
	void showcontents();
	Ship aircraftCarrier, battleship, submarine, cruiser, destroyer;
	bool isshiphere(char ship, int x, int y);
};

