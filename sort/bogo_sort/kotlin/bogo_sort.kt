/*
Bogo Sort

Bogo Sort is the most inefficient way of sorting an algorithm.
The way Bogo Sort works is like throwing a deck of cards in the air
and picking them back up and checking to see if it's organized.

Array of ints [ 3, 1, 2 ]
Step 1.
Starts at the start of the array and will grab a random index from the array to switch with.

randomIndex = RANDOM NUMBER

Step 2.
Once random index is obtained, it will then switch the current index value with the random index value
Example: randomIndex = 2, currentIndex = 0

[ 3, 1, 2 ] ---> [ 2, 1, 3 ]

Step 3.
Check if array is sorted.
[ 2, 1, 3 ] <---- Is not sorted so go onto the next index and repeat steps 1 & 2. Stop when sorted

- You could be done in the next step or the next million steps :')
*/
package com.exam.kotlin.codingproject

import kotlin.random.Random

class BogoSort {

    companion object{
        private val randomValues = List(10) { Random.nextInt(0, 100) }

        private fun isSorted(arr: IntArray): Boolean {
            for (i in 0 until arr.size - 1) {
                if (arr[i] > arr[i + 1]) {
                    return false
                }
            }
            return true
        }

        fun bogoSort(numbersToSort: IntArray) : IntArray {
            while (!isSorted(numbersToSort)) {
                for (i in numbersToSort.indices) {
                    val randomIndex = randomValues[numbersToSort.size]
                    val holder = numbersToSort[i]
                    numbersToSort[i] = numbersToSort[randomIndex]
                    numbersToSort[randomIndex] = holder
                }
            }

            return numbersToSort
        }

    }
}
