#include<iostream>
#include <vector>
#include<stack>
using namespace std;
int main(){
    vector<int>number;
    int n,q;
    cin>>n>>q;
    while(n--){
        int num;
        cin>>num;
        number.push_back(num);
    }
    int m=number.size();
    int max=10001;
    int a[max];
    for(int i=0;i<max;i++){
        a[i]=1;
    }
    a[0]=0,a[1]=0;
    for(int i=2;(i*i)<=max;i++){
        if(a[i]==1){
            for(int j=2;(j*i)<=max;j++)
                a[i*j]=0;
        }
    }
    int j=0;
    int counter=0;
    int b[1240];
    for(int i=0;i<=max;i++){
        if(a[i]==1){
            b[j]=i;
            j++;
            counter++;
        }
    }
    /*
     * Write your code here.
     */
    stack<int>s;
    int i=1;
    int l;
    while(i<=q){
        int prime=b[i-1];
        int m=number.size();
        l=m-1;
        int count=0;
        while(count<m){
            ///check if it is divided by qth prime
            int num=number[l];
            if((num%prime)==0){
                s.push((number[l]));
                number.erase(number.begin()+l);
                l--;
                count++;
            }
            else{
                number.insert(number.begin(),number[l]);
                number.erase(number.begin()+l+1);
                count++;
            }
        }
        i++;
    }
    //stack ko reverse kar do
    stack<int> s2;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    int k=number.size()-1;
    for(int i=0;i<=k;i++){
        cout<<number[i]<<" ";
    }

    return 0;
}
