import java.util.Arrays

fun bubbleSort(arr: Array<Int>) {
    var swapOccurred: Boolean
    var len = arr.lastIndex

    do {
        swapOccurred = false

        for (i in 0 until len) {
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i+1].also {arr[i+1] = arr[i]}
                swapOccurred = true
            }
        }
        len--
    } while (swapOccurred)
}

fun main(args: Array<String>) {
    val arr = arrayOf(1, 3, 5, 4, 2, 6, 8, 9, 7, 10, 13, 15, 17, 16, 14, 12, 19, 18, 11)

    bubbleSort(arr)
    println(Arrays.toString(arr))
}