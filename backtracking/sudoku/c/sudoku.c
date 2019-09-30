//Author: Simon W.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define board_max 9
#define true 1
#define false 0

int check_board(int sudoku_board[][board_max], int row, int col, int num); //board validation with paramters - active sudoku board, row index, col index, digit comparator
int solve_sudoku(int sudoku_board[][board_max], int row, int col);		   //just backtracking through the whole board to solve the board
int find_value(int duplicate_board_value, int solved_board_value);
void color_print(int s, int found);

int main()
{	
	//define indexing variables, board to be copied into to print colored values and puzzle board
	int x, y, iterations = 0, copy_board[board_max][board_max], sudoku_puzzle[board_max][board_max] = { {0,0,0,0,8,0,1,0,0},
																								        {0,0,3,0,0,0,2,0,4},
																	                                    {4,0,0,2,0,0,0,0,7},
																	                                    {0,9,0,5,0,0,0,0,0},
																	                                    {5,0,0,8,0,3,0,7,1},
																	                                    {0,8,4,0,0,0,0,5,6},
																	                                    {0,0,7,3,0,0,0,1,0},
																	                                    {0,6,9,0,0,1,8,0,0},
																	                                    {0,0,0,0,4,0,0,0,0} };
	//COPY the board so we can check if the values in our solved table are from the original table
	//this way we can change the color of the newly found values when printing
	for (x = 1; x < board_max + 1; ++x)
	{
		for (y = 1; y < board_max + 1; ++y) {
			copy_board[x - 1][y - 1] = sudoku_puzzle[x - 1][y - 1];
		}
	}

	//PRINT the unsolved board
	printf("======The UNSOLVED puzzle======\n");
	printf("     +++++++++++++++++++\n"); //simple method of formatting the table - 19 characters
	for (x = 1; x < board_max+1; ++x)
	{
		printf("     ");
		for (y = 1; y < board_max+1; ++y) {
			if (sudoku_puzzle[x - 1][y - 1] == 0) {
				printf("|");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 4); //set the output color to red
				printf("%d", sudoku_puzzle[x - 1][y - 1]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15); //set the output color back to white
		}
			else {
				printf("|%d", sudoku_puzzle[x - 1][y - 1]); //print the number normally
			}
		}
		printf("| \n");
		if (x % 3 == 0) {
			printf("     +++++++++++++++++++\n"); //when you come to the end of a row, print
		}
	}

	//===Here we begin solving the puzzle===
	printf("\n======The SOLVED puzzle======\n");
	if (solve_sudoku(sudoku_puzzle, 0, 0)) //if we able to traverse the table - solve it
	{
		printf("     +++++++++++++++++++\n"); //simple method of formatting the table - 19 characters
		for (x = 1; x < board_max+1; ++x)
		{
			printf("     ");
			for (y = 1; y < board_max+1; ++y) {
				printf("|");
				int check = find_value(copy_board[x - 1][y - 1], sudoku_puzzle[x - 1][y - 1]); //checking if the number exists in the original table
				if (!check) {
					color_print(sudoku_puzzle[x - 1][y - 1], false); //solve the puzzle and return the value to the console but color it GREEN
				}
				else {
					color_print(sudoku_puzzle[x - 1][y - 1], true); //the value should be one of the original values in the given puzzle, return it to the console and print it WHITE
				}
			}
			printf("| \n");
			if (x % 3 == 0) {
				printf("     +++++++++++++++++++\n"); //when you come to the end of a row, print //more formatting lines for each nonet
			}
		}
	}
	else {
		printf("\n\n****ERROR****\n\n");
	}
	return 0;
}

int solve_sudoku(int sudoku_board[][board_max], int row, int col) {
	if (row < board_max && col < board_max) { //if we are able to index through valid locations
		if (sudoku_board[row][col]) { //indexing - if there is a valid number at at an indice that is not 0
			if ((col + 1) < board_max) { //if the current column plus 1 is less than 9 - allows us to compare the adjacent column
				return solve_sudoku(sudoku_board, row, col + 1); //try all the numbers that could be at this index recursively
			}
			else if ((row + 1) < board_max) { //same goes for rows
				return solve_sudoku(sudoku_board, row + 1, 0); //same here
			}
			else {
				return 1; //f1
			}
		} //end if
		else { //for values that are zero
			for (int input = 1; input <= board_max; ++input) { //testing valid numbers, do not start at 0
				if (check_board(sudoku_board, row, col, input)) { //check if the number can be there validly
					sudoku_board[row][col] = input; //input the number
					if ((col + 1) < board_max) {
						if (solve_sudoku(sudoku_board, row, col + 1)) {
							return 1; //f2
						}
						else {
							sudoku_board[row][col] = 0;
						}
					}
					else if ((row + 1) < board_max){
						if (solve_sudoku(sudoku_board, row + 1, 0)) {
							return 1; //f3
						}
						else {
							sudoku_board[row][col] = 0;
						}
					}
					else {
						return 1; //f4
					} //end if
				} //end if
			} //end for
		} //end else
		return 0;
	} //end if
	else {
		return 1;
	}
}

int check_board(int sudoku_board[][board_max], int row, int col, int num) {
	int row_index_start = (row / 3) * 3; //curent starting row index - important to note integer trucation
	int col_index_start = (col / 3) * 3; //current starting column index

	//going through the entire table, by row and by column
	for (int i = 0; i < board_max; ++i){//indexing, start at 0
		if (sudoku_board[row_index_start + (i % 3)][col_index_start + (i / 3)] == num) { //check the values in the current nonet (3x3 box)
			return 0;
		}
		if (sudoku_board[row][i] == num) {//clheck all of the indices in the current row
			return 0;
		}
		if (sudoku_board[i][col] == num) { //check all of the indices in the current column
			return 0;
		}
	}
	return 1;
}

int find_value(int duplicate_board_value, int solved_board_value) {

	if (duplicate_board_value == solved_board_value) {
		return 1; //if the value in the original board matches
	}
	else {
		return 0;
	}
}

void color_print(int s, int found)
{
		if (found == true)
		{
			printf("%d", s); //print like normal
		}
		else if (found == false)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 2); //set the output color to green
			printf("%d", s); //print 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15); //change it back to white
		}
}