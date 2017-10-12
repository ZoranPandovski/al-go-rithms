# Interpolation Search

Interpolation search is an algorithm for searching for a given key in an indexed array that has been ordered. It parallels how humans search through a telephone book for a particular name, the key value by which the book's entries are ordered. In each search step it calculates where in the remaining search space the sought item might be, based on the key values at the bounds of the search space and the value of the sought key, usually via a linear interpolation. The key value actually found at this estimated position is then compared to the key value being sought. If it is not equal, then depending on the comparison, the remaining search space is reduced to the part before or after the estimated position.<br><br>
The idea of formula is to return higher value of pos when element to be searched is closer to arr[h]. And smaller value when closer to arr[l].<br>
To find the position to be searched, it uses following formula:-<br>
pos = l + [ (x-arr[l])*(h-l) / (arr[h]-arr[L]) ]

arr[] ==> Array where elements need to be searched<br>
x     ==> Element to be searched<br>
l    ==> Starting index in arr[]<br>
h    ==> Ending index in arr[]<br>