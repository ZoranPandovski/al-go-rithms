/**
 * @author https://github.com/swoldemi/
 * Quick port of ./c/sudoku.c
 */
public class Sudoku {
	
	static int check_board(int[][] sudoku_board, int row, int col, int num){
		int row_index_start = (row / 3) * 3; //current starting row index - important to note integer truncation
		int col_index_start = (col / 3) * 3; //current starting column index

		//going through the entire table, by row and by column
		for (int i = 0; i < 9; ++i){//indexing, start at 0
			if (sudoku_board[row_index_start + (i % 3)][col_index_start + (i / 3)] == num) { //check the values in the current nonet (3x3 box)
				return 0;
			}
			if (sudoku_board[row][i] == num) {//check all of the indices in the current row
				return 0;
			}
			if (sudoku_board[i][col] == num) { //check all of the indices in the current column
				return 0;
			}
		}
		return 1;
	}
	
	static int solve_sudoku(int sudoku_board[][], int row, int col) {
		if (row < 9 && col < 9) { //if we are able to index through valid locations
			if (sudoku_board[row][col] != 0) { //indexing - if there is a valid number at at an indice that is not 0
				if ((col + 1) < 9) { //if the current column plus 1 is less than 9 - allows us to compare the adjacent column
					return solve_sudoku(sudoku_board, row, col + 1); //try all the numbers that could be at this index recursively
				}
				else if ((row + 1) < 9) { //same goes for rows
					return solve_sudoku(sudoku_board, row + 1, 0); //same here
				}
				else {
					return 1; //f1
				}
			} //end if
			else { //for values that are zero
				for (int input = 1; input <= 9; ++input) { //testing valid numbers, do not start at 0
					if (check_board(sudoku_board, row, col, input)==1) { //check if the number can be there validly
						sudoku_board[row][col] = input; //input the number
						if ((col + 1) < 9) {
							if (solve_sudoku(sudoku_board, row, col + 1)==1) {
								return 1;
							}
							else {
								sudoku_board[row][col] = 0;
							}
						}
						else if ((row + 1) < 9){
							if (solve_sudoku(sudoku_board, row + 1, 0)==1) {
								return 1;
							}
							else {
								sudoku_board[row][col] = 0;
							}
						}
						else {
							return 1;
						}
					}
				}
			}
			return 0;
		}
		else {
			return 1;
		}
	}
	
	static int find_value(int duplicate_board_value, int solved_board_value){
		if (duplicate_board_value == solved_board_value) {
			return 1; //if the value in the original board matches
		}
		else {
			return 0;
		}
	}
	
	public static void main(String[] args) {    
		int x, y;
		int[][] copy_board = new int[9][9];
		int[][] sudoku_puzzle = new int[][]{{0,0,0,0,8,0,1,0,0},
											{0,0,3,0,0,0,2,0,4},
											{4,0,0,2,0,0,0,0,7},
								            {0,9,0,5,0,0,0,0,0},
								            {5,0,0,8,0,3,0,7,1},
								            {0,8,4,0,0,0,0,5,6},
								            {0,0,7,3,0,0,0,1,0},
								            {0,6,9,0,0,1,8,0,0},
								            {0,0,0,0,4,0,0,0,0} };
		for (x = 1; x < 9 + 1; ++x)
		{
			for (y = 1; y < 9 + 1; ++y) {
				copy_board[x - 1][y - 1] = sudoku_puzzle[x - 1][y - 1];
			}
		}
		
		System.out.print("======The UNSOLVED puzzle======\n");
		System.out.print("     +++++++++++++++++++\n"); //simple method of formatting the table - 19 characters
		for (x = 1; x < 9+1; ++x)
		{
			System.out.print("     ");
			for (y = 1; y < 9+1; ++y) {
				if (sudoku_puzzle[x - 1][y - 1] == 0) {
					System.out.print("|");
					System.out.print(sudoku_puzzle[x - 1][y - 1]);
			}
				else {
					System.out.print("|" + sudoku_puzzle[x - 1][y - 1]); //print the number normally
				}
			}
			System.out.print("| \n");
			if (x % 3 == 0) {
				System.out.print("     +++++++++++++++++++\n"); //when you come to the end of a row, print
			}
		}
		
		System.out.print("\n======The SOLVED puzzle======\n");
		solve_sudoku(sudoku_puzzle, 0, 0);
		System.out.print("     +++++++++++++++++++\n"); //simple method of formatting the table - 19 characters
		for (x = 1; x < 9+1; ++x)
		{
			System.out.print("     ");
			for (y = 1; y < 9+1; ++y) {
				System.out.print("|");
				System.out.print(sudoku_puzzle[x - 1][y - 1]); 
			}
			System.out.print("| \n");
			if (x % 3 == 0) {
				System.out.print("     +++++++++++++++++++\n"); //when you come to the end of a row, print //more formatting lines for each nonet
			}
		}
	
	}
}