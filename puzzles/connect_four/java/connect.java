//This is for connect.java

import java.util.*;
import java.io.*;
import java.util.Map;
import java.lang.*;

class InvalidRowException extends Exception
{
	public InvalidRowException()
	{
	}
}

class InvalidColumnException extends Exception
{
	public InvalidColumnException()
	{
	}
}

class connectFour
{
	int NONE = 0;
	int RED = 1;
	int BLACK = 2;
	int boardColumns, boardRows, turn, winner, count;     //= 7, 6
	int[][] board;                   // = new int[boardRows][boardColumns];
	int[][] neighbors = {{0,1},{1,1},{1,0},{1,-1},
						 {0,-1},{-1,-1},{-1,0},{-1,1}};
	boolean gameOver;

	//GameState gameState = new GameState();

	public connectFour () // constructor
	{
		this.boardColumns = 7;
		this.boardRows = 6;
		this.turn = RED;
		this.winner = NONE;
		board = new int[boardRows][boardColumns];
	}

	public void createNewGame()
	{
		this.turn = RED;
		this.winner = NONE;
		this.board = new int[boardRows][boardColumns];
		gameOver = false;
		//gameState = new GameState(boardRows, boardColumns, playerTurn);
	}

	public void drop(int columnNum) throws InvalidRowException, InvalidColumnException
	{
		if (checkValidColumnNumber(columnNum))
		{
			int rowNum = getEmptyBottomRowOfColumn(columnNum);
			if (checkValidRowNumber(rowNum))
			{
				board[rowNum][columnNum] = turn;
				checkIfGameOver(rowNum, columnNum);
				changeTurn();
			}
			else
			{
				throw new InvalidRowException();
			}
		}
		else
		{
			throw new InvalidColumnException();
		}
	}

	public void printBoard()
	{
		int spot;
		for (int i = 0; i < boardRows; i++)
		{
			for (int j = 0; j < boardColumns; j++)
			{
				spot = board[i][j];
				if (spot == RED)
					System.out.print("R ");
				else if (spot == BLACK)
					System.out.print("B ");
				else 
					System.out.print(". ");
			}
			System.out.println();
		}
	}

	public void printTurn()
	{
		System.out.println("TURN: " + ((turn == RED) ? "RED" : "BLACK"));
	}

	public void printWinner()
	{
		System.out.println("WINNER: " + ((winner == RED) ? "RED" : "BLACK"));	
	}

	public void printNoWinner()
	{
		System.out.println("WINNER: DRAW");	
	}

	private void changeTurn()
	{
		this.turn = ((this.turn == RED) ? BLACK : RED);
	}

	private int getEmptyBottomRowOfColumn(int colNum)
	{
		for (int i = boardRows - 1; i >= 0; i--)
		{
			if (board[i][colNum] == NONE)
			{
				return i;
			}
		}
		return -1;
	}

	private boolean checkValidColumnNumber(int colNum)
	{
		return (0 <= colNum && colNum < boardColumns);
	}

	private boolean checkValidRowNumber(int rowNum)
	{
		return (0 <= rowNum && rowNum < boardRows);
	}

	private boolean isFourInARow(int rowNum, int colNum, int adjRow, int adjCol)
	{
		int startingCell;
		boolean  result = false;

		if (checkValidRowNumber(rowNum) && checkValidColumnNumber(colNum))
			startingCell = board[rowNum][colNum];
		else
			return result;

		if (startingCell != NONE)
		{
			int newRow, newCol;
			for (int i = 1; i <= 3; i++)
			{
				newRow = rowNum + (adjRow * i);
				newCol = colNum + (adjCol * i);
				if (!checkValidRowNumber(newRow) || !checkValidColumnNumber(newCol) ||
					board[newRow][newCol] != startingCell)
				{
					return result;
				}
			}
			result = true;
		}
		return result;
	}

	private boolean checkForWinner(int rowNum, int colNum)
	{
		int rowNeighbor, colNeighbor;
		for (int i = 0; i < 8; i++)
		{
			rowNeighbor = neighbors[i][0];
			colNeighbor = neighbors[i][1];
			if (isFourInARow(rowNum, colNum, rowNeighbor, colNeighbor))
				return true;
			for (int j = 0; j < 8; j++)
			{
				if (isFourInARow((rowNum + rowNeighbor), (colNum + colNeighbor),
					             (neighbors[j][0]),(neighbors[j][1])))
					return true;
			}
		}
		return false;
	}

    private void checkIfGameOver(int rowNum, int columnNum)
	{
		if (checkForWinner(rowNum, columnNum))
		{
			winner = turn;
			printBoard();
			printWinner();
			gameOver = true;
		}
		else
		{
			count = 0;
			for (int i = 0; i < boardRows; i++)
			{
				for (int j = 0; j < boardColumns; j++)
				{
					if (board[i][j] == NONE)
						count++;
				}
			}
			if (count == 0)
			{
				printBoard();
				printNoWinner();
				gameOver = true;
			}
		}
	}

	public boolean isGameOver()
	{
		return gameOver;	
	}

	public void quit()
	{
		gameOver = true;
	}
}

public class connect 
{
	public static void printCommands()
	{
		System.out.println("--------------- WELCOME TO CONNECT FOUR ---------------");
		System.out.print("Player Red will always start first. The grid is set to \n" +
			             "6 x 7 and cannot be modified. To play, the player may \n" +
			             "input the column they wish to enter from the range of \n" +
			             "1 - 7. The game will automatically place the piece to \n" +
			             "the bottom of the board for the specified column. The \n" +
			             "Winner is the first to connect 4 pieces.\n\n");
		System.out.println("* To quit the game, enter '0' at any time.");
		System.out.println("* To place a piece, enter a number from 1 - 7. When a \n" +
			               "  Column is full, you are no longer able to put a piece\n" +
			               "  in that column.");
	}

	public static void main(String[] args) throws IOException
	{
		int input;
		boolean quit = false;
		connectFour CFour = new connectFour();
		CFour.createNewGame();
		printCommands();
		while(!CFour.isGameOver())
		{
			CFour.printBoard();
			CFour.printTurn();
			Scanner in = new Scanner(System.in);
			try
			{
				input = in.nextInt();
				System.out.println("Your Input:" + input);
				if (input == 0)
				{
					CFour.quit();
				}
				else
				{
					try 
					{
						CFour.drop(input-1);
					}
					catch (InvalidRowException ex)
					{
						System.out.println("ERROR: The column number used cannot be " + 
							               "placed anymore. Try a different column.");
					}
					catch (InvalidColumnException ex)
					{
						System.out.println("ERROR: The column number used is invalid." +
							               "Try a different column.");
					}
				}
			}
			catch (InputMismatchException ex)
			{
				System.out.println("Invalid Input. Must be a number from 1 - 7");
			}
		}
	}
	
}