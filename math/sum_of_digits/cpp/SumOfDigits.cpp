#include <iostream>

using namespace std;

int sumOfDigits(int i){
    int res = 0 ;
    while(i != 0){
            res += i%10;
            i /= 10 ;
    }
    return res ;
}


int main()
{
    cout << sumOfDigits(25114) ;
    return 0;
}
