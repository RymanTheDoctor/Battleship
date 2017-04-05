#pragma once
#include "Ship.h"
class ShipBoard
{
public:
	ShipBoard();
	~ShipBoard();
private:
	Ship aircraftCarrier, battleship, submarine, cruiser, destroyer;
};

