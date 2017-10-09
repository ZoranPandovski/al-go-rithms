#include <iostream>
#include <vector>
using std::vector;

class knightsTour{
  vector< vector<int> > board;
  int sizeX;
  int sizeY;
  bool complete;
  unsigned long long numMoves;
public:
  knightsTour(const int& sizeX, const int& sizeY, const int& startX, const int& startY){
    for (size_t i = 0; i < sizeY; i++) {
      vector<int> v;
      for (size_t j = 0; j < sizeX; j++) {
        v.push_back(0);
      }
      board.push_back(v);
    }
    this->complete = false;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    traverse(startX, startY);
  }
  void traverse(const int& currentX, const int& currentY, const int& count=1);
  void printBoard();
};

void knightsTour::traverse(const int& currentX, const int& currentY, const int& count){
  // Base cases: stopping conditions for recursion

  // Already completed traversal for this instance from it's starting point
  if(complete) return;

  // Illegal positions (out of range)
  if((currentX<0)||(currentY<0)) return;
  if((currentX>=sizeX)||(currentY>=sizeY)) return;

  // This position has already been tried
  if(board[currentY][currentX]>0){
    return;
  }
  else{
    // Set board to this count
    board[currentY][currentX]=count;
    numMoves++;

    // If count is the square of the size, this is the last square nessesary
    // to complete the knight's tour so complete is set to true
    if (count==(sizeX*sizeY)) {
      complete=true;
      return;
    }

    // If not completed, try all possible moves for the knight
    // (any of the 8 possible L moves) with the next count
    int c=count+1;
    traverse(currentX+2,currentY+1,c);
    traverse(currentX+2,currentY-1,c);
    traverse(currentX+1,currentY-2,c);
    traverse(currentX-1,currentY-2,c);
    traverse(currentX-2,currentY-1,c);
    traverse(currentX-2,currentY+1,c);
    traverse(currentX-1,currentY+2,c);
    traverse(currentX+1,currentY+2,c);

    // The above code explores to the full depth of each option from this point.
    // If all possible moves are explored and none have lead to a completed tour
    // then this is not the correct move from its parent state so go back up
    // and try a different move.
    if(!complete){
      board[currentY][currentX]=0;
      if (count==1){
        std::cout << "Tour of "<< sizeX << " by " << sizeY;
        std::cout <<" not found through any combination.\nNot possible to have a knights tour from this start position"<< std::endl;
      }
      return;
    }

    // If it is complete and it has reached up to the first state then print
    // out the board with the ordering filled in.
    if((complete)&&(count==1)){
      printBoard();
      std::cout << "Tour of "<< sizeX << " by " << sizeY;
      std::cout <<" board complete in "<< numMoves <<" moves!"<< std::endl;
    }
  }
}

void knightsTour::printBoard(){
  for (size_t i = 0; i < sizeY; i++) {
    for (size_t j = 0; j < sizeX; j++) {
      std::cout<<board[i][j]<<"\t";
    }
    std::cout<<"\n";
  }
}

int main(){
  int sizeX = 5;
  int sizeY = 5;
  int startX = 2;
  int startY = 2;
  knightsTour k(sizeX, sizeY, startX, startY);
  return 0;
}
