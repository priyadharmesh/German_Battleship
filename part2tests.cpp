/*
 * part2tests.cpp
 *
 *  Created on: 11-Jan-2024
 *      Author: Priyanka
 */

#include "Test.h"
#include<set>

void part2tests()
{
	Board myBoard(10, 10);
	OwnGrid& myOwnGrid = myBoard.getOwnGrid();

//Blocked area
    assertTrue(myOwnGrid.placeShip(Ship(GridPosition("B2"),
    		GridPosition("B4"))) , "Ship not placed");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
           == set<GridPosition>{GridPosition{"A1"} ,GridPosition{"A2"},
    	          GridPosition{"A3"},GridPosition{"A4"},GridPosition{"B2"},
				    GridPosition{"B3"},GridPosition{"B4"},
                    GridPosition{"A5"},GridPosition{"B5"},GridPosition{"C5"},
					GridPosition{"C4"},GridPosition{"C3"},GridPosition{"C2"},
					GridPosition{"C1"},GridPosition{"B1"}},
					"Blocked area not correct");

   assertTrue(!myOwnGrid.placeShip({Ship{GridPosition{"J1"},
	   GridPosition{"J7"}}}
   ),"Length of the ship is too long");

   assertTrue(!myOwnGrid.placeShip(Ship{GridPosition{"B5"},
	   GridPosition{"E5"}}),
              "ships touch each other");

  	//place ship of length more than given number
   assertTrue(myOwnGrid.placeShip(Ship(GridPosition("C9"),GridPosition("G9")))
    		,"Ship not placed");

	assertTrue(!myOwnGrid.placeShip({Ship{GridPosition{"I5"},
	   GridPosition{"I9"}}}), "ships of that length not available");

	//outside the boundary (more than board size)
	assertTrue(!myOwnGrid.placeShip({Ship{GridPosition{"K5"},
	   GridPosition{"I9"}}}), "Out of range");


}

