#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Bubble Sort: Implemmentation by Mario Hirotoshi

void swapValues(int & number1, int & number2){
  int temporary;

  temporary = number1;
  number1   = number2;
  number2   = temporary;

  return;
}

int binarySearch(int array[], int query, int lenght){
  int left = 0;
  int right = lenght - 1;
  int medium;

  while(left <= right){
    medium = (left + right)/2;
    if(array[medium] < query)
      left++;
    else if(array[medium] > query)
      right--;
    else
      return medium;
  }

  return -1;
}

void bubbleSort(int array[], int lenght){
  int counter1, counter2;

  for(counter1 = 0; counter1 < lenght - 1; counter1++){
    for(counter2 = counter1 + 1; counter2 < lenght; counter2++){
      if(array[counter1] > array[counter2])
        swapValues(array[counter1], array[counter2]);
    }
  }

  return;
}

int main(){
  srand(time(0));
  cout.setf(ios::fixed);
  cout.precision(5);

  int lenght;
  cout<<"Type the lenght of the array: "<<endl;
  cin>>lenght;

  int array[lenght];
  int newNumber;

  cout<<"The original array before the bubble sort: "<<endl;
  for(int counter = 0; counter < lenght; counter++){
    newNumber = (rand() % 1000) + 1;
    if(binarySearch(array, newNumber, lenght) == -1){
      array[counter] = newNumber;
      cout<<"["<<(counter + 1)<<"]: "<<newNumber<<" ";
    }
    else
      counter--;
  }

  //Measuring the sorting time
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  bubbleSort(array, lenght);

  std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

  cout<<endl<<"Now, the array after the bubble sort: "<<endl;
  for(int counter = 0; counter < lenght; counter++){
    cout<<"["<<(counter + 1)<<"]: "<<array[counter]<<" ";
  }

  cout << endl << "Bubble sort execution time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl<<"ms ";

  return 0;
}
