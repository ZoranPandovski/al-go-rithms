#include<iostream>
#include<string>

using namespace std;
char Greatest_digit_in_number(string number);
int main(){
   string number;
   cin>>number;
   cout<<"The Greatest digit in this number is: "<<Greatest_digit_in_number(number)<<endl;
return 0;
}

char Greatest_digit_in_number(string number){
   int i =0;
   char greatest_digit = '0';
   for (char digit : number){
      if(digit > greatest_digit)
         greatest_digit = digit;
   }
   return greatest_digit;      
}
