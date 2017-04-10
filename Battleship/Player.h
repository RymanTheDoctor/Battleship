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
	pair<int, int> validateshot();
	bool haslost();
	ShipBoard ships;
	ShotBoard shots;
};