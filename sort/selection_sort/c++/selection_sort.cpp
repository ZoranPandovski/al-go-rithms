// cruxiu :)
#include <iostream> /* cout and cin */
#include <chrono> /* steady_clock::now */

void printList(int *list, int size) {
	for (int i = 0; i < size; i++){
    std::cout << "The element " << i << " is " << list[i] << "." << std::endl;
	}
}

void selectionSort(int *list, int size) {
	int smaller, aux;
	for(int i = 0; i < (size - 1); i++) {
		smaller = i;
		for(int j = (i + 1); j < size; j++) {
			if(list[j] < list[smaller]) {
				smaller = j;
			}
		}
		if(i != smaller) {
			aux = list[i];
			list[i] = list[smaller];
			list[smaller] = aux;
		}
	}
}

int main(int argc, char const *argv[]){
  std::cout << "Please, enter the size of the list." << std::endl;
  int size, value, option;
  bool find;
  std::cin >> size;
  int *list = new int[size];
  for(int i = 0; i < size; i++){
    std::cout << "Enter the element " << i << " of the list." << std::endl;
    std::cin >> list[i];
  }
  std::cout << "Now, we will sort the list. Your list now is:" << std::endl;
  printList(list, size);
  auto start = std::chrono::steady_clock::now();
  selectionSort(list, size);
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << "After sort, your list now is:" << std::endl;
  printList(list, size);
  std::cout << "And the time for sort was " << std::chrono::duration <double, std::milli> (diff).count() << " ms." << std::endl;
  delete[] list;
	return 0;
}
