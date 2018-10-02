## Circle sort

__Circle sort__ algorithm compares the first element to the last element, then the second element to the second last element, etc.

Then split the array in two and recurse until there is only one single element in the array. 

In short below two steps are repeated while there are swap operations involved in the steps.

1. Compare the first element to the last element, then the second element to the second last element, etc.
1. Then split the array in two and recurse until there is only one single element in the array.

#### This image explain it better

![Circle sort diagram](http://forth-4th.sourceforge.net/images/CircleSort.png)

_Image source_ [SourceForge](https://sourceforge.net/p/forth-4th/wiki/Circle%20sort/)