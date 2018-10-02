
#include<bits/stdc++.h>
using namespace std;

///////Quicksort 3 Partition with median pivot//////////////////

//for storing partition locations
struct twopoint
{
  int left;
  int right;
};

//for finding median of first,last and middle element to select pivot
int medianlocation(vector<int> &vec,int a,int b,int c)
{
  if(vec[a]<=vec[b])
  {
    if(vec[b]<=vec[c])
      return b;
    if(vec[a]<=vec[c])
      return c;
    return a;
  }
  if(vec[c]<=vec[b])
    return b;
  if(vec[a]<=vec[c])
    return a;
  return c;
}

//Partitions the vector into 3 parts. Lesser part, Equal part and Greater part
//Returns 2 points, the 2 location of partitions, between which single equal element is embedded 
//and no further operation is needed inbetween them 

twopoint Partition(vector<int> &vec,int low,int high)
{
int pivotlocation = medianlocation(vec,low,high,low+(high-low)/2);
int pivot=vec[pivotlocation];
twopoint j;
j.left=pivotlocation;
j.right=pivotlocation;

for(int i=low;i<j.left;i++)
{
  if(vec[i]>=pivot)
  {
    swap(vec[i],vec[pivotlocation]);
    j.left=i;
    j.right=i;
    pivotlocation=i;
  }
}
for(int i=j.right+1;i<=high;i++)
{
  if(vec[i]==pivot)
  {
    j.right++;
    swap(vec[i],vec[j.right]);
  }
  if(vec[i]<pivot)
  {
    swap(vec[j.left],vec[i]);
    j.left++;
    i--;
  }
}

return j;
}

//main quicksort function

void QuickSort(vector<int> &vect,int left,int right)
{
  if(left>=right)
    return;
  twopoint part = Partition(vect,left,right);
  QuickSort(vect,left,part.left-1);
  QuickSort(vect,part.right+1,right);

}


//main test function
int main() {


int n;
cout << "Enter size \n";
cin >> n;

vector<int> vec(n);

cout << "Enter elements of vector\n";
for(int i=0;i<n;i++)
{
  cin >> vec[i];
}

QuickSort(vec,0,n-1);


cout << "Sorted elements are\n";
for(int i=0;i<n;i++)
{
  cout <<  vec[i] << " ";
}
    
    return 0;
}
