/*
 * ConsoleView.h
 *
 *  Created on: 05-Jan-2024
 *      Author: Priyanka
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Shot.h"
#include "Ship.h"
#include <iostream>
#include <vector>

class ConsoleView {
private:
    Board* board;

public:
    /*
     * Constructor for ConsoleView that takes a pointer to a Board object
     * @param board - Pointer to the Board object to be associated
     *  with this ConsoleView
     */
    ConsoleView(Board* board);
    /*
     * a method to print the initial and modified board
     * position as the game proceeds
     */
    void print();
	virtual ~ConsoleView();

private:
    /*
     * method to fill a char array for the own grid
     */
    void fillOwnGrid(char ownGridDisplay[][10]) const;

    /*
     * Helper method to fill a char array for the opponent grid
     */
    void fillOpponentGrid(char opponentGridDisplay[][10]) const;
};

#endif /* CONSOLEVIEW_H_ */
