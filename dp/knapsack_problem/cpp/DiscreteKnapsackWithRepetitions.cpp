//Solves the Knapsack problem when a number of items(each infinite of its kind) each having some value are required to be selected
//It is solved by a 1D DP as it checks the maximum value attainable for each weight from 1 to Maxweight
//after it finds the maximum value attainable for that weight with each item everytime.
//weight is stored in vector weight, corresponding value is stored in vector value

#include<bits/stdc++.h>
using namespace std;

int DiscreteKnapsackWithRepetitions(const int Maxweight,const vector<int> weight,const vector<int> value,const int Numberofitems)
{

  vector<int> Maxvalue(Maxweight+1);

  Maxvalue[0]=0;

  for(int w=1;w<=Maxweight;w++)
  {
    Maxvalue[w]=0;

    for(int i=0;i<Numberofitems;i++)
    {
      if(weight[i]<=w)
      {
        Maxvalue[w]=max(Maxvalue[w],Maxvalue[w-weight[i]]+value[i]);
      }
    }

  }

  return Maxvalue[Maxweight];
}

int main()
{
int W,N;
cout << "Enter Max Weight\n";
cin >> W;
cout << "Enter number of items\n";
cin >> N;

vector<int> w(n),v(n);
cout << "Enter weight and value of each element in order\n";
for(int i=0;i<n;i++)
{
cin >> w[i] >> v[i];
}

cout << "Maximum total value attainable is\n";

cout << DiscreteKnapsackWithRepetitions(W,w,v,N);

return 0;
}
