void main() {
  isStrongNumber(145);
  isStrongNumber(0);
  isStrongNumber(40585);
  isStrongNumber(2020);
}

void isStrongNumber(int number) {
  int sum = 0;

  if (number == 0) sum = 1;

  for (int i = number; i != 0; i ~/= 10) {
    sum += factorial(i % 10);
  }

  if (sum == number)
    print("${number} is a strong number.");
  else
    print("${number} is not a strong number.");
}

int factorial(int num) {
  if (num <= 1) return 1;

  return num * factorial(num - 1);
}
