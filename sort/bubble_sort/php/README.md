<h1>Bubble Sort</h1>

<h3>Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.</h3>
Example: <br>
First Pass:  <br>
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.  <br>
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4  <br>
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2  <br>
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them. <br>
Second Pass:  <br>
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )  <br>
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2  <br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  <br>
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )  <br>
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted. <br>
Third Pass:  <br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  <br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  <br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  <br>
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  <br>
<br>
<br>

Steps for bubble sort in PHP <br>
PHP program for implementation <br>
of Bubble Sort <br>
1. Traverse through all array elements <br>
2. Last i elements are already in place
3. traverse the array from 0 to n-i-1
4. Swap if the element found is greater
5. than the next element
6. Driver code

![image](https://user-images.githubusercontent.com/91491296/135582786-8cc428e9-d0ab-4e14-9b69-cab5066678a8.png)

<br>

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.<br>
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.<br>
Auxiliary Space: O(1)<br>
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.<br>
Sorting In Place: Yes<br>
Stable: Yes<br>
