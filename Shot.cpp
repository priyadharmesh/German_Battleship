/*
 * Shot.cpp
 *
 *  Created on: 07-Jan-2024
 *      Author: Priyanka
 */

#include "Shot.h"

// Constructor definition for Shot
Shot::Shot(GridPosition targetPos) : targetPosition(targetPos) {
    // Additional initialization if needed
}

// Getter definition for targetPosition
GridPosition Shot::getTargetPosition() const {
    return targetPosition;
}

