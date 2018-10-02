import java.util.Arrays

fun insertionSort(arr: Array<Long>) {
    for (j in 1..arr.size - 1){
        var i = j - 1;
        val processedValue = arr[j];
        while ( (i >= 0) && (arr[i] > processedValue) ){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = processedValue;
    }
}

fun main(args: Array<String>) {
    val arr = arrayOf(1, 3, 5, 4, 2, 6, 8, 9, 7, 10, 13, 15, 17, 16, 14, 12, 19, 18, 11)

    insertionSort(arr)
    println(Arrays.toString(arr))
}


