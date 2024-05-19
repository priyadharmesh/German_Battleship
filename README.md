# German_Battleship
Battleship Game: Object-Oriented Model
Introduction
This project involves creating an object-oriented (OO) model of the classic game Battleship. The goal of the initial version is to replace the paper-based gameplay, allowing a player to arrange ships, track opponent’s shots, and keep track of their own shots. The program will not support multiplayer; players must still communicate with their opponents, who may use a traditional sheet of paper.

Project Structure
The project is divided into three major parts, each enriching the model from basic elements to a complete game representation.

Part 1: Basic Classes
GridPosition Class

Represents a position on the board with a row and a column.
Immutable class; once created, its state cannot be modified.
Can be created from a row and column or from a string (e.g., "B10").
Includes methods to check validity (isValid), convert to string, and compare positions.
Ship Class

Represents a ship with a bow and stern position.
Immutable class.
Includes methods to check validity (isValid), get the bow and stern positions, calculate length, and determine occupied and blocked areas on the grid.
OwnGrid and OpponentGrid Classes

Represent the player's grid and the opponent's grid, respectively.
OwnGrid manages ship placement and validates the arrangement according to the rules.
OpponentGrid tracks the opponent's shots and updates the state accordingly.
Board Class

Contains both OwnGrid and OpponentGrid.
Provides methods to access the grids and the board dimensions.
ConsoleView Class

Displays the current state of the board on the console.
Utilizes information from the Board class to print the grids.
Part 2: Display and Arrangement Rules
Display

ConsoleView's print method shows the current state of the board, displaying arranged ships and preparing for displaying the opponent's grid.
Utilizes a char array to represent the grids and fill them based on the game state.
Arrangement Rules

Ships must not touch each other, must form a straight line, and must be positioned horizontally or vertically.
Each player has a specific number of ships of varying lengths (e.g., 1 carrier, 2 battleships, 3 destroyers, and 4 submarines).
OwnGrid::placeShip method checks all these conditions before placing a ship.
Part 3: Shots
Shot Class

Represents a shot taken at a target position on the grid.
Includes an enumeration for the impact of a shot (NONE, HIT, SUNKEN).
Taking Blows

OwnGrid::takeBlow method determines the impact of a shot (miss, hit, or sunk).
Checks all ships to see if they are hit or sunk by the shot.
Tracking Opponent Shots

OpponentGrid::shotResult method records the result of a shot and updates the list of sunken ships.
Updated Display

ConsoleView's print method now also displays misses and hits, providing a visual representation of the game state.
Conclusion
The Battleship Game project provides a comprehensive and object-oriented approach to modeling the classic game. It includes detailed class structures for grid positions, ships, grids, and shots, ensuring a robust and accurate representation of the game state. The ConsoleView class offers a clear and user-friendly interface to display the game, making it easy to track and manage the game progress.

This project showcases the use of advanced C++ features such as smart pointers and container classes from the C++ standard library, ensuring efficient and effective memory management and data handling. The structured approach and adherence to the game rules ensure a realistic and enjoyable gameplay experience.
