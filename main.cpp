// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include<string>
#include<set>
#include<vector>
#include "Board.h"
#include "ConsoleView.h"
#include "GridPosition.h"
#include "OwnGrid.h"
#include "Ship.h"
#include "OpponentGrid.h"
#include "Shot.h"
#include "Test.h"


using namespace std;

int main ()
{
cout << "BattleShip started." << endl << endl;

    //Ship

    GridPosition Grid('B',2);
    GridPosition Grid1("B4");
    GridPosition Grid2('D',4);
    GridPosition Grid3("G4");
    GridPosition Grid4("F6");
    GridPosition Grid5("F9");

    GridPosition Grid6("F7");
    GridPosition Grid7("F8");
    Ship ship1(Grid,Grid1);
    Ship ship2(Grid2,Grid3);
    Ship ship3(Grid4,Grid5);
    //Ship ship4(Grid6,Grid7);

// Create Board and OwnGrid
Board myBoard(10, 10);
OwnGrid& myOwnGrid = myBoard.getOwnGrid();
OpponentGrid& opponentGrid = myBoard.getOpponentGrid();

// Place the three ships on OwnGrid
if(myOwnGrid.placeShip(ship1))
	{
//
	}
else
{
	cout<<"not done"<<endl;
}
myOwnGrid.placeShip(ship2);
myOwnGrid.placeShip(ship3);
//myOwnGrid.placeShip(ship4);
std::set<GridPosition> shotAt;
GridPosition Grid10("B3");
GridPosition Grid11("E4");
GridPosition Grid12("F4");
GridPosition Grid13("G5");
Shot shot1(Grid);
Shot shot2(Grid1);
Shot shot3(Grid10);
Shot shot4(Grid4);
Shot shot5(Grid5);
Shot shot6(Grid6);
Shot shot7(Grid7);
Shot shot8(Grid2);
Shot shot9(Grid11);
Shot shot10(Grid12);
Shot shot11(Grid13);

//OwnGrid taken blows
myOwnGrid.takeBlow(shot1);
myOwnGrid.takeBlow(shot2);
myOwnGrid.takeBlow(shot3);
myOwnGrid.takeBlow(shot4);
myOwnGrid.takeBlow(shot5);
myOwnGrid.takeBlow(shot6);
myOwnGrid.takeBlow(shot7);
myOwnGrid.takeBlow(shot8);
myOwnGrid.takeBlow(shot9);
myOwnGrid.takeBlow(shot10);
myOwnGrid.takeBlow(shot11);

// Opponent Grid shots
std::map<GridPosition, Shot::Impact> shots;

opponentGrid.shotResult(Shot{{"C2"}}, Shot::NONE);
opponentGrid.shotResult(Shot{{"F5"}}, Shot::NONE);
opponentGrid.shotResult(Shot{{"G4"}}, Shot::NONE);
opponentGrid.shotResult(Shot{{"I5"}}, Shot::NONE);
opponentGrid.shotResult(Shot{{"G5"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"G6"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"C5"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"C3"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"C4"}}, Shot::SUNKEN);
opponentGrid.shotResult(Shot{{"G1"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"H1"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"I1"}}, Shot::SUNKEN);



/*
opponentGrid.shotResult(Shot{{"C2"}}, Shot::NONE);
opponentGrid.shotResult(Shot{{"G8"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"G5"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"G6"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"G7"}}, Shot::SUNKEN);
opponentGrid.shotResult(Shot{{"E2"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"F2"}}, Shot::HIT);
opponentGrid.shotResult(Shot{{"G2"}}, Shot::SUNKEN);
*/

// returns map of the shots taken and its impact on opponentGrid
shots=opponentGrid.getShotsAt();


// returns vector of blown shots on ownGrid
shotAt= myOwnGrid.getShotAt();
std::vector<Ship> SunkenShip;
std::set<GridPosition> positions;
opponentGrid.fillsunkenship(shots);
SunkenShip=opponentGrid.getSunkenShips();


// Print ship details using ConsoleView

ConsoleView myConsoleView(&myBoard);
myConsoleView.print();

//
cout<< "Test Cases is Starting"<<endl;

part1tests();
part2tests();
part3tests();


	return 0;
}
