import java.util.ArrayList;

class MazePrim implements GenMaze {
  
  cell[][] maze; //holds our maze
  ArrayList<cell> path; //holds the current path we have taken
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
  int level;

 MazePrim(int w, int h, int lev) {
  //start at upperleft hand corner
  //init vars
  level = lev;
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
  path = new ArrayList<cell>();
  current.visit();
  path.add(current);
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
  else {
    current.backTrack(); 
    /*
    if (maze[y+1][x].getColor() == color(0,0,256)) {
      maze[y+1][x].backTrack();
    }
    if (maze[y-1][x].getColor() == color(0,0,256)) {
      maze[y+1][x].backTrack();
    }
    if (maze[y][x-1].getColor() == color(0,0,256)) {
      maze[y+1][x].backTrack();
    }
    if (maze[y][x+1].getColor() == color(0,0,256)) {
      maze[y+1][x].backTrack();
    }
*/
    for (int i = 0;i < path.size(); i++) {
      if (path.get(i).equals2(current)) {
        path.remove(i);
      }
    }
    newX = current.getX() / 16;
    newY = current.getY() / 16;
    x = newX;
    y = newY;
  }
  if (!path.isEmpty()) {
    double rand = Math.random();
    if (level == 6)
    current = path.get(path.size()*3/4);
    else if (level == 7)
    current = path.get(0);
    else if (level == 1)
    current = path.get(path.size() - 1);
    else {
      if (rand < (level-1)/4.0) {
        current = path.get((int) (Math.random() * path.size()));
      }
      else {
        current = path.get(path.size() - 1);
      }
    }
  }  
}
boolean hasNeighbors() {
    newX = current.getX() / 16;
    newY = current.getY() / 16;
    x = newX;
    y = newY;
  return maze[y+2][x].unvisited() || maze[y-2][x].unvisited() || maze[y][x-2].unvisited() || maze[y][x+2].unvisited();
}

void getNext() {
  double rand;
  cell ret;
  //System.out.println("current pushed");
  ret = current;//give ret an init value that passes first case
    newX = current.getX() / 16;
    newY = current.getY() / 16;
    x = newX;
    y = newY;
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
  path.add(maze[midY][midX]);

  ret.visit();
  path.add(ret);
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
  return path.isEmpty();
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