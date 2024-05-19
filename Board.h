/*
 * Board.h
 *
 *  Created on: 05-Jan-2024
 *      Author: Priyanka
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"

class Board {
private:
	/*
	 * Instance of OwnGrid representing the player's own grid
	 */
    OwnGrid ownGrid;
    /*
     * Instance of OpponentGrid representing the opponent's grid
     */
    OpponentGrid opponentGrid;

public:
    /*
     * Constructor to initialize the Board with specified rows and
     * columns for OwnGrid and OpponentGrid
     */
    Board(int rows, int columns);
    /*
     * function to retrieve the number of rows in the player's own grid
     */
    int getRows() const;
    /*
     * function to retrieve the number of columns in the player's own grid
     */
    int getColumns() const;
    /*
     * function to retrieve a reference to the player's own grid
     */
    OwnGrid& getOwnGrid() ;
    /*
     * function to retrieve a reference to the opponent's grid
     */
    OpponentGrid& getOpponentGrid() ;
	virtual ~Board();
};

#endif /* BOARD_H_ */
