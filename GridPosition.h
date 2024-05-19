/*
 * GridPosition.h
 *
 *  Created on: 21-Dec-2023
 *      Author: Priyanka
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_
#include <string>
using namespace std;
class GridPosition
{
private:
    /*
     * Represents the row of the grid (e.g., 'A', 'B', ...)
     */
	char row;
	/*
	 * Represents the column of the grid (1, 2, 3, ...)
	 */
	int column;
public:
	/*
	 * Constructor that initializes a GridPosition
	 * with a given row and column
	 */
	GridPosition(char row,int column);
	/*
	 * Constructor that initializes a GridPosition from a
	 * string representation (e.g., "A5")
	 */
	GridPosition(std::string position);
    /*
     * Checks if the current GridPosition is valid
     * (e.g., row is within acceptable range)
     */
    bool isValid() const;
    /*
     * function to retrieve the row of the GridPosition
     */
    char getRow() const;
    /*
     *  function to retrieve the column of the GridPosition
     */
    int getColumn() const;
    /*
     * function to Conversion operator to convert the
     * GridPosition to a string representation
     */
    operator std::string() const;
    /*
     * Equality operator to check if two GridPositions are equal
     *  and returns true or false
     */
    bool operator==(const GridPosition& other) const;
    /*
     *  Less-than operator to determine ordering of GridPositions
     *  It is used in intersection and
     *  also in finding the sunken ships when bow and stern is given
     */
    bool operator<(const GridPosition& other) const;



	virtual ~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
