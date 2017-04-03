#include "Ship.h"

Ship::Ship()
{
}


Ship::~Ship()
{
}

bool Ship::doesshipoccupy(int x, int y)
{
	if (rotation) { //If the ship is horizontal
		if (x <= (xleft + size - 1) && x >= (xleft) && y == ytop) { //If it is the left peg of the ship, or right of that, and the right peg of the ship, or left of that
			return true;
		}
		else {
			return false;
		}
	}
	else { //If the ship is vertical
		if (y >= (ytop - size + 1) && y <= (ytop) && x == xleft) { //If it is the top peg of the ship, or below that, and the bottom peg of the ship, or above that
			return true;
		}
		else {
			return false;
		}
	}
}

bool Ship::haspartbeenhit(int x, int y)
{
	if (rotation) { //If the ship is horizontal
		return hitstaken.at(x - xleft);
	}
	else { //If the ship is vertical
		return hitstaken.at(ytop - y);
	}
}

void Ship::setlocation(int setx, int sety, int setsize, bool setrotation)
{
	xleft = setx;
	ytop = sety;
	size = setsize;
	rotation = setrotation;
	for (int i = 1;i <= size;i++) {
		hitstaken.push_back(false);
	}
}

void Ship::gethit(int x, int y)
{
	if (rotation) { //If the ship is horizontal
		int hittotake = x - xleft;
		hitstaken[hittotake] = true;
	}
	else { //If the ship is vertical
		int hittotake = ytop - y;
		hitstaken[hittotake] = true;
	}
}
