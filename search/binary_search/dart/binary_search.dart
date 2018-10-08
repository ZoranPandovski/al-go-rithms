//entry point to call binarysearch recursively
int search(List<int> array, int elementIndex) {
  return binarySearch(array, 0, array.length - 1, elementIndex);
}

int binarySearch(List<int> array, int start, int end, int elementIndex) {
   if (start <= end)
        {
            int middle = (start + (end - start) / 2).round();

            if (array[middle] == elementIndex)
                return middle;

            if (array[middle] > elementIndex)
                return binarySearch(array, start, middle - 1, elementIndex);

            return binarySearch(array, middle + 1, end, elementIndex);
        }

        return -1;
}


//run it
void main() {
  print("Hello world");
  List<int> values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  print("Found the value @ index ${search(values, 3)}");
}