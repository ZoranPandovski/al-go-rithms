fun divideArr(array : ArrayList<Int>,low : Int, top : Int) : Int{
    val pivot = array[top]
    var i = (low - 1)
    for (j in low .. top){
        if(array[j] <= pivot){
            i++

            val t = array[i]
            array[i] = array[j]
            array[j] = t
        }
    }

    val t = array[i+1]
    array[i+1] = array[top]
    array[top] = t

    return i+1
}

fun quickSort(array : ArrayList<Int>, low : Int, top : Int){
    if(low < top){
        val p = divideArr(array,low,top)

        quickSort(array,low,p-1)
        quickSort(array,p+1,top)
    }
}

fun printArray(array : ArrayList<Int>){
    val n = array.size
    for ( i in 0 .. n){
        print(array[i].toString() + " ")
    }
    println("--------------")
}

fun main(args: Array<String>) {
    val array : ArrayList<Int> = ArrayList()
    array.apply {
        add(16)
        add(65)
        add(36)
        add(524)
        add(8431)
        add(3)
        add(1)
        add(6548)
        add(100)
        add(1656)
    }

    val n = array.size
    quickSort(array, 0, n-1)
    println("Array sorted by QuickSort")
    printArray(array)
}