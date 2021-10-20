import java.util.*
import kotlin.jvm.JvmStatic

internal object JavaProgram {
    @JvmStatic
    fun main(args: Array<String>) {
        val size: Int
        var i: Int
        val del: Int
        var count = 0
        val arr = IntArray(50)
        val scan = Scanner(System.`in`)
        print("Enter Array Size : ")
        size = scan.nextInt()
        print("Enter Array Elements : ")
        i = 0
        while (i < size) {
            arr[i] = scan.nextInt()
            i++
        }
        print("Enter Element to be Delete : ")
        del = scan.nextInt()
        i = 0
        while (i < size) {
            if (arr[i] == del) {
                for (j in i until size - 1) {
                    arr[j] = arr[j + 1]
                }
                count++
                break
            }
            i++
        }
        if (count == 0) {
            print("Element Not Found..!!")
        } else {
            print("Element Deleted Successfully..!!")
            print("\nNow the New Array is :\n")
            i = 0
            while (i < size - 1) {
                print(arr[i].toString() + " ")
                i++
            }
        }
    }
}