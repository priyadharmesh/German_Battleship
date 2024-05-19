/*
 * Shot.h
 *
 *  Created on: 07-Jan-2024
 *      Author: Priyanka
 */

#ifndef SHOT_H
#define SHOT_H

#include "GridPosition.h" // Include the GridPosition header


class Shot {
public:
	/*
	 * Enumeration representing the impact of a shot
	 */
	enum Impact {
	        NONE,          // No impact
	        HIT,           // Hit the target
	        SUNKEN         // Target ship has been sunken
	    };
private:
	/*
	 * The target position of the shot
	 */
    GridPosition targetPosition;
    /*
     * The impact of the shot (NONE, HIT, SUNKEN)
     */
    Impact impact;

public:
    /*
     * Constructor that initializes a Shot with a given target position
     */
    Shot(GridPosition targetPos);
    /*
     * Getter function to retrieve the target position of the shot
     */
    GridPosition getTargetPosition() const;
};

#endif // SHOT_H
