#include <iostream>
#include <ctime>
#include "MainClass.h"
#include "Ship.h"
#include "ShipBoard.h"
#include "ShotBoard.h"
#include "Player.h"

using namespace std;

MainClass::MainClass()
{
}


MainClass::~MainClass()
{
}

int main() {
	srand(time(NULL));
	//Not supposed to be here, just testing out how to draw the board
	cout << "  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 1;i <= 10;i++) {
		cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
		if (i < 10) {
			cout << i << " |     |     |     |     |     |     |     |     |     |     |" << endl;
		}
		else {
			cout << i << "|     |     |     |     |     |     |     |     |     |     |" << endl;
		}
		cout << "  |     |     |     |     |     |     |     |     |     |     |" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	system("pause");
}