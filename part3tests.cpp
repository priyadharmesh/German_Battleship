/*
 * part3tests.cpp
 *
 *  Created on: 11-Jan-2024
 *      Author: Priyanka
 */

#include "Test.h"
#include<set>

void part3tests()
{

	Board myBoard(10, 10);
	OwnGrid& myOwnGrid = myBoard.getOwnGrid();
	OpponentGrid& opponentGrid = myBoard.getOpponentGrid();

	// PlaceShip

	assertTrue(myOwnGrid.placeShip(Ship(GridPosition("B2"),
			GridPosition("B4"))) , "Ship not placed");


	// owngrid takeblow check

	assertTrue(myOwnGrid.takeBlow(Shot({"B2"})) == Shot::HIT ,
			"Impact is not a hit for B2");
	assertTrue(myOwnGrid.takeBlow(Shot({"B5"})) == Shot::NONE ,
			"Impact is not a miss for B5");

	// sunken

	// Test Opponent Grid Shot at

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

	std::map<GridPosition, Shot::Impact> shots;
	std::vector<Ship> SunkenShip;
	shots=opponentGrid.getShotsAt();
	opponentGrid.fillsunkenship(shots);
	SunkenShip=opponentGrid.getSunkenShips();
	assertTrue(SunkenShip.size()==2," first sunken ship is not added");
	assertTrue(opponentGrid.getSunkenShips()[0].occupiedArea() ==
			set<GridPosition> {{"C3"},{"C4"},{"C5"}}, "Sunken ship 1 is "
					"incorrect");


	//sunkenships

	ConsoleView myConsoleView(&myBoard);
	myConsoleView.print();


}


