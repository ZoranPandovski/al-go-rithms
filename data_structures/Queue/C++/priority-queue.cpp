#include <iostream.h>

#include <bits/stdc++.h>

using namespace std;

// Structure for the elements in the
// priority queue
struct item {
  int value;
  int priority;
};

// Store the element of a priority queue
item pr[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority) {
  // Increase the size
  size++;

  // Insert the element
  pr[size].value = value;
  pr[size].priority = priority;
}

// Function to check the top element
int peek() {
  int highestPriority = INT_MIN;
  int ind = -1;

  // Check for the element with
  // highest priority
  for (int i = 0; i <= size; i++) {

    // If priority is same choose
    // the element with the
    // highest value
    if (highestPriority ==
      pr[i].priority &&
      ind > -1 &&
      pr[ind].value >
      pr[i].value) {
      highestPriority = pr[i].priority;
      ind = i;
    } else if (highestPriority <
      pr[i].priority) {
      highestPriority = pr[i].priority;
      ind = i;
    }
  }

  // Return position of the element
  return ind;
}

// Function to remove the element with
// the highest priority
void dequeue() {
  // Find the position of the element
  // with highest priority
  int ind = peek();

  // Shift the element one index before
  // from the position of the element
  // with highest priortity is found
  for (int i = ind; i < size; i++) {
    pr[i] = pr[i + 1];
  }

  // Decrease the size of the
  // priority queue by one
  size--;
}


int main() {
  // Function Call to insert elements
  // as per the priority
  int val, priority, opt, num;
  printf("\n\n1 for Insert the Data in Queue\n2  for Delete the data from the Queue\n3 for peek \n0 for Exit \n");
  do {
    cin >> opt;
    switch (opt) {
    case 1:
      cout << "Enter number of elements to insert";
      cin >> num;
      for (int i = 0; i < num; i++) {
        cin >> val >> priority;
        enqueue(val, priority);
      }

      break;

    case 2:
      // Dequeue the top element
      dequeue();
      break;
    case 3:
      // Stores the top element
      // at the moment
      int ind = peek();

      cout << pr[ind].value << endl;

    case 0:
      break;
    default:
      printf("\nIncorrect Choice");

    }
  } while (opt != 0);

  return 0;
}
