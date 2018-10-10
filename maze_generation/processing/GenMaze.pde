interface GenMaze {
  
 void generate();
 void displayMaze();
 boolean generated();
 void makeExit();
 cell[][] getMaze();
 cell getExit();
}