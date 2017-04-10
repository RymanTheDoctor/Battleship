#pragma once
#include "ShotBoard.h"
#include "ShipBoard.h"
#include <iostream>

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void takeshot(bool whoseturn);
	bool haslost();
	ShipBoard ships;
	ShotBoard shots;
};