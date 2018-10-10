class cell {  
  protected color c;
  protected boolean unvisited;
  protected int x;
  protected int y;
  boolean dropped;
  
  cell() {
    
  }
  
  cell( int xpos, int ypos ) {
    x = xpos;
    y = ypos;
    unvisited = true;
    c = color(0, 0, 0);
    fill(c);
    noStroke();
    rect(x, y, 16, 16);
  }
  
  cell( int xpos, int ypos, boolean v ) {
    x = xpos;
    y = ypos;
    unvisited = v;
    c = color(0, 0, 256);
    fill(c);
    noStroke();
    rect(x, y, 16, 16);
  }
  
    cell( int xpos, int ypos, boolean v, int greenType ) {
    x = xpos;
    y = ypos;
    unvisited = v;
    dropped = false;
    c = color(0, greenType, 0);
    fill(c);
    noStroke();
    rect(x, y, 16, 16);
  }
  
  boolean equals2 ( cell a) {
    return (x == a.getX()) && (y == a.getY());
  }
  
  protected color getColor() { 
    return c;   
  }
  
  private void setColor(color col) {
    c = col;
    displayCell();
  }
  
  protected int getX() {
    return x;
  }
  
  protected int getY() {
    return y;
  }

  private void visit() {
    unvisited = false;
    setColor(color(0,0,256));
  }
 

  private void backTrack() {
    setColor( color(0,256,0) );
  }
  
  protected boolean unvisited() {
    return unvisited;
  }
  
  public boolean equals(cell c) { 
    boolean bool1 = red(c.getColor()) == red(getColor()); 
    boolean bool2 = green(c.getColor()) == green(getColor()); 
    boolean bool3 = blue(c.getColor()) == blue(getColor()); 
    return bool1 && bool2 && bool3; 
  } 
  
  public cell maxGreen(cell c) { 
    if (green(c.getColor()) > green(getColor())) { 
      return c; 
    } 
    else { 
      return this; 
    } 
  } 
  
  public cell minGreen(cell c) { 
    if (green(c.getColor()) < green(getColor())) { 
      return c; 
    } 
    else { 
      return this; 
    } 
  } 
  
  protected void displayCell() {
    fill(c);
    noStroke();
    rect(x, y, 16, 16);
  }
  
  void drop() {
    dropped = true;
  }
  
  void undrop() {
    dropped = false;
  }
  
  boolean dropped() {
    return dropped;
  }
  
}