
import java.util.*
import kotlin.jvm.JvmStatic

object Sorting {
    @JvmStatic
    fun main(args: Array<String>) {
        val n: Int
        var temp: Int
        val s = Scanner(System.`in`)
        print("Enter no. of elements you want in array:")
        n = s.nextInt()
        val a = IntArray(n)
        println("Enter all the elements:")
        for (i in 0 until n) {
            a[i] = s.nextInt()
        }
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                if (a[i] > a[j]) {
                    temp = a[i]
                    a[i] = a[j]
                    a[j] = temp
                }
            }
        }
        print("Ascending Order:")
        for (i in 0 until n - 1) {
            print(a[i].toString() + ",")
        }
        print(a[n - 1])
    }
}