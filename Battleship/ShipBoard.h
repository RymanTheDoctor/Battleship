#pragma once
#include "Ship.h"
class ShipBoard
{
public:
	ShipBoard();
	~ShipBoard();
	void showcontents();
	Ship aircraftCarrier, battleship, submarine, cruiser, destroyer;
};

