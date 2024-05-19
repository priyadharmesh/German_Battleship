/*
 * GridPosition.cpp
 *
 *  Created on: 21-Dec-2023
 *      Author: Priyanka
 */

#include "GridPosition.h"
#include <iostream>
using namespace std;





GridPosition::GridPosition(char row, int column) : row(row), column(column)
{
}

GridPosition::GridPosition(std::string position)
{

	string column1;
	int len;
	std::string complete=position;
	len=complete.size();

	column1 = complete.substr(1, len-1);
	column= stoi(column1);
	row=complete[0];

}

bool GridPosition::isValid() const
{

	if((row >= 'A' && row <= 'Z') && (column > 0 && column<=10)){
	return true;
	}
	else{
		return false;
	}
}

GridPosition::operator std::string() const {
    return std::string(1, row) + std::to_string(column);
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

bool GridPosition::operator ==(const GridPosition &other) const
{
	return (row == other.row) && (column == other.column);
}

bool GridPosition::operator <(const GridPosition &other) const
{
	return (row < other.row) || ((row == other.row) &&
			(column < other.column));
}

GridPosition::~GridPosition()
{
	// TODO Auto-generated destructor stub
}
