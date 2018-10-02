# Pigeonhole Sort
Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number of elements (*n*) and the length of the range of possible key values (*N*) are approximately the same. It requires O(*n* + *N*) time. It is similar to counting sort, but differs in that it "moves items twice: once to the bucket array and again to the final destination [whereas] counting sort builds an auxiliary array then uses the array to compute each item's final destination and move the item there."

The pigeonhole algorithm works as follows:

  1. Given an array of values to be sorted, set up an auxiliary array of initially empty "pigeonholes," one pigeonhole for each key through the range of the original array.
  2. Going over the original array, put each value into the pigeonhole corresponding to its key, such that each pigeonhole eventually contains a list of all values with that key.
  3. Iterate over the pigeonhole array in order, and put elements from non-empty pigeonholes back into the original array.

## Example
Suppose one were sorting these value pairs by their first element:

    (5, "hello")
    (3, "pie")
    (8, "apple")
    (5, "king")

For each value between 3 and 8 we set up a pigeonhole, then move each element to its pigeonhole:

    3: (3, "pie")
    4:
    5: (5, "hello"), (5, "king")
    6:
    7:
    8: (8, "apple")

The pigeonhole array is then iterated over in order, and the elements are moved back to the original list.

The difference between pigeonhole sort and counting sort is that in counting sort, the auxiliary array does not contain lists of input elements, only counts:

    3: 1
    4: 0
    5: 2
    6: 0
    7: 0
    8: 1

Using this information, one could perform a series of exchanges on the input array that would put it in order, moving items only once.

For arrays where *N* is much larger than *n*, bucket sort is a generalization that is more efficient in space and time.
