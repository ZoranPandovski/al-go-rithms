/*
	Find the solution of simple maze.
*/
public class RatInAMaze
{
	
	private static final int FREE = 0;
	private static final int WALL = 1;
	private static final int TRAVELED = 2;
	private static final int FINISH = 3;
	
	public static void main( String[] args )
	{
		int[][] maze = {
			{1, 0, 1, 1, 1, 1, 1, 1 ,1},
			{1, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 0, 1, 0, 1, 1},
			{1, 0, 0, 0, 0, 1, 0, 0, 1},
			{1, 1, 1, 1, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 1, 0, 0, 0},
			{1, 0, 1, 1, 0, 0, 0, 1, 1},
			{1, 0, 0, 1, 0, 1, 0, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
		
		if( resolveMaze( maze, 0, 1 ) )
		{
			System.out.println("Solution found.");
			
			for( int row = 0; row < maze.length; ++row )
			{
				for( int col = 0; col < maze[row].length; ++col )
				{
					System.out.print( maze[row][col] + " " );
				}
				System.out.println();
			}
		}
		else
		{
			System.out.println( "There is no solution." );
		}
		
	}
	
	private static final int[] DELTA_ROW = {+1,  0, -1,  0};
	private static final int[] DELTA_COL = { 0, -1,  0, +1};
	
	private static boolean resolveMaze( int[][] map, int row, int col )
	{
		if( isItFinish( map, row, col ) )
		{
			map[row][col] = FINISH;
			return true;
		}
		else {
			map[row][col] = TRAVELED;
			
			for (int k = 0; k < 4; k++) {
				int nextRow = row + DELTA_ROW[k];
				int nextCol = col + DELTA_COL[k];
				
				if( nextRow >= 0 && nextRow < map.length
						&& nextCol >= 0 && nextCol < map[nextRow].length
						&& map[nextRow][nextCol] == FREE )
				{
					
					if( resolveMaze( map, nextRow, nextCol ) )
					{
						map[row][col] = FINISH;
						return true;
					}
				}
			}
			
			return false;
		}
	}
	
	private static boolean isItFinish(int[][] map, int row, int col) {
		if( row == map.length - 1 ) return true;
		if( ( row == 0) && col != 1 ) return true;
		if( ( col == map[row].length - 1 ) ) return true;
		if( col == 0 ) return true;
		return false;
	}
}
