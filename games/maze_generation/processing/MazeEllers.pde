
class MazeEllers implements GenMaze {
  
  int row; 
  int col; 
  int rowMaze; 
  int colMaze; 
  boolean generated; 
  cell exit; 
  cell[][] Maze;
  int newSetVal;
  int rowGen;
  
  public MazeEllers (int w, int h) { 
    row = h/16; 
    col = w/16; 
    generated = false; 
    Maze = new cell[row][col]; 
    newSetVal = 100;
    rowGen = 2;
    
    // FILL IT UP 
    
    for ( int i = 0; i < row; i++ ) {
      for ( int j = 0; j < col; j++ ) {
        Maze[i][j] = new wall(j*16, i*16); //generates matrix of walls
      }
    }
    
    for ( int i = 2; i < row-1; i+=2 ) {
      for ( int j = 2; j < col-1; j+=2 ) {
        Maze[i][j] = new cell(j*16,i*16,true,newSetVal); 
        newSetVal += 1;
      }
    }
  } 
  
  void randomlyJoinHorizontal(int r) {
    for (int i = 2; i < col-3; i+=2) {
      if ( Maze[r][i].getColor() != Maze[r][i+2].getColor() ) {
        if ( Math.random() > .5 ) {
          Maze[r][i+1] = (cell) Maze[r][i+1];
          Maze[r][i+1].setColor(Maze[r][i+2].getColor());
          join(Maze[r][i], Maze[r][i+2]);
        }
      }
    }
  }
  
  void joinVertical(int r) { 
    for (int i = 2; i < col-1; i+=2) {
      while ( !Maze[r][i].dropped() ) {
        for (int j = i; j < col-1; j+=2) {
          if ( Maze[r][i].getColor() == Maze[r][j].getColor() && Math.random() > .6 ) {
            Maze[r+1][j] = (cell) Maze[r+1][j];
            Maze[r+1][j].setColor(Maze[r][j].getColor());
            Maze[r+2][j].setColor(Maze[r][j].getColor());
            dropSet(Maze[r][j].getColor());
            break;
          }
        }
      }
    } 
  } 
  
  void joinBottom() { 
    for (int i = 2; i < col-3; i+=2) {
      if ( Maze[18][i].getColor() != Maze[18][i+2].getColor() ) {
        Maze[18][i+1] = (cell) Maze[18][i+1];
        Maze[18][i+1].setColor(Maze[18][i+2].getColor());
        join(Maze[18][i], Maze[18][i+2]);
      }
    }
  }

  
  // From the MazeDepth Code...
  // ======================================================================
  void generate() {  
    frameRate(1);
    if ( rowGen < row-3 ) {    
    randomlyJoinHorizontal(rowGen);
    joinVertical(rowGen);
    unDropSet();
    rowGen += 2; 
    //System.out.println(rowGen);
    }
    
    else {
      joinBottom();
      turnGreen();
      generated = true;
      frameRate(60);
    }
      
  } 
  
  void displayMaze() {
    for ( int i = 0; i < Maze.length; i++ ) {
      for ( int j = 0; j < Maze[0].length; j++ ) {
        //if (!(Maze[i][j] instanceof wall) && Maze[i][j].getColor() != color(0,128,256)) { 
          //Maze[i][j].setColor(color(0,256,0)); 
        //} 
        Maze[i][j].displayCell();
      }
    }
  }
  
  void makeExit() { 
    boolean bool = true; 
    while (bool) { 
      int rand1 = (int) (random(row/4) + 3*row/4); 
      int rand2 = (int) (random(col/4) + 3*col/4); 
      if (!(Maze[rand1][rand2] instanceof wall)) { 
        Maze[rand1][rand2].setColor(color(0,256,256)); 
        bool = false; 
        exit = Maze[rand1][rand2];
      } 
    }
  } 
  
  boolean generated() { 
    return generated;   
  } 
  
  cell[][] getMaze() { 
    return Maze; 
  } 
  
  cell getExit() {
    return exit; 
  } 
  
  void join(cell cellA, cell cellB) {
    if ( green(cellA.getColor()) > green(cellB.getColor()) ) {
      for ( int i = 2; i < row-1; i+=1 ) {
        for ( int j = 2; j < col-1; j+=1 ) {
          if ( Maze[i][j].getColor() == cellB.getColor() ) {
            Maze[i][j].setColor( cellA.getColor() );
          }
        }
      }
    }
    
    else {
      for ( int i = 2; i < row-1; i+=1 ) {
        for ( int j = 2; j < col-1; j+=1 ) {
          if ( Maze[i][j].getColor() == cellA.getColor() ) {
            Maze[i][j].setColor( cellB.getColor() );
          }
        }
      }
    }
  }
  
  void dropSet( color c ) {
    for ( int i = 2; i < row-1; i+=2 ) {
      for ( int j = 2; j < col-1; j+=2 ) {
        if ( Maze[i][j].getColor() == c ) {
          Maze[i][j].drop();
        }
      }
    }
  }
  
  void unDropSet() {
    for ( int i = 2; i < row-1; i+=2 ) {
      for ( int j = 2; j < col-1; j+=2 ) {
        Maze[i][j].undrop();
        }
      }
    }
 
  void turnGreen() {
    for ( int i = 2; i < row-1; i+=1 ) {
      for ( int j = 2; j < col-1; j+=1 ) {
        if ( Maze[i][j].getColor() != color(0,0,0) ) {
          Maze[i][j].setColor(color(0,256,0));
          }
        }
      }
    }
  
  // ======================================================================
  
  
} 