//a Latin square is an n × n array filled with n different symbols,
//each occurring exactly once in each row and exactly once in each column

#include <iostream>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

bool check_rows();
bool check_cols();

int main()
{
  int numToAdd = 0;
  int row; //row to change from user input
  int col; //column to change from user input
  string hold = "";
  int size;

  //get difficulty (n for how large the square is)
  while (size >= 2)
  {
    cout << "Welcome to Latin Squares!  How big do you want the square?" << endl;
    cin >> hold;
    stringstream conv(hold);
    conv >> size;
  }
  const int SQUARE_SIZE = size;
  int square[SQUARE_SIZE][SQUARE_SIZE];

  for (int c = 0; c < SQUARE_SIZE; c++)
  {
    for (int r = 0; r < SQUARE_SIZE; r++)
    {
      square[r][c] = 0;
    }
  }

  while (!check_rows() || !check_cols())
  {
    for (int c = 0; c < SQUARE_SIZE; c++)
    {
      for (int r = 0; r < SQUARE_SIZE; r++)
      {
        cout << square[r][c] << "\t";
      }
      cout << endl;
    }

    while (numToAdd > 0 && numToAdd <= SQUARE_SIZE) //make sure the input is within range
    {
    cout << "Enter a number to add to the square:" << endl;
    cin >> hold;
    stringstream conv(hold);
    conv >> numToAdd;
    }

    while (row > 0 && row <= SQUARE_SIZE)
    {
      cout << "Enter the row you want to put it in (first row is 1, second is 2, etc)" << endl;
      cin >> hold;
      stringstream conv(hold);
      conv >>  row;
    }

    while (col > 0 && col <= SQUARE_SIZE)
    {
      cout << "Enter the column you want to put it in (first column is 1, second is 2, etc)" << endl;
      cin >> hold;
      stringstream conv(hold);
      conv >>  col;
    }

    square[row][col] = numToAdd;
  }

  cout << "Congrats!  You've solved the square!" << endl;
  return 0;
}

bool check_rows()
{
  bool allGood = false;

  return allGood;
}

bool check_cols()
{
  bool allGood = false;
  //to be implemented
  return allGood;
}
