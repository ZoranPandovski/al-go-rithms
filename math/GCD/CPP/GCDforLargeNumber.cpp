#include<iostream>
#define MAX 250

using namespace std;

int mod(char*,int);

int findGCD(int a,char*b){
    int bInt = a;
    a = mod(b,a);
    while(a != 0){
        int temp = a;
        a = bInt%a;
        bInt = temp;
    }

    return bInt;
}

int mod(char* b,int a){

    int x=0;
    for(int i=0;b[i]!='\0';i++){
        x = ((x*10) + (b[i]-'0'))%a;
    }
    return x%a;
}


int main()
{
    int a;
    char b[MAX];	//large number cannot be stored in a normal data type like long long or int. 

        cin>>a;
        cin>>b;
        if(a==0){
            cout<<b<<endl;
        }
        else{
             cout<<findGCD(a,b)<<endl;
        }
       

}
