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
		if ((x - xleft) >= 1 && (x - xleft) <= hitstaken.size()) { //Make sure the point is actually in the dang vector
			return hitstaken.at(x - xleft);
		}
		else return false;
	}
	else { //If the ship is vertical
		if ((ytop - y) >= 1 && (ytop - y) <= hitstaken.size()) {
			return hitstaken.at(ytop - y);
		}
		else return false;
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
		if ((x - xleft) >= 1 && (x - xleft) <= hitstaken.size()) { //Make sure the point is actually in the dang vector
			int hittotake = x - xleft;
			hitstaken[hittotake] = true;
		}
	}
	else { //If the ship is vertical
		if ((ytop - y) >= 1 && (ytop - y) <= hitstaken.size()) {
			int hittotake = ytop - y;
			hitstaken[hittotake] = true;
		}
	}
}
