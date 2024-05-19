/*
 * OpponentGrid.cpp
 *
 *  Created on: 04-Jan-2024
 *      Author: Priyanka
 */

#include "OpponentGrid.h"


OpponentGrid::OpponentGrid(int rows, int columns):rows(rows),
    columns(columns)
{
	// TODO Auto-generated constructor stub

}


int OpponentGrid::getRows() const
{
	return rows;
}

int OpponentGrid::getColumns() const
{
	return columns;
}


void OpponentGrid::shotResult(const Shot& shot, Shot::Impact impact)
{

	shots[shot.getTargetPosition()] = impact;
}


const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
    return shots;
}

void OpponentGrid::fillsunkenship
(std::map<GridPosition, Shot::Impact>& ShotMap)
{

	std::map<GridPosition,Shot::Impact > newMap;
    for (const auto& pair : ShotMap) {
        if (pair.second != Shot::NONE) {
            newMap.insert(pair);
        }
    }

    GridPosition position("A1");
        for (const auto& pair : newMap) {
                if (pair.second == Shot::SUNKEN) {
                	std::set<GridPosition> sunkenships_x;
                	std::set<GridPosition> sunkenships_y;
                	position = pair.first;
                    for( const auto& pair1 : newMap)
                    {
                    	const GridPosition& position1 = pair1.first;
                    	if(position1.getRow()==position.getRow())
                    	{
                    		int length=0;
                    		length=std::abs(position1.getColumn()
                    				-position.getColumn());
                    		if(length >= 0 && length < 5)
                    		{
                    			sunkenships_x.insert(position1);
                    		}
                    	}

                    	else if(position1.getColumn()==position.getColumn())
                    	{
                    		int length=0;
                    		length=std::abs(position1.getRow()
                    				-position.getRow());
                    		if(length >= 0 && length < 5)
                    		{
                    			sunkenships_y.insert(position1);
                    		}
                    	}
                    	if(position1.getRow()==position.getRow()
                    		&& position1.getColumn()==position.getColumn())
                    	{
                    		  sunkenships_x.insert(position1);

                    		  sunkenships_y.insert(position1);
                    	}

                    }
                    if(sunkenships_x.size()>sunkenships_y.size())
                    {
                    	//to check if the length of the
                    	//ship is in between 3 and 5
                      if(sunkenships_x.size()>2 && sunkenships_x.size()<5)
                      {
    				   auto minElement = std::min_element
    						 (sunkenships_x.begin(), sunkenships_x.end());
    				   auto maxElement = std::max_element
    						 (sunkenships_x.begin(), sunkenships_x.end());
                       GridPosition row_sunken=(*minElement);
                       GridPosition stern_sunken=(*maxElement);
                       Ship sunkenship(row_sunken, stern_sunken);
                       SunkenShip.push_back(sunkenship);
                      }
                    }
                    else
                    {
                    	//to check if the length of the ship is
                    	//between 3 and 5
                    	if(sunkenships_y.size()>2 && sunkenships_y.size()<5)
                    	{
    					auto minElement = std::min_element
    						(sunkenships_y.begin(), sunkenships_y.end());
    					auto maxElement = std::max_element
    						(sunkenships_y.begin(), sunkenships_y.end());
                        GridPosition row_sunken=(*minElement);
                        GridPosition stern_sunken=(*maxElement);
                        Ship sunkenship(row_sunken, stern_sunken);
                        SunkenShip.push_back(sunkenship);
                    	}
                    }

               }

        }
}
std::vector<Ship> OpponentGrid::getSunkenShips() const
{
    return SunkenShip;
}

OpponentGrid::~OpponentGrid()
{
	// TODO Auto-generated destructor stub
}

