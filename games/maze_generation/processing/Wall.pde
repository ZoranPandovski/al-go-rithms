class wall extends cell {
  
  wall(int xpos, int ypos) {
    x = xpos;
    y = ypos;
    c = color(0, 0, 0);
    unvisited = false;
    fill(c);
    noStroke();
    rect(x, y, 16, 16);
  }
  color getColor() {
    return c;
  }
}