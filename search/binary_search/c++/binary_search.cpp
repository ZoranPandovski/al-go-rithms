//saru95, cruxiu :)
#include <iostream> /* cout and cin */
#include <chrono> /* steady_clock::now */

bool binarySearchIterative(int list[], int first, int end, int item)
{

	int middle;

	while(first <= end)
	{
	     middle = (first + end)/2;
	     if(list[middle] == item)
	        {
			return true;
		}
		if(list[middle] < item)
		{
			first = middle + 1;
		} else
		{
			end = middle - 1;
		}
	}
	return false;
}

bool binarySearchRecursive(int list[], int first, int end, int item)
{

	int middle = (first + end)/2;

	if(list[middle] == item)
	{
		return true;
	}
	if(first >= end)
	{
		return false;
	}
	if(list[middle] < item)
	{
		return binarySearchRecursive(list, middle+1, end, item);
	} else
	{
		return binarySearchRecursive(list, first, middle-1, item);
	}

}

int main(int argc, char const *argv[])
{
  std::cout << "Please, enter the size of the list." << std::endl;
  int size, value, option;
  bool find;
  std::cin >> size;
  int *list = new int[size];
  for(int i = 0; i < size; i++)
  {
    std::cout << "Enter the element " << i << " of the list." << std::endl;
    std::cin >> list[i];
  }
  std::cout << "Now, enter a value to be searched in the list." << std::endl;
  std::cin >> value;
  std::cout << "Now, would you like to use a binary search iterative (0) or a binary search recursive(1)." << std::endl;
  std::cin >> option;
  switch (option) {
    case 0:
      {
        auto start = std::chrono::steady_clock::now();
        find = binarySearchIterative(list, 0, size-1, value);
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        if(find)
        {
          std::cout << "You find the element using the binary search iterative." << std::endl;
        }
        else{
          std::cout << "You not find the element using the binary search iterative." << std::endl;
        }
        std::cout << "And the time of search was " << std::chrono::duration <double, std::milli> (diff).count() << " ms." << std::endl;
      }
      break;
    case 1:
      {
        auto start = std::chrono::steady_clock::now();
        find = binarySearchRecursive(list, 0, size-1, value);
        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        if(find)
        {
          std::cout << "You find the element using the binary search recursive." << std::endl;
        }
        else
	{
          std::cout << "You not find the element using the binary search recursive." << std::endl;
        }
        std::cout << "And the time of search was " << std::chrono::duration <double, std::milli> (diff).count() << " ms." << std::endl;
      }
      break;
    default:
      std::cout << "This isn't a valid option, please restart the program." << std::endl;
      break;
  }
  delete[] list;
	return 0;
}
