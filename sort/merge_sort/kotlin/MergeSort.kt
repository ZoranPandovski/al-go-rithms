object MergeSort {

    fun mergesort(array: IntArray) {
        mergesort(array, IntArray(array.size), 0, array.size - 1)
    }

    private fun mergesort(array: IntArray, temp: IntArray, leftStart: Int, rightEnd: Int) {
        if (leftStart >= rightEnd)
            return
        val middle = (leftStart + rightEnd) / 2
        mergesort(array, temp, leftStart, middle)
        mergesort(array, temp, middle + 1, rightEnd)
        mergeHalves(array, temp, leftStart, rightEnd)

    }

    private fun mergeHalves(array: IntArray, temp: IntArray, leftStart: Int, rightEnd: Int) {
        val leftEnd = (rightEnd + leftStart) / 2
        val rightStart = leftEnd + 1
        val size = rightEnd - leftStart + 1
        var left = leftStart
        var right = rightStart
        var index = leftStart
        while (left <= leftEnd && right <= rightEnd) {
            if (array[left] <= array[right]) {
                temp[index] = array[left]
                left++
            } else {
                temp[index] = array[right]
                right++
            }
            index++
        }

        System.arraycopy(array, left, temp, index, leftEnd - left + 1)
        System.arraycopy(array, right, temp, index, rightEnd - right + 1)
        System.arraycopy(temp, leftStart, array, leftStart, size)
    }


    @JvmStatic
    fun main(args: Array<String>) {
        val testCases = arrayOf(intArrayOf(4, 5, 7, 9), intArrayOf(4, 5, 7, 1), intArrayOf(7, 4, 5, 3, 0))
        for (testCase in testCases) {
            printArray(testCase)
            println()
            mergesort(testCase)
            printArray(testCase)
            println("\n")
        }
    }

    fun printArray(arr: IntArray) {
        for (i in arr.indices) {
            print(arr[i].toString() + " ")
        }
    }
}
