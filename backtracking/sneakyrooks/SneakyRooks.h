#ifndef __SNEAKY_ROOKS_H
#define __SNEAKY_ROOKS_H


typedef struct Coordinate
{
	int col;  // The column where this rook is located (1 through board width).
	int row;  // The row where this rook is located (1 through board height).
} Coordinate;


// Functional Prototypes

int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize);

void parseCoordinateString(char *rookString, Coordinate *rookCoordinate);

double difficultyRating(void);

double hoursSpent(void);

#endif
