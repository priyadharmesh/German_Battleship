/*
 * ConsoleView.cpp
 *
 *  Created on: 05-Jan-2024
 *      Author: Priyanka
 */

#include "ConsoleView.h"

ConsoleView::ConsoleView(Board* board) : board(board) {
}

void ConsoleView::print()  {
    const int rows = board->getRows();
    const int columns = board->getColumns();

    // Create char arrays for own grid and opponent grid
    char ownGridDisplay[10][10];
    char opponentGridDisplay[10][10];



    // Fill char arrays based on own grid and opponent grid
    fillOwnGrid(ownGridDisplay);
    fillOpponentGrid(opponentGridDisplay);

    // Print the own grid
    std::cout << "Own Grid:" << std::endl;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            std::cout << ownGridDisplay[row][col] << ' ';
        }
        std::cout << std::endl;
    }

    // Print a separator between own grid and opponent grid
    std::cout << "---------------------" << std::endl;

    // Print the opponent grid
   std::cout << "Opponent Grid:" << std::endl;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            std::cout << opponentGridDisplay[row][col] << ' ';
        }
        std::cout << std::endl;
    }
}

void ConsoleView::fillOwnGrid(char ownGridDisplay[][10]) const {
	 OwnGrid& ownGrid = board->getOwnGrid();
    // Initialize the display array
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            ownGridDisplay[row][col] = '~';
        }
    }
    // Fill the display array with ship information

        for (const Ship& ship : ownGrid.getShips()) {
            GridPosition bowPosition = ship.getBow();
            GridPosition sternPosition = ship.getStern();
            int arrayIndex;
            int arrayIndex1;

            if ((bowPosition.getRow()) >= 'A' &&
            		(bowPosition.getRow() <= 'J'))
                {
                    arrayIndex = bowPosition.getRow() - 'A';
                    arrayIndex1 = sternPosition.getRow() - 'A';
                }
            // Check if the ship is horizontal or vertical
            if (bowPosition.getRow() == sternPosition.getRow()) {
                // Ship is horizontal
                for (int col = bowPosition.getColumn()-1; col <=
                sternPosition.getColumn()-1; ++col) {
                	ownGridDisplay[arrayIndex][static_cast<int>(col)] = '#';
                }
            } else if (bowPosition.getColumn() == sternPosition.getColumn())
            {
                // Ship is vertical
                for (int row =arrayIndex; row <= arrayIndex1; ++row) {
                    ownGridDisplay[static_cast<int>(row)]
		            [static_cast<int>(bowPosition.getColumn()-1)] = '#';

                }
            }
        }
        // Fill the display array with misses and hits
        const std::set<GridPosition>& shotAt = ownGrid.getShotAt();
        for (const GridPosition& position : shotAt) {
            int arrayIndex = position.getRow() - 'A';
            int columnIndex = position.getColumn() - 1;

            if (ownGridDisplay[arrayIndex][columnIndex] == '#') {
                // Hit
                ownGridDisplay[arrayIndex][columnIndex] = 'O';
            } else {
                // Miss
                ownGridDisplay[arrayIndex][columnIndex] = '^';
            }
        }
}

void ConsoleView::fillOpponentGrid(char opponentGridDisplay[][10]) const
{
	OpponentGrid& opponentGrid = board->getOpponentGrid();

    // Initialize the display array
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
        	opponentGridDisplay[row][col] = '~';
        }
    }
//modification

    std::map<GridPosition, Shot::Impact> shots;
    shots=opponentGrid.getShotsAt();

    for (const auto& pair  : shots)
    {
    	const GridPosition& position = pair.first;
    	int arrayIndex = position.getRow() - 'A';
    	int columnIndex = position.getColumn() - 1;
    	if (pair.second == Shot::NONE)
    	{
          if( opponentGridDisplay[arrayIndex][columnIndex] == '~')
          {
            // Miss
        	  opponentGridDisplay[arrayIndex][columnIndex] = '^';
          }
        }
    	else if (pair.second == Shot::HIT)
    	{
    		if( opponentGridDisplay[arrayIndex][columnIndex] == '~')
    		{          // HIT
    		  opponentGridDisplay[arrayIndex][columnIndex] = '0';
    		}
    	}
    	else
    	{
    		if( opponentGridDisplay[arrayIndex][columnIndex] == '~')
    		{          // HIT
    		  opponentGridDisplay[arrayIndex][columnIndex] = '0';
    	    }
        }
    }
    //level 2 modification
    std::vector<Ship> SunkenShip;
    SunkenShip=opponentGrid.getSunkenShips();
    for (const Ship& ship : SunkenShip){
        GridPosition bowPosition = ship.getBow();
        GridPosition sternPosition = ship.getStern();
        int arrayIndex;
        int columnIndex;
        if ((bowPosition.getRow()) >= 'A' && (bowPosition.getRow() <= 'J'))
            {
                arrayIndex = bowPosition.getRow() - 'A';
                columnIndex = sternPosition.getRow() - 'A';
            }

        // Check if the ship is horizontal or vertical
        if (bowPosition.getRow() == sternPosition.getRow()) {
            // Ship is horizontal
            for (int col = bowPosition.getColumn()-1;
            		col <= sternPosition.getColumn()-1; ++col) {
            	opponentGridDisplay[arrayIndex][static_cast<int>(col)] = '#';
            }
        } else if (bowPosition.getColumn() == sternPosition.getColumn()) {
            // Ship is vertical
            for (int row =arrayIndex; row <= columnIndex; ++row) {
            	opponentGridDisplay[static_cast<int>(row)]
		         [static_cast<int>(bowPosition.getColumn()-1)] = '#';

            }
        }
    }
}


ConsoleView::~ConsoleView() {
    // Implementation of the destructor, if needed
}
