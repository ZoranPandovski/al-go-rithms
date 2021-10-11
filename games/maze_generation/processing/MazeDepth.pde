import java.util.Stack;

class MazeDepth implements GenMaze {
  
cell[][] maze; //holds our maze
Stack<cell> path; //holds the current path we have taken
cell current; //current cell we are on in maze
character dude;
int x; //current xcor within array [y][x]
int y; //current ycor within array [y][x]
int newX; //used for transitions with midX
int newY; //used for transitions with midY
int midX; //used for walls in between cells
int midY; //used for walls in between cells
int numRow;
int numCol;
cell exit;


 MazeDepth(int w, int h) {
  //start at upperleft hand corner
  //init vars
  numRow = h / 16;
  numCol = w / 16;
  maze = new cell[numRow][numCol];
  for ( int i = 0; i < numRow; i++ ) {
    for ( int j = 0; j < numCol; j++ ) {
      maze[i][j] = new wall(j*16, i*16); //generates matrix of walls
    }
  }
  for ( int i = 2; i < numRow-1; i += 2 ) {
    for ( int j = 2; j < numCol-1; j += 2 ) {
      maze[i][j] = new cell(j*16, i*16);
      //creates cells 2 spaces apart with a 2 cell
      //buffer zone around the edges, helps with out of bounds
      //exceptions
    }
  }
  //start at upperleft hand corner
  //init vars
  x = 2;
  y = 2;
  current = maze[2][2];
  path = new Stack();
  current.visit();
  dude = new character();
}

void generate() {  
  //delay(100); //stops .1 second each frame for better visualization
 
  //if current cell has neighbors
  if ( hasNeighbors() ) {
    //choose a path
    getNext();
  }
  
  //otherwise if we can backtrack
  else if ( !path.isEmpty() ) {
    //get last placement and go through draw again
    current.backTrack(); //shows backtracking process
    
    current = path.pop();
    
    newX = current.getX() / 16;
    newY = current.getY() / 16;
    
    midX = (newX + x)/2;
    midY = (newY + y)/2;
    
    maze[midY][midX].backTrack();
    
    x = newX;
    y = newY;
    
    //System.out.println("current popped");
    //System.out.println(x);
    //System.out.println(y);
    
    current.backTrack();

    }
}




//returns if a cell in the array has unvisited neighbors 
//to travel to
boolean hasNeighbors() {
  return maze[y+2][x].unvisited() || maze[y-2][x].unvisited() || maze[y][x-2].unvisited() || maze[y][x+2].unvisited();
}

//updates current and moves to next cell
//as well as removes wall by converting it to
//a visited cell
void getNext() {
  double rand;
  cell ret;
  path.push(current);//add our last location to the stack
  //System.out.println("current pushed");
  ret = current;//give ret an init value that passes first case
  
  while ( !ret.unvisited() ) {
    //while our new current has been visited
    //look for another
    rand = Math.random();
    
    if ( rand < .25 ) {
      ret = maze[y+2][x];
    }
    else if ( rand < 0.5 ) {
      ret = maze[y-2][x];
    }
    else if ( rand < 0.75 ) {
      ret = maze[y][x-2];
    }
    else {
      ret = maze[y][x+2];
    }
  }
  
  newX = ret.getX() / 16;//new array xcor
  newY = ret.getY() / 16;//new array ycor
  
  //System.out.println(newX);
  //System.out.println(newY);
  
  midX = (newX+x)/2;//wall array xcor
  midY = (newY+y)/2;//wall array ycor
  
  //System.out.println(midX);
  //System.out.println(midY);
  
  maze[midY][midX] = (cell) maze[midY][midX];//typecast wall to cell
  maze[midY][midX].visit();//turn wall to visited cell
  
  //update vars
  x = newX;
  y = newY;
  current = ret;
  current.visit();
} 

cell[][] getMaze() {
  return maze;
}

void displayMaze() {
  for ( int i = 0; i < maze.length; i++ ) {
    for ( int j = 0; j < maze[0].length; j++ ) {
      maze[i][j].displayCell();
    }
  }
}

boolean generated() {
  return maze[2][2].getColor() == color(0,256,0);
}

  void makeExit() { 
    boolean bool = true; 
    while (bool) { 
      int rand1 = (int) (random(maze.length/4) + 3*maze.length/4); 
      int rand2 = (int) (random(maze[0].length/4) + 3*maze[0].length/4); 
      if (!(maze[rand1][rand2] instanceof wall)) { 
        maze[rand1][rand2].setColor(color(0,256,256)); 
        bool = false; 
        exit = maze[rand1][rand2];
      } 
    }
  }
cell getExit() {
  return exit;
}

}