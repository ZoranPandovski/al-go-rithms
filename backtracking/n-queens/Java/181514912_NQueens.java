/*The N Queen is the problem of placing N chess queens on an N×N 
chessboard so that no two queens attack each other.
n=1 , trivial solution
n=2 and 3 , no solutions exist
n>=4 , solutions exist*/

import java.util.Scanner;
public class N_QueenProblem {
	static int n=0;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		System.out.print("Number of Queens to be placed, N = "); //give n>=4
		n=in.nextInt();
		in.close();
		int board[][]=new int[n+1][n+1];
		boolean result=nQueen(board,n);
		if(result) {
			printBoard(board);
		}else {
			System.out.println("Not Possible !!");
		}
	}
	public static boolean nQueen(int[][] board,int noq) {
		if(noq==0) {
			return true;	// all queens have been placed
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(isAttacked(i, j, board)) {
					continue;	// skip and move to next cell
				}
				board[i][j]=1;	// place current queen at (i,j)
				if(nQueen(board, noq-1))	// solve sub-problem
					{return true;}
				board[i][j]=0;	// if solution not found undo changes made i.e., remove the queen from (i,j)
			}
		}
		return false;
	}
  
  /* This function checks if the current position is under attack
  or not*/
	public static boolean isAttacked(int x,int y,int[][] board) {
		
		for(int i=1;i<=n;i++) {	// checking for row and column
			if(board[x][i]==1)
				return true;
			if(board[i][y]==1)
				return true;
		}
		for(int i=1;i<=n;i++) {		// checking for the diagonals
			for(int j=1;j<=n;j++) {
				if((i+j)==(x+y) && board[i][j]==1) {
					return true;
				}
				if((i-j)==(x-y) && board[i][j]==1) {
					return true;
				}
			}
		}
		return false;
	}
  
  /* This function print the chess board with 0 as empty cell and
  1 as the occupied cell*/
	public static void printBoard(int[][] board) {
		for(int line=1;line<=n;line++) {
			for(int value=1;value<=n;value++) {
				System.out.print(board[line][value]+" ");	//print the board
			}
			System.out.println();
		}
	}
}
