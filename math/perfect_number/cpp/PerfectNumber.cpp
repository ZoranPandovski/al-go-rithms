#include<iostream>

using namespace std;
bool is_a_perfect_number(int number);
int main(){
   unsigned int number; 
   cout<<"enter a number"<<endl;
   cin >> number;

  if( is_a_perfect_number(number))
      cout<<"It is a perfect number"<<endl;
   else
      cout<<"It's not a perfect number"<<endl;

   return 0;
}

bool is_a_perfect_number(int number){
   int sum_dividers=0;
   for(int i = 1; i<number; i++){
      if(number % i==0)
         sum_dividers+=i;
   }
   if(number == sum_dividers)
      return true;
   else return false;
}