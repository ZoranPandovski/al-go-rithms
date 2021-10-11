class character { 
  
  color c; 
  int lives; 
  int xpos;
  int ypos; 
  int xperm;  
  int yperm; 
  int arrx;
  int arry;
  
  character() { 
    lives = 3;
    xpos = 40;
    ypos = 40;
    xperm = 40;
    yperm = 40;
    arrx = 2;
    arry = 2;
    c = color(256, 0, 256); // Uses RGB Input for a new color 
  } 
  
  void printChar() {
    noStroke();
    fill(c);
    ellipse(xpos, ypos, 10, 10);
  }
  
  void up() {
    ypos -= 16;
    arry -= 1;
  }
  
  void down() {
    ypos += 16;
    arry += 1;
  }
  
  void left() {
    xpos -= 16;
    arrx -= 1;
  }
  
  void right() {
    xpos += 16;
    arrx += 1;
  }
  
  void validDirection(int i, cell[][] maze) {
    if (i == 0 && maze[arry-1][arrx].getColor() != color(0,0,0) ) {
      //System.out.println("up");
      up();
    }
    
    else if (i == 1 && maze[arry+1][arrx].getColor() != color(0,0,0) ) {
      //System.out.println("down");
      down();
    }
    
    if (i == 2 && maze[arry][arrx-1].getColor() != color(0,0,0) ) {
      //System.out.println("left");
      left();
    }
    
    if (i == 3 && maze[arry][arrx+1].getColor() != color(0,0,0) ) {
      //System.out.println("right");
      right();
    }
    //System.out.println(arry + "," + arrx);
  }
  
  int getArrX() {
    return arrx;
  }
  
  int getArrY() {
    return arry;
  }
  
  int getX() {
    return xpos;
  }
  
  int getY() {
    return ypos;
  }
  
  int getLives() {
    return lives;
  }
  
  void reset() {
    xpos = xperm;
    ypos = yperm;
    arrx = 2;
    arry = 2;
  }
  
 void die() {
   lives -= 1;
   reset();
 }
      
}