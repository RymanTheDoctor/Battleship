#pragma once


class ShotBoard
{
private:
	int shotboard[10][10];
public:
	ShotBoard();
	~ShotBoard();
	void recordshot(int x, int y);
	void showshotstaken();
	bool hasshotbeentaken(int x, int y);
};