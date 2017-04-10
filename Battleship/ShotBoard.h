#pragma once


class ShotBoard
{
public:
	ShotBoard();
	~ShotBoard();
	int shotboard[10][10];
	void showshotstaken();
	bool hasshotbeentaken(int x, int y);
};