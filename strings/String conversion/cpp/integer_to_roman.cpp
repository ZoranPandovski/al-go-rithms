#include <bits/std++.h>
using namespace std;

unordered_map<int, string> ump ={
    {1, "I"},
    {5, "V"},
    {10, "X"},
    {50, "L"},
    {100, "C"},
    {500, "D"},
    {1000, "M"}
};

string intToRoman(int num) {
    string res = "";
   int d = 1;
   while(num){
        int rem = num%10;

        if(rem == 4 || rem == 9){
            if(rem < 5){
                res += ump[5*d];
            }else{
                res += ump[10*d];
            }
            res += ump[d];
        }else{
            int temp = rem;
            if(rem >= 5) temp -= 5;

            while(temp--){
                res += ump[d];
            }

            if(rem >= 5) {
                res += ump[5*d];
            }
        }


        d *= 10;
        num /= 10;
    } 

    reverse(res.begin(), res.end());
    return res;
}

int main(){
  cout << intToRoman(58); // LVIII
}
