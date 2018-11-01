import java.util.Scanner

class ParenthesesGenerator {
    fun generate(n: Int): List<String> {
        if (n < 0) {
            throw IllegalArgumentException("The given number can't be lower than zero")
        }

        val result = mutableListOf<String>()
        nextLevel(result, n, n)

        return result
    }

    private fun nextLevel(list: MutableList<String>, left: Int, right: Int, index: Int = right * 2, curr: String = "") {
        if (left < 0 || right < left)
            return

        if (index == 0) {
            list.add(curr)
        } else {
            nextLevel(list, left - 1, right, index - 1, "$curr(")
            nextLevel(list, left, right - 1, index - 1, "$curr)")
        }
    }
}

fun main(args: Array<String>) {
    print("Enter a positive number: ")
    val n = Scanner(System.`in`).nextInt()

    val values = ParenthesesGenerator().generate(n)
    val stringified = values.joinToString("\",\"", "\"", "\"")

    println(stringified)
}