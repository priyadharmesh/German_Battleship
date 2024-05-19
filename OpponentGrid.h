/*
 * OpponentGrid.h
 *
 *  Created on: 04-Jan-2024
 *      Author: Priyanka
 */

#include "Ship.h"
#include "Shot.h"
#include "OwnGrid.h"
#include <iostream>
#include <set>
#include <vector>
#include <map>
#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

class OpponentGrid {
private:
    int rows;
    int columns;
    /*
     * Vector to store information about sunken ships on opponent Grid
     */
    std::vector<Ship> SunkenShip;
    /*
     * Map to store shots and their impacts on the opponent's grid
     */
    std::map<GridPosition, Shot::Impact> shots;


public:
    OpponentGrid(int rows, int columns);

    int getRows() const;
    int getColumns() const;
    /*
     * it record the result of a shot on the opponent's grid
     * @return the GridPosition shot and its Impact
     */
    void shotResult(const Shot& shot, Shot::Impact impact);
    /*
     * it returns the map of shots taken on opponent grid and its Impact
     */
    const std::map<GridPosition, Shot::Impact>& getShotsAt() const;
    /*
     * to fill information about sunken ships based on shot impacts
     * @param it takes shot maps as a parameter
     * and fills the sunkenship vector
     */
    void fillsunkenship(std::map<GridPosition, Shot::Impact>& ShotMap);
    /*
     * It retrieves the information about sunken ship
     * @returns the vector filled by fillsunkenship()
     */
    std::vector<Ship> getSunkenShips() const;
	virtual ~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
