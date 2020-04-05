
// HUU NGOC CHINH CAO
// 4529434
// COP 3502C 00308
// FALL SEMESTER 2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SneakyRooks.h"


//This function check if the rooks can attack each other
int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize)
{
	int *isRow, *isCol; 
	int i, j;
	Coordinate *coor;
	
	// Malloc
	isRow = malloc(sizeof(int) * (boardSize + 1));
	isCol = malloc(sizeof(int) * (boardSize + 1));
	coor = malloc(sizeof(Coordinate));
	
	// Malloc fail check
	if (isRow == NULL || isCol == NULL || coor == NULL)
		return 1;

	// Case no rook on chess board
	if (rookStrings[0] == "")
	{
		free(isRow);
		free(isCol);
		free(coor);
		return 1; 
	}
	
	// Initialize isRow and isCol to 0
	for (i = 1; i <= boardSize; i++)
	{
		isRow[i] = 0;
		isCol[i] = 0;
	}

	// Loop through rookStrings
	for (j = 0; j < numRooks; j++)
	{
		// Call parse function
		parseCoordinateString(rookStrings[j], coor);
		
		// Check if the rooks can attack each other
		if (isRow[coor->row] == 1 || isCol[coor->col] == 1)
		{
			// Free after return
			free(isRow);
			free(isCol);
			free(coor);
			return 0;
		}
	
		// Switch isRow and isCol to 1 so that the
		// program knows there is a rook at that position
		isRow[coor->row] = 1;
		isCol[coor->col] = 1;
	}
	
	// Free after return
	free(isRow);
	free(isCol);
	free(coor);
	
	//Return 1 if the rooks cannot attack each other
	return 1;
}


//This function parse through rookString to determine the numeric row and column where the
//given rook resides on the chess board
void parseCoordinateString(char *rookString, Coordinate *rookCoordinate)
{
	int newCol = 0, newRow = 0;
	int i, t;
	int x = 0, y = 0;
	int temp1 = 1, temp2 = 1;
	
	//Loop through rookString to findout how many digit and alpha
	for (i = 0; i < strlen(rookString); i++)
	{
		if (isalpha(rookString[i]))
			x++;
		if (isdigit(rookString[i]))
			y++;
	}
		
	// Loop through rookString again
	for (i = 0; i < strlen(rookString); i++)
	{		
		// Convert string to rook's position
		if (isalpha(rookString[i]))
		{
			x--;
			for (t = 0; t < x; t++)
			{
				temp1 = temp1 * 26;
			}
			newCol = temp1 * (rookString[i] - 'a' + 1) + newCol;
			temp1 = 1;
		}
		if (isdigit(rookString[i]))
		{
			y--;
			for (t = 0; t < y; t++)
			{
				temp2 = temp2 * 10;
			}
			newRow = temp2 * (rookString[i] - '0') + newRow;
			temp2 = 1;
		}
	}
	
	// Pass the result to struct
	rookCoordinate->col = newCol;
	rookCoordinate->row = newRow;
}

//Difficult rate
double difficultyRating(void)
{
	return 3.0;
}

//Hour spent in this assignment
double hoursSpent(void)
{
	return 2.0;
}