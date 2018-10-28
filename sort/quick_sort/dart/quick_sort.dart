/// Quick Sort the input list
void quickSort(List<int> items, int left, int right) {
  int i = left, j = right;

  // Choose middle as original pivot rather than ends to
  // avoid worst-case behavior on already-sorted lists
  int pivot = items[(left + right) ~/ 2];

  while (i <= j) {
    while (items[i] < pivot) {
      i++;
    }
    while (items[j] > pivot) {
      j--;
    }

    if (i <= j) {
      // Swap items i & j
      final int higherElementCopy = items[i];
      items[i] = items[j];
      items[j] = higherElementCopy;

      i++;
      j--;
    }
  }

  // Recursively sort left and right of pivot
  if (left < j) {
    quickSort(items, left, j);
  }
  if (i < right) {
    quickSort(items, i, right);
  }
}

// ----- Test -----
void main() {
  // 1. Arrange
  final List<int> testedList = [10, 2, 8, 5, 6, 1, 4, 7, 9, 3];
  final List<int> expectedOutput = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  // 2. Act
  quickSort(testedList, 0, testedList.length - 1);
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
