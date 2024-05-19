/*
 * OwnGrid.cpp
 *
 *  Created on: 04-Jan-2024
 *      Author: Priyanka
 */

#include "OwnGrid.h"




OwnGrid::OwnGrid(int rows, int columns):rows(rows), columns(columns)
{
 // initialize shiptolenMap

    shiptolenMap[5] = 1;
    shiptolenMap[4] = 2;
    shiptolenMap[3] = 3;
    shiptolenMap[2] = 4;
}

int OwnGrid::getRows() const
{
	return rows;
}

int OwnGrid::getColumns() const
{
	return columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{

    int length=0;
	std::set<GridPosition> blocked_previous ;
	std::set<GridPosition> occupied_current ;
	std::set<GridPosition> intersection;
	if(ships.size()!=0)
	{
		for (const Ship& ship : ships){
			blocked_previous=ship.blockedArea();
		}
	}
	occupied_current=ship.occupiedArea();
	std::set_intersection(blocked_previous.begin(),
      blocked_previous.end(), occupied_current.begin(),
	  occupied_current.end(),
	  std::inserter(intersection, intersection.begin()));
    if (intersection.empty()) {
    	length=ship.findlength();
    	if(shiptolenMap.find(length) != shiptolenMap.end())
    	{

    		 shiptolenMap[length]=shiptolenMap[length]-1;

        }
    	else
        {
           return false;
        }
    	if(shiptolenMap[length]>=0)
    	{
		ships.push_back(ship);
    	}
    	else{
    		return false;
    	}
    }
    else
    {
    	return false;
    }
    return true;
}

const std::vector<Ship>& OwnGrid::getShips() const
{
	return ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot& shot) {
	shotAt.insert(shot.getTargetPosition());
	for (Ship& ship : ships) {
		std::set<GridPosition> occu_positions;
		std::set<GridPosition> intersection;

occu_positions=ship.occupiedArea();
		auto it = occu_positions.find(shot.getTargetPosition());
		if (it != occu_positions.end())
		{

		    std::set_intersection(
		    		occu_positions.begin(), occu_positions.end(),
		        shotAt.begin(), shotAt.end(),
		        std::inserter(intersection, intersection.begin())
				);
		    if(intersection.size() == ship.occupiedArea().size() - 1)
		    {
		    	return Shot::Impact::HIT;
		    }
		    else if(intersection.size() == ship.occupiedArea().size())
		    {
		    	togetshipMap.insert(std::make_pair
		    			(shot.getTargetPosition(), ship));
		    	return Shot::Impact::SUNKEN;

		    }
		    else
		    {
		    	return Shot::Impact::HIT;
		    }

		}
	}

    return Shot::Impact::NONE;

}

const std::set<GridPosition>& OwnGrid::getShotAt() const {
    return shotAt ;
}

const std::map<GridPosition, Ship>& OwnGrid::getShipsMap() const {
    return togetshipMap;
}

OwnGrid::~OwnGrid()
{
	// TODO Auto-generated destructor stub
}
