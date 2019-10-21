#include <stdio.h>

int sumOfDigits(int number){

int total=0;

  while(number>0){
      total=total+number%10;
      number=number/10;
  }
  return total;
}

int main(int argc, char const *argv[]) {

int result=sumOfDigits(987123);
printf("Sum of the digits are:%d \n",result);

return 0;
}
