/// Bubble Sort the input list then return it.
List<int> bubbleSort(List<int> items) {
  bool isSorted = false;

  while (!isSorted) {
    // We know the list isn't sorted whenever we have to do a swap.
    isSorted = true;

    for (var i = 0; i < items.length - 1; i++) {
      if (items[i] > items[i + 1]) {
        isSorted = false;
        final int higherElementCopy = items[i];
        items[i] = items[i + 1];
        items[i + 1] = higherElementCopy;
      }
    }
  }

  return items;
}

// ----- Test -----
void main() {
  // 1. Arrange
  final List<int> unsortedInput = [10, 2, 8, 5, 6, 1, 4, 7, 9, 3];
  final List<int> expectedOutput = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  // 2. Act
  final List<int> sortedOutput = bubbleSort(unsortedInput);
  print(sortedOutput);

  // 3. Assert
  // No simple list equality in dart yet so using 'fold' to recursively check
  // each sorted element compared to the expected output at each index.
  int i = 0;
  final bool isEqual = sortedOutput.fold(
    true,
    (result, item) => result && item == expectedOutput[i++],
  );
  print(isEqual);
}