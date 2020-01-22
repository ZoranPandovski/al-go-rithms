fun ShellSort(arr: IntArray): Int {
    val sz=arr.size
    var gap = sz/2
    
    while (gap>0) {
        var i = gap
        while (i<sz) {
            val temp = arr[i]
			var j = i
            while (j>=gap && (arr[j-gap]>temp)) {
                arr[j] = arr[j-gap]
                j-=gap
            }
            arr[j]=temp
            i += 1
        }
        gap /= 2
    }
    return 0
}

fun main(args: Array<String>) {
    val arr = intArrayOf(65, 83, 21, 78, 55, 12, 9, 33)
    println("Before Sorting")
    for( a in arr) print("$a  ")

    ShellSort(arr)

    println("\nAfter sorting")
    for( a in arr) print("$a  ")
}