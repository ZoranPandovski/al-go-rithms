// C# program to find the shortest
// path between a given source cell
// to a destination cell.
using System;
using System.Collections.Generic;

class GFG
{
static int ROW = 9;
static int COL = 10;

// To store matrix cell coordinates
public class Point
{
	public int x;
	public int y;

	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
};

// A Data Structure for queue used in BFS
public class queueNode
{
	// The coordinates of a cell
	public Point pt;
	
	// cell's distance of from the source
	public int dist;

	public queueNode(Point pt, int dist)
	{
		this.pt = pt;
		this.dist = dist;
	}
};

// check whether given cell (row, col)
// is a valid cell or not.
static bool isValid(int row, int col)
{
	// return true if row number and
	// column number is in range
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
static int []rowNum = {-1, 0, 0, 1};
static int []colNum = {0, -1, 1, 0};

// function to find the shortest path between
// a given source cell to a destination cell.
static int BFS(int [,]mat, Point src,
						Point dest)
{
	// check source and destination cell
	// of the matrix have value 1
	if (mat[src.x, src.y] != 1 ||
		mat[dest.x, dest.y] != 1)
		return -1;

	bool [,]visited = new bool[ROW, COL];
	
	// Mark the source cell as visited
	visited[src.x, src.y] = true;

	// Create a queue for BFS
	Queue<queueNode> q = new Queue<queueNode>();
	
	// Distance of source cell is 0
	queueNode s = new queueNode(src, 0);
	q.Enqueue(s); // Enqueue source cell

	// Do a BFS starting from source cell
	while (q.Count != 0)
	{
		queueNode curr = q.Peek();
		Point pt = curr.pt;

		// If we have reached the destination cell,
		// we are done
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// Otherwise dequeue the front cell
		// in the queue and enqueue
		// its adjacent cells
		q.Dequeue();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			
			// if adjacent cell is valid, has path
			// and not visited yet, enqueue it.
			if (isValid(row, col) &&
					mat[row, col] == 1 &&
			!visited[row, col])
			{
				// mark cell as visited and enqueue it
				visited[row, col] = true;
				queueNode Adjcell = new queueNode
						(new Point(row, col),
								curr.dist + 1 );
				q.Enqueue(Adjcell);
			}
		}
	}

	// Return -1 if destination cannot be reached
	return -1;
}

// Driver Code
public static void Main(String[] args)
{
	int [,]mat = {{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
				{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
				{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
				{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
				{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
				{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
				{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

	Point source = new Point(0, 0);
	Point dest = new Point(3, 4);

	int dist = BFS(mat, source, dest);

	if (dist != -1)
		Console.WriteLine("Shortest Path is " + dist);
	else
		Console.WriteLine("Shortest Path doesn't exist");
	}
}

