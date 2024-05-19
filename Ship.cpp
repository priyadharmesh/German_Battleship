/*
 * Ship.cpp
 *
 *  Created on: 03-Jan-2024
 *      Author: Priyanka
 */

#include "Ship.h"
#include "GridPosition.h"
#include <set>
#include<iostream>
#include<iterator>

Ship::Ship( const GridPosition& bow,  const GridPosition& stern)
: bow(bow), stern(stern)
{
//
}

bool Ship::isValid() const
{
    if(bow.isValid() && stern.isValid())
    {
    	if((bow.getRow() ==  stern.getRow() || bow.getColumn()
    			==  stern.getColumn()))
    	{
    		int Length = findlength();
        	if(2 <= Length && Length <= 5)
        	{
        		return true;
        	}else {
               return false;
            }
    	}else {
           return false;
        }
    }
    else
    {
    	return false;
    }
    return false;
}

int Ship::findlength() const
{
	int length=0;
	if(bow.getRow() ==  stern.getRow() )
	{
		for(int col=bow.getColumn(); col<=stern.getColumn() ; col++)
		{
			length++;
		}
	}
	else
	{
		for(int row=bow.getRow(); row<=stern.getRow() ; row++)
		{
			length++;
		}
	}
	return length;
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern() const
{
    return stern;
}


const std::set<GridPosition> Ship::occupiedArea() const
{
	    std::set<GridPosition> positions;

	    // Determine whether the ship is positioned
	    //horizontally or vertically
	    bool isHorizontal = (bow.getRow() == stern.getRow());

	    // Populate the set with the occupied positions
	    //based on ship length
	    int Length = findlength();
	    for (int pos = 0; pos < Length; ++pos) {

            char currentRow = isHorizontal ?
            		bow.getRow() : (bow.getRow() + pos);
	        int currentColumn = isHorizontal ?
	        		bow.getColumn() + pos : bow.getColumn();
	        positions.emplace(currentRow, currentColumn);
	    }

	return positions;

}

const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> occ_positions;
	std::set<GridPosition> surroundingPositions;
	occ_positions=occupiedArea();
	for (const auto& element : occ_positions) {
		    for (int row = -1; row <= 1; ++row) {
		        for (int col = -1; col <= 1; ++col) {
		            if (!(row == 0 && col == 0)) {

		                surroundingPositions.insert(GridPosition
		                 (element.getRow() + row,
		                		 element.getColumn() + col));
		            }
		        }
		    }
	}
	    return surroundingPositions;

}


Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}
