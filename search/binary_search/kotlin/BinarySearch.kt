class BinarySearch(private val array: IntArray) {

    //Search for a number in an array
    fun search(number: Int): Int {
        return binarySearch(0, array.size - 1, number)
    }

    // Returns index of x if it is present in the array, else returns -1
    private fun binarySearch(start: Int, end: Int, number: Int): Int {
        if (start <= end) {
            val middle = start + (end - start) / 2

            if (array[middle] == number)
                return middle

            return if (array[middle] > number) binarySearch(start, middle - 1, number) else binarySearch(middle + 1, end, number)

        }

        return -1
    }
}

fun main(args: Array<String>) {
    val searchableArray = BinarySearch(intArrayOf(2, 3, 7, 8, 78, 99, 102, 5555))
    val numberToFind = 102
    val result = searchableArray.search(numberToFind)
    if (result == -1)
        println("Element not present")
    else
        println("Element found at index $result")
}