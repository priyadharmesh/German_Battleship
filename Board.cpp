/*
 * Board.cpp
 *
 *  Created on: 05-Jan-2024
 *      Author: Priyanka
 */

#include "Board.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include<iostream>


Board::~Board()
{
	// TODO Auto-generated destructor stub
}

Board::Board(int rows, int columns): ownGrid(rows, columns),
		opponentGrid(rows, columns)
{
}

int Board::getRows() const
{
	return ownGrid.getRows();
}

int Board::getColumns() const
{
	return ownGrid.getColumns();
}

 OwnGrid& Board::getOwnGrid()
{

	return ownGrid;

}

 OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

