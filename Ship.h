/*
 * Ship.h
 *
 *  Created on: 03-Jan-2024
 *      Author: Priyanka
 */

#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include "Shot.h"
#include <set>

class Ship {
private:
	/*
	 * The bow position of the ship
	 */
    GridPosition bow;
    /*
     * The stern position of the ship
     */
    GridPosition stern;
    /*
     * Set of positions where the ship has been hit
     */
    std::set<GridPosition> takenBlows;

public:
    /*
     *  Constructor that initializes a Ship with a
     *  given bow and stern position
     */
    Ship(const GridPosition& bow, const GridPosition& stern);
    /*
     * Checks if the ship is valid
     * (e.g., has a positive length and is aligned
     * horizontally or vertically,
     *  the length of the ship and also ships touch
     *  each other is checked here)
     */
    bool isValid() const;
    /*
     * function to retrieve the bow position of the ship
     */
    GridPosition getBow() const;
    /*
     * function to retrieve the stern position of the ship
     */
    GridPosition getStern() const;
    /*
     * function to retrieve the set of positions occupied by the ship
     * it takes bow and stern and calculate
     *  the in between grid positions
     */
    const std::set<GridPosition> occupiedArea() const;
    /*
     * function to retrieve the set of positions blocked by the ship
     * all the 8 position occupied by the ship
     */
    const std::set<GridPosition> blockedArea() const;
    /*
     * process a shot and return the impact on the ship
     * (e.g., Hit, Miss, Sunken)
     */
    Shot::Impact takeBlow(const Shot& shot);
    /*
     *  function to retrieve the set of positions
     *  where the ship has been hit
     */
    const std::set<GridPosition>& getShotAt() const;
    /*
     * Function to find the length of the ship based on its positions
     */
    int findlength() const;

	virtual ~Ship();
};

#endif /* SHIP_H_ */
