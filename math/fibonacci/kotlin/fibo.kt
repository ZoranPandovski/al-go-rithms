/**
 * Calculate Numbers in the Fibonacci sequence using Dynamic Programming 
 * No recursion
 * Execution time: O(n)
 */

fun fibonacci (n: Int): Long{       
    if (n <= 0){
        return 0
    }  else if (n == 1){
        return 1
    } else {
        var a: Long = 0
        var b: Long = 1
        var value: Long = 0
        repeat(n-1){
            value = a + b
            a = b
            b = value
        }               
        return value
    }    
}

fun main(args: Array<String>) {
    val testIndexes: Array<Int> = arrayOf(1, 4, 6, 10, 22)
    
    for (index in testIndexes) {
        println("Fibonacci sequence. Position: $index. Value: ${fibonacci(index)}")
    }    
}