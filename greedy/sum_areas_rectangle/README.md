Given an array, task is to compute the sum of all possible maximum area rectangle which can be formed from the array elements. 
Also, you can reduce the elements of the array by at most 1.


Naive Approach : Check for all possible four elements of the array and then whichever can form a rectangle. 
In these rectangles, separate all those rectangles which are of maximum area formed by these elements.
After getting the rectangles and their areas, sum them all to get our desired solution.



Efficient Approach : To get the maximum area rectangle, first sort the elements of the array in non-increasing array.
After sorting, start the procedure to select the elements of the array.
Here, selection of two elements of array (as length of rectangle) is possible if elements of array are equal (a[i] == a[i+1]) or
if length of smaller element a[i+1] is one less than a[i] (in this case we have our length a[i+1] because a[i] is decreased by 1).
One flag variable is maintained to check that whether we get length and breadth both. 
After getting length, set the flag variable, now calculate the breadth in the same way as we have done for length and sum the area of rectangle. 
After getting length and breadth both, again set the flag variable false so that we will now search for a new rectangle. 
This process is repeated and lastly, final sum of area is returned.
