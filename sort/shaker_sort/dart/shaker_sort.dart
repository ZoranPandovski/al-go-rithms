void main() {
  // define a list to be sorted
  final List<int> unsortedList = [10, 2, 8, 5, 6, 1, 4, 7, 9, 3];

  // define expected result
  final List<int> expectedList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  // call the method and save sorted list
  final List<int> sortedList = shakerSort(unsortedList);

  // test the resolution
  bool condition1 = sortedList.toSet().difference(expectedList.toSet()).isEmpty;
  bool condition2 = sortedList.length == expectedList.length;
  if (condition1 && condition2) {
    print('Successfully sorted the list!');
  }

  // print the sorted list
  print(sortedList);
}

// define a method that takes the list to sort as input
List<int> shakerSort(List<int> list) {
  // the number of steps in the algorithm is only half the length of the input list
  for (int i = 0; i < list.length / 2; i++) {
    // first we go through every element in the list starting from the left
    for (int j = 0; j < list.length - 1; j++) {
      // if the next element is smaller than the current element, we need to swap them
      if (list[j] > list[j + 1]) {
        int temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }

    // now each element of the list is run through again from right to left
    for (int j = list.length - 1; j > 0; j--) {
      // if the next element is bigger than the current element, we need to swap them
      if (list[j] < list[j - 1]) {
        int temp = list[j];
        list[j] = list[j - 1];
        list[j - 1] = temp;
      }
    }
  }

  return list;
}
