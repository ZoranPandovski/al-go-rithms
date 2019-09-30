void main() {
  List<int> sequence = getFibonacciSequence(20);

  for (int i = 0; i < sequence.length; i++) {
    print(sequence[i]);
  }
}

List<int> getFibonacciSequence(int n) {
  List<int> sequence = new List<int>();

  for (int i = 0; i <= n; i++) {
    sequence.add(getNextNumber(i));
  }

  return sequence;
}

int getNextNumber(int n) => n <= 2 ? 1 : getNextNumber(n - 1) + getNextNumber(n - 2);
