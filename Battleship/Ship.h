#pragma once
#include <vector>
class Ship
{
public:
	Ship();
	~Ship();
	bool doesshipoccupy(int x, int y);
	bool haspartbeenhit(int x, int y);
	bool issunken();
	void setlocation(int setx, int sety, int size, bool setrotation);
	void gethit(int x, int y);
private:
	int xleft, ytop, size;
	bool rotation; //True means horizontal, false means vertical
	std::vector<bool> hitstaken; //This vector stores whether each part of the ship has been hit, true is hit, false is not hit
};

