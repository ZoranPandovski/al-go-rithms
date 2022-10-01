#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <math.h>
#include <map>
#include<set>
#include <forward_list>
using namespace std;
int findpeak(int a[],int low,int high){
  int mid=(low+high)/2;
  if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
      return mid;
  }
  else{
      if(a[mid-1]>a[mid]){
          high=mid-1;
          return findpeak(a,low,high);
      }
      else{
          low=mid+1;
          return findpeak(a,low,high);
      }
  }


}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<findpeak(a,0,n);
}