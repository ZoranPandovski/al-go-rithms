import 'dart:math';

void main() {
  isArmstrongNumber(371);
  isArmstrongNumber(810);
  isArmstrongNumber(1634);
  isArmstrongNumber(2020);
}

void isArmstrongNumber(int number) {
  int sum = 0, digits = 0;

  for (int i = number; i != 0; i ~/= 10) digits++;
  for (int i = number; i != 0; i ~/= 10) {
    sum += pow(i % 10, digits);
  }

  if (sum == number)
    print("${number} is a armstrong number.");
  else
    print("${number} is not a armstrong number.");
}
