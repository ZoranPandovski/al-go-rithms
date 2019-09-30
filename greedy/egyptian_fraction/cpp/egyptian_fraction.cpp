/*
Greedy Algorithm for Egyptian Fraction
Every positive fraction can be represented as sum of unique unit fractions. 
A fraction is unit fraction if numerator is 1 and denominator is a positive 
integer, for example 1/3 is a unit fraction. Such a representation is called 
Egyptian Fraction as it was used by ancient Egyptians.

Following are few examples:

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void egyptian(int nr, int dr, vector<pair<int,int> >& res){
  if(dr == 0 || nr == 0){
    return;
  }

  if(dr%nr == 0){
    res.push_back(pair<int,int>(1, dr/nr));
    return;
  }


  if(nr%dr == 0){
    res.push_back(pair<int,int>(dr/nr, 1));
  }
  //ceil
  if(nr > dr){
    res.push_back(pair<int,int>(nr/dr, 1));
    egyptian(nr%dr, dr, res);
  }
  
  int c = dr/nr + 1;
  res.push_back(pair<int,int>(1, c));

  egyptian(nr*c - dr*1, dr*c, res); 
}

void printVecPair(vector<pair<int,int> > res){
  for(int i=0; i<res.size(); i++){
    cout << res[i].first << "/" << res[i].second << endl;
  }
}

int main(int argc, char const *argv[])
{
  vector<pair<int,int> > res;
  int nr = 12, dr = 13;
  egyptian(nr, dr, res);

  printVecPair(res);
  return 0;
}