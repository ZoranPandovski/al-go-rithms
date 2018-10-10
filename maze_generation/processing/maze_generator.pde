GenMaze maze; //holds our maze
character dude;
int level;
int levelsPassed;
boolean chosen;

//time vars
int time; //tracks time round starts in millis
int wait = 30000;//timePerRound
int clockCenterX;//clock X coordinate
int clockCenterY;//clock Y coordinate
float angleIncrement = (1000 * 2 * PI) / (wait * frameRate * 6); // (coverts to seconds * 2pi (circle) ) / ( timePerRound * frameRate * balancing factor )
float timeAngle = 3 * PI / 2;//begin upright 90 degrees
int radius = 16;//16 pixel radius 
String liveStr; 

void setup() {
  background(0, 0, 0);
  size(336, 450);
  dude = new character();
  chosen = false;
  level = 1;
  levelsPassed = 0;
  clockCenterX = (int) (width / 2.5);
  clockCenterY = 400;
  liveStr = "" + dude.getLives(); 
  
}



void draw() {  
  if ( dude.getLives() < 1 ) {
    clear();
  }
  
  else if ( !chosen ) {
    
    if ( level == 1 ) {
      maze = new MazeDepth(width, height-114);
    }
    
    else if ( level == 8 ) {
      maze = new MazeEllers(width, height-114);
    }
    
    else {
      maze = new MazePrim(width, height-114, level);
    }
    
    chosen = true;
  }
  
  else {
    
    if ( !maze.generated() ) { //run while maze is generating
      maze.generate(); //further generate
      if ( maze.generated() ) { //if done generating
        maze.makeExit(); //add a lil exit
        
        time = millis(); //start timer for character
      }
    }

    
    else {
      //background(0);
      maze.displayMaze();
      
      loadPixels();
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          int dist = (int) Math.sqrt(((dude.getX()-j)*(dude.getX()-j))+((dude.getY()-i)*(dude.getY()-i)));
          pixels[i*width + j] = color(red(pixels[i*width + j])/(dist*dist/350), 
                                      blue(pixels[i*width + j])/(dist*dist/350),
                                      green(pixels[i*width + j])/(dist*dist/350));
        }
      }
      updatePixels();
      
      drawClock();
      dude.printChar();
      textSize(16);
      text("TIME:", 50, 405); 
      text("LIVES:", 200, 405);
      textSize(25); 
      text(liveStr, 260, 407);
      textSize(30); 
      if (level == 1) { 
        text("DEPTH-FIRST SEARCH", 10, 360);
      } 
      else if (level == 8) { 
        text("ELLER'S ALGORITHM", 20, 360);
      } 
      else if (level == 5) { 
        text("PRIM'S ALGORITHM", 30, 360);
      } 
      else {
        text("TREE GROWING ALGO", 10, 360);
      }
      fill(0);
      //System.out.println( (dude.getX() - 8) + " , " + (dude.getY() - 8) );
      //System.out.println( (maze.getExit().getX()) + " , " + (maze.getExit().getY()) );
      
      if ( (dude.getY() - 8) == maze.getExit().getY()  && (dude.getX() - 8) == maze.getExit().getX() ) {
        clear();
        chosen = false;
        level += 1;
        dude.reset();
        resetClock();
        levelsPassed += 1;
      }
      
      else if ( millis() - time >= wait ) { //if run out of time ( currently 30 seconds )
        clear(); 
        dude.die(); //dude dies
        liveStr = "" + dude.getLives(); 
        maze.displayMaze();
        drawClock();
        dude.printChar();
        textSize(16);
        text("TIME:", 50, 405); 
        text("LIVES:", 200, 405);
        textSize(25); 
        text(liveStr, 260, 407);
        fill(0);
        time = millis(); //restart timer
        resetClock();
      }
    }
  }
}

/*
void keyPressed() { //PAUSES GENERATION
  final int k = keyCode;
  if (k == 'S')
    if (looping)  noLoop();
    else          loop();
}
*/

  void keyPressed() { 
    if (key == CODED) { 
       if (keyCode == UP) { 
         dude.validDirection(0, maze.getMaze());
       } 
       else if (keyCode == DOWN) { 
         dude.validDirection(1, maze.getMaze());
       }
       else if (keyCode == LEFT) { 
         dude.validDirection(2, maze.getMaze()); 
       }
       else if (keyCode == RIGHT) { 
         dude.validDirection(3, maze.getMaze()); 
       } 
    }
    else {
      if (key == 'w') { 
         dude.validDirection(0, maze.getMaze());
       } 
       else if (key == 's') { 
         dude.validDirection(1, maze.getMaze());
       }
       else if (key == 'a') { 
         dude.validDirection(2, maze.getMaze()); 
       }
       else if (key == 'd') { 
         dude.validDirection(3, maze.getMaze()); 
       } 
    }
  }
  
  void drawClock() {
    stroke(256, 256, 256);
    fill(0);
    ellipse( clockCenterX, clockCenterY, 32, 32 );
    
    stroke(256, 256, 0);
    line( clockCenterX, clockCenterY, clockCenterX, clockCenterY - radius );
    
    stroke(256, 256, 256);
    line( clockCenterX, clockCenterY, clockCenterX + (radius * cos(timeAngle)), clockCenterY + (radius * sin(timeAngle)) );
    timeAngle += angleIncrement;
  }
  
  void resetClock() {
    timeAngle = 3 * PI / 2;
  }
    