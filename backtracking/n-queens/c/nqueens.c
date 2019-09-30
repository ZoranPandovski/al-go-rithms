/* N Queens backtracking algorithm
 * For more information:
 * https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/
 */

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define N (100) /* maximum number of N for 2D array */

/* Return true if position (x, y) 
 * is attacked by some queen in board 
 * Verify if exists another queen in the same column, row or diagonal */
bool is_attacked(int x, int y, int board[][N], int dim) {
	int i, j;

	/* For all (i, j) positions in grid */
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (board[i][j]) {
				/* (i,j) is in the same diagonal */
				if (i+j == x+y)
					return true;
					
				/* (i,j) is in the same diagonal */
				if (i-j == x-y)
					return true;

				/* (i,j) is the same row or column */
				if (i == x || j == y)
					return true;
			}
		}
	}

	return false;
}

/* Solve the problem of n queens
 * Put a queen in a position, and try
 * to put n-1 queens in other positions
 */
bool n_queens(int board[][N], int n, int dim) {
	int i, j;

	/* if n == 0, it is a solution */
	if (n == 0) return true;

	/* For all (i,j) in grid */
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			/* if (i,j) is attacked, it is not a valid position */
			if (is_attacked(i, j, board, dim))
				continue;

			/* mark (i,j) occupied */
			board[i][j] = 1;

			/* execute now for n-1 queens */
			/* if returns true, there's a solution */
			if (n_queens(board, n-1, dim))
				return true;

			/* if returns false, desoccupied position
			 * and go to next position */
			board[i][j] = 0;
		}
	}

	/* if we don't find a solution, return false */
	return false;
}

int main() {
	int board[N][N], i, j, n, m;
	
	printf("Enter the size of chess board: ");
	scanf("%d", &m);

	printf("Enter the number of queens: ");
	scanf("%d", &n);

	for (i = 0; i < m; i++)
		memset(board[i], 0, m);

	if (n_queens(board, n, m)) {
		/* n_queens return true, there's a solution */
		printf("YES\n");

		/* print the solution */
		for (i = 0; i < m; i++, printf("\n"))
			for (j = 0; j < m; j++)
				printf("%d ", board[i][j]);
	} else {
		printf("NO\n");
	}

	return 0;
}
