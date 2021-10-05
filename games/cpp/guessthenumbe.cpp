#include<iostream>
#include<cmath>
using namespace std;

int randomgen(){
    srand((unsigned) time(0));
    int r = rand()%100+1;
    return r;
}

float approx(int guess, int r){
    float close = fabsf(r - guess) / 10;
    return close;
}


void start(){
    int level = 1;
    int ran = randomgen();
    //cout<<ran<<"\n";  //To print out random when developing
    while(level <= 10){
        int guess;
        cout<<"\nEnter Your guess no. "<<level<<"\n";
        cin>>guess;
        if(guess==ran){
            cout<<"Congratulations You have won, it was exactly "<<ran<<endl;
            level = 10;
        }
    cout<<"You are  [ "<<approx(guess,ran)<<"/10 ]  scales away from the Number\n";
        level++;
    }
}

int main(){
    cout<<"Guess the Number";
    start();
    return 0;
}
