/*
 * OwnGrid.h
 *
 *  Created on: 04-Jan-2024
 *      Author: Priyanka
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include "Ship.h"
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include<iostream>
#include <map>
#include "Shot.h"

class OwnGrid {
private:
	/** Number of rows in the OwnGrid object **/
    int rows;
    /*number of columns in the OwnGrid object */
    int columns;
    /* Vector of ship object on grid */
    std::vector<Ship> ships;
    /*
     * map table consist of different ship lengths
     * and possible number of each ship
     * that can be placed on the grid
     */
    std::map<int, int> shiptolenMap;
    /* set of GridPosition objects on the grid */
    std::set<GridPosition> shotAt;

    /* A map consist of GridPosition and Ship to be got */
    std::map<GridPosition , Ship> togetshipMap;

public:
    OwnGrid(int rows, int columns);
    int getRows() const;
    int getColumns() const;
    /*
     * Returns a vector containing all the ship
     *  Objects currently on the grid
     */
    const std::vector<Ship>& getShips() const;
    /*
     * tells whether the given ship is placed and
     * stores it in a vector all the ship object passed
     */
    bool placeShip(const Ship& ship);
    /*
     * Receives a shot on OwnGrid
     * @param [in] it takes reference to a shot as a parameter
     * @return A Shot::Impact member indicating the result of shot
     */
	Shot::Impact takeBlow(const Shot& shot);

	/*
	 * Returns list of shots on grid
	 * @return Set of Shot objects
	 */
    const set<GridPosition>& getShotAt() const;
    /*
     * Returns map of sunken ships
     * @return map(GridPosition and ship)
     */
    const std::map<GridPosition, Ship>& getShipsMap() const;
	virtual ~OwnGrid();
};

#endif /* OWNGRID_H_ */
