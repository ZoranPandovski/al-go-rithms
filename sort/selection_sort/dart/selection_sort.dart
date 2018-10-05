/// Selection Sort the input list
void selectionSort(List<int> items) {
  // Iterate through the array, knowing left-of-i is sorted and looking
  // for the lowest to-the-right element to place at the end of left
  for (int i = 0; i < items.length - 1; i++) {
    int lowestIndex = i;
    for (int j = i + 1; j < items.length; j++) {
      if (items[j] < items[lowestIndex]) {
        lowestIndex = j;
      }
    }

    // Swap the lowest item with this position (i)
    final int lowestNumber = items[lowestIndex];
    items[lowestIndex] = items[i];
    items[i] = lowestNumber;
  }
}
 // ----- Test -----
void main() {
  // 1. Arrange
  final List<int> testedList = [10, 2, 8, 5, 6, 1, 4, 7, 9, 3];
  final List<int> expectedOutput = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
   // 2. Act
  selectionSort(testedList);
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