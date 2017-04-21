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

void ordinal(int num) {
	switch (num % 10) {
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
}

void whogoesfirst() {
	char docointoss;
	cout << "Would you like to do a coin toss to decide who goes first? [y/n] ";
	cin >> docointoss;
	if (docointoss != 'n') {
		cout << "Someone please call it, and continue when ready.\n";
		system("pause");
		if (rand() % 2) {
			cout << "        _.-'~~`~~'-._" << endl;
			cout << "     .'`  B   E   R  `'." << endl;
			cout << "    / I               T \\" << endl;
			cout << "  /`       .-'~\" - .     `\\" << endl;
			cout << " ; L      / `-    \      Y  ;" << endl;
			cout << ";        />  `.  -.|       ;" << endl;
			cout << "|       /_     '-.__)      |" << endl;
			cout << "|        |-  _.' \ |        |" << endl;
			cout << ";        `~~;     \\        ;" << endl;
			cout << " ;  INGODWE /      \\)      ;" << endl;
			cout << "  \\  TRUST '.___.-'`\"     / " << endl;
			cout << "   `\\                   /`" << endl;
			cout << "     '._   1 9 9 7   _.'" << endl;
			cout << "        `'-..,,,..-'`" << endl;
			cout << "Heads will go first.\n";
		}
		else {
			cout << "        _.-'~~`~~'-._" << endl;
			cout << "     .'`     _**_    `'." << endl;
			cout << "    /       |    |      \\" << endl;
			cout << "  /`   _____|    |_____  `\\" << endl;
			cout << " ;    /________________\\   ;" << endl;
			cout << ";    |__________________|  ;" << endl;
			cout << "|     \\ /\\ /\\ /\\ /\\ /\\ /   |" << endl;
			cout << "|      I  I  I  I  I  I    |" << endl;
			cout << ";      I  I  I  I  I  I    ;" << endl;
			cout << " ;     I  I  I  I  I  I    ;" << endl;
			cout << "  \\    I  I  I  I  I  I   / " << endl;
			cout << "   `\\                   /`" << endl;
			cout << "     '._   1 9 9 7   _.'" << endl;
			cout << "        `'-..,,,..-'`" << endl;
			cout << "Tails will go first.\n";
		}
		system("pause");
	}
	system("CLS");
}

void titlescreen() {
	cout << endl;
	cout << "                            B A T T L E S H I P" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "*                             __    __    __                                  *" << endl;
	cout << "*                            |==|  |==|  |==|                                 *" << endl;
	cout << "*                          __|__|__|__|__|__|_                                *" << endl;
	cout << "*                       __|___________________|___                            *" << endl;
	cout << "*                    __|__[]__[]__[]__[]__[]__[]__|___                        *" << endl;
	cout << "*                   |............................o.../                        *" << endl;
	cout << "*                   \\.............................../                         *" << endl;
	cout << "*            _,~')_,~')_,~')_,~')_,~')_,~')_,~')_,~')/,~')_                   *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "                 Dylan Brown     Alyssa Cote     Ryan Turner" << endl;;
	cout << endl;
	cout << "Try to sink all of the other player's ships before they sink all of your ships. ";
	cout << "All of the other player's ships are somewhere on his/her board. ";
	cout << "You try to hit  them by calling out the coordinates of one of the squares on the board. ";
	cout << "Neither you nor the other player can see the other's board so you must make guesses.    ";
	cout << "Each player has two grids: the upper for where your ships are, and the lower forrecording previous guesses. ";
	cout << "Players take turns guessing coordinates, and are    informed of whether their shot hit or missed, and if it sunk a ship. ";
	cout << endl << endl;
	system("pause");
	system("CLS");
}

int main() {
	srand(time(NULL));
	bool whoseturnisit = true;
	Player A, B;
	int x, y, totalturns = 1, poneturns = 1, ptwoturns = 1;
	titlescreen();
	whogoesfirst();
	while (!(A.haslost()) && !(B.haslost())) { //Main gameplay loop
		if (whoseturnisit == true) {
			cout << "Player 1's Turn. This is your " << poneturns;
			ordinal(poneturns);
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
				if (B.ships.battleship.issunken()) {
					cout << " You sunk their Battleship!";
				}
			}
			else if (B.ships.aircraftCarrier.doesshipoccupy(x, y)) { //If the aircraft carrier is here
				B.ships.aircraftCarrier.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (B.ships.aircraftCarrier.issunken()) {
					cout << " You sunk their Aircraft Carrier!";
				}
			}
			else if (B.ships.submarine.doesshipoccupy(x, y)) { //If the submarine is here
				B.ships.submarine.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (B.ships.submarine.issunken()) {
					cout << " You sunk their Submarine!";
				}
			}
			else if (B.ships.cruiser.doesshipoccupy(x, y)) { //If the cruiser is here
				B.ships.cruiser.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (B.ships.cruiser.issunken()) {
					cout << " You sunk their Cruiser!";
				}
			}
			else if (B.ships.destroyer.doesshipoccupy(x, y)) { //If the destroyer is here
				B.ships.destroyer.gethit(x, y);
				A.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (B.ships.destroyer.issunken()) {
					cout << " You sunk their Destroyer!";
				}
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
			ordinal(ptwoturns);
			cout << "turn. The game has had " << totalturns << " total turns.\n";
			B.ships.showcontents();
			cout << endl;
			B.shots.showshotstaken();
			tie(x, y) = B.validateshot();
			if (A.ships.battleship.doesshipoccupy(x, y)) { //If the battleship is here
				A.ships.battleship.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (A.ships.battleship.issunken()) {
					cout << " You sunk their Battleship!";
				}
			}
			else if (A.ships.aircraftCarrier.doesshipoccupy(x, y)) { //If the aircraft carrier is here
				A.ships.aircraftCarrier.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (A.ships.aircraftCarrier.issunken()) {
					cout << " You sunk their Aircraft Carrier!";
				}
			}
			else if (A.ships.submarine.doesshipoccupy(x, y)) { //If the submarine is here
				A.ships.submarine.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (A.ships.submarine.issunken()) {
					cout << " You sunk their Submarine!";
				}
			}
			else if (A.ships.cruiser.doesshipoccupy(x, y)) { //If the cruiser is here
				A.ships.cruiser.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (A.ships.cruiser.issunken()) {
					cout << " You sunk their Cruiser!";
				}
			}
			else if (A.ships.destroyer.doesshipoccupy(x, y)) { //If the destroyer is here
				A.ships.destroyer.gethit(x, y);
				B.shots.shotboard[x - 1][y - 1] = 2;
				cout << "Your shot hit!";
				if (A.ships.destroyer.issunken()) {
					cout << " You sunk their Destroyer!";
				}
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