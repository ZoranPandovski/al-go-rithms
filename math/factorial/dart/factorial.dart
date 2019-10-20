void main() {
  print('!1 = ${factorial(1)}');
  print('!2 = ${factorial(2)}');
  print('!3 = ${factorial(3)}');
  print('!4 = ${factorial(4)}');
  print('!5 = ${factorial(5)}');
  print('!6 = ${factorial(6)}');
  print('!7 = ${factorial(7)}');
}

int factorial (int n) => n > 1 ? n * factorial(n-1) : 1;