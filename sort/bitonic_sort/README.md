## Bitonic sort

Bitonic sort is a classic parallel algorithm for sorting. Even though bitonic sort does **O(nLog<sup>2</sup>n)** comparisons, the fact that we always compare elements in predefined sequence and the sequence of comparison doesn't depend on data make it suitable for parallel implementation.

To better understand bitonic sort we must first understand what is a Bitonic Sequence and how to make a given sequence Bitonic.

### Bitonic Sequence

A sequence is called Bitonic if it is first increasing, then decreasing. In other words, an array *arr[0...n-1]* is Bitonic if there exists an index i where 0 <= i <= n-1 such that:

**arr[0] <= arr[1] .. <= arr[i]   AND   arr[i] >= arr[i+1] .. >= arr[n-1]**

1. A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, a decreasing order sequence is considered Bitonic with the increasing part as empty.
2. A rotation of Bitonic sequence is also bitonic.

**How to form a Bitonic Sequence from a random input?**

We start by forming 4-element bitonic sequences from consecutive 2-element sequence. Consider 4 elements in sequence x<sub>0</sub> , x<sub>1</sub> , x<sub>2</sub> and x<sub>3</sub>. We sort x<sub>0</sub> and x<sub>1</sub> in ascending order and x<sub>2</sub> and x<sub>3</sub> in descending order. We then concatenate the two pairs to form a 4-element bitonic sequence.
Next,  we take two 4-element bitonic sequences, sorting one in ascending order, the other in descending order (using the Bitonic Sort which we will discuss below), and so on, until we obtain the Bitonic Sequence.

### Bitonic Sorting

To better understand how Bitonic Sorting works we're gonna see an example.
![Example](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bitonic3.png "A picture explaining Bitonic Sort, taken from geeksforgeeks.org")

The meaning of the arrows is explained in this picture.
![Arrows](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bit2.png "Arrows explanation.")

In the picture with the example above, we can see an array *arr[3,7,4,8,6,2,1,5]*.
1. The first two steps show the process of forming a Bitonic sequence as explained above. After this step we reach the fourth **stage(3.3)** as shown in the picture , where the array becomes {3, 4, 7, 8, 6, 5, 2, 1} 
2. Creating a sorted sequence from bitonic sequence : After the second step, first half of the array is sorted in increasing order while second half in decreasing. We compare the first element of first half with the first element of second half, then second element of first half with the second element of second half and so on. We exchange the elements if an element of the second half is smaller.
3. After the above stage we now have two 4-element bitonic sequences in our array. If we take a look at the fifth **stage(3.2)** in the picture we can say that those sequences are namely {3,4,2,1} and {6,5,7,8}. We can furthermore see that both sequences are of length N/2 , where N is the number of elements in the array, and the elements in the first sequence are smaller than all elements of the second bitonic sequence.
4. We repeat the same process within the two bitonic sequences and we get four bitonic sequences of N/4 such that all elements of each bitonic sequence are smaller than the consecutive one. In the sixth **stage(3.1)** we can see our array now is {2,1,3,4,6,5,7,8}
5. If we repeat this process one more time we get eight bitonic sequences of size N/8 which is 1. Since all these bitonic sequences are sorted and every one of them has a single element, we get the sorted array.
