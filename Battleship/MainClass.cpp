#include <iostream>
#include <ctime>
#include <cstdlib>
#include <tuple>
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
	int x, y, totalturns = 1, poneturns = 1, ptwoturns = 1;
	while (!(A.haslost()) && !(B.haslost())) { //Main gameplay loop
		if (whoseturnisit == true) {
			cout << "Player 1's Turn. This is your " << poneturns;
			switch (poneturns%10) {
			case 1:
				cout << "st ";
				break;
			case 2:
				cout << "nd ";
				break;
			case 3:
				cout << "rd ";
				break;
			default:
				cout << "th ";
				break;
			}
			if (totalturns == 1) {
				cout << "turn.\n";
			}
			else {
				cout << "turn. The game has had " << totalturns << " total turns.\n";
			}
			A.ships.showcontents();
			cout << endl;
			A.shots.showshotstaken();
			tie(x, y) = A.validateshot();
			if (B.ships.battleship.doesshipoccupy(x, y)) { //If the battleship is here
				B.ships.battleship.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (B.ships.aircraftCarrier.doesshipoccupy(x, y)) { //If the aircraft carrier is here
				B.ships.aircraftCarrier.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (B.ships.submarine.doesshipoccupy(x, y)) { //If the submarine is here
				B.ships.submarine.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (B.ships.cruiser.doesshipoccupy(x, y)) { //If the cruiser is here
				B.ships.cruiser.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (B.ships.destroyer.doesshipoccupy(x, y)) { //If the destroyer is here
				B.ships.destroyer.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else {
				A.shots.shotboard[x - 1][y - 1] = 1;
				cout << "Your shot missed...";
			}
			poneturns++;
			totalturns++;
			whoseturnisit = false;
		}
		else {
			cout << "Player 2's Turn. This is your " << ptwoturns;
			switch (ptwoturns % 10) {
			case 1:
				cout << "st ";
				break;
			case 2:
				cout << "nd ";
				break;
			case 3:
				cout << "rd ";
				break;
			default:
				cout << "th ";
				break;
			}
			cout << "turn. The game has had " << totalturns << " total turns.\n";
			B.ships.showcontents();
			cout << endl;
			B.shots.showshotstaken();
			tie(x, y) = B.validateshot();
			if (A.ships.battleship.doesshipoccupy(x, y)) { //If the battleship is here
				A.ships.battleship.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (A.ships.aircraftCarrier.doesshipoccupy(x, y)) { //If the aircraft carrier is here
				A.ships.aircraftCarrier.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (A.ships.submarine.doesshipoccupy(x, y)) { //If the submarine is here
				A.ships.submarine.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (A.ships.cruiser.doesshipoccupy(x, y)) { //If the cruiser is here
				A.ships.cruiser.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else if (A.ships.destroyer.doesshipoccupy(x, y)) { //If the destroyer is here
				A.ships.destroyer.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
			}
			else {
				B.shots.shotboard[x - 1][y - 1] = 1;
				cout << "Your shot missed...";
			}
			ptwoturns++;
			totalturns++;
			whoseturnisit = true;
		}
		cout << endl;
		system("pause");
		system("CLS");
		cout << "Please give the computer to your opponent and look away.\n";
		system("pause");
		system("CLS");
	}
	if (A.haslost() == true) {
		cout << "Player 2 is the winner!\n";
	}
	else {
		cout << "Player 1 is the winner!\n";
	}
	system("pause");
}