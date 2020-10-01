## Moore's Voting Algorithm

## Step 1
The algorithm for the first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is that if each occurrence of an element e can be cancelled with all the other elements that are different from e then e will exist till end if it is a majority element.

## Step 2
Traverse through the array and check if the count of the element found is greater than half the size of the array, then print the answer else print “No majority element”.

## Algorithm
* Loop through each element and maintains a count of majority element, and a majority index, maj_index
* If the next element is same then increment the count if the next element is not same then decrement the count.
* if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
* Now again traverse through the array and find the count of majority element found.
* If the count is greater than half the size of the array, print the element
* Else print that there is no majority element
