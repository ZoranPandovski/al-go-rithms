/// Insertion Sort the input list
void insertionSort(List<int> items) {
  // Iterate through the array, knowing i-and-left is sorted and bubbling
  // to-the-right-of-i elements left until they reach the correct position
  for (int i = 0; i < items.length - 1; i++) {
    // Vars for the left and right comparators
    int l = i;
    int r = l + 1;

    while (l >= 0) {
      r = l + 1;
      if (items[l] > items[r]) {
        // Swap items
        final int higherNumber = items[l];
        items[l] = items[r];
        items[r] = higherNumber;
      }
      l--;
    }
  }
}

// ----- Test -----
void main() {
  // 1. Arrange
  final List<int> testedList = [10, 2, 8, 5, 6, 1, 4, 7, 9, 3];
  final List<int> expectedOutput = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  // 2. Act
  insertionSort(testedList);
  print(testedList);

  // 3. Assert
  // No simple list equality in dart yet so using 'fold' to recursively check
  // each sorted element compared to the expected output at each index.
  int i = 0;
  final bool isEqual = testedList.fold(
    true,
    (result, item) => result && item == expectedOutput[i++],
  );
  print(isEqual);
}
