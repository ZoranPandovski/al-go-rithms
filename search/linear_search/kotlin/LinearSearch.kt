fun linearSearch(arr: Array<Int>, target: Int): Int? {
    for ((index, value) in arr.withIndex()) {
        if (value == target) {
            return index
        }
    }
    return null
}

fun main(args: Array<String>) {
    val arr = arrayOf(1,2,3,4,5,6,7,8,9)
    val target = 6

    println(linearSearch(arr, target))
}