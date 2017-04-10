#include <iostream>
#include <ctime>
#include <cstdlib>
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
	bool whoseturnisit = true;
	Player A, B;
	while (!(A.haslost()) && !(B.haslost())) { //Main gameplay loop
		if (whoseturnisit == true) {
			A.ships.showcontents();
			cout << endl;
			A.shots.showshotstaken();
			A.takeshot(whoseturnisit);
			whoseturnisit = false;
		}
		else {
			B.ships.showcontents();
			cout << endl;
			B.shots.showshotstaken();
			B.takeshot(whoseturnisit);
			whoseturnisit = true;
		}
		system("CLS");
		cout << "Please give the computer to your opponent and look away.\n";
		system("pause");
		system("CLS");
	}
	system("pause");
}

/* Prototype board code
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
*/