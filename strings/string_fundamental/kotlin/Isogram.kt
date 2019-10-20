fun String.isIsogram(): Boolean {
    val chars = this.toUpperCase().toCharArray()
    chars.sort()
    for (i in 0 until chars.size - 1) {
        if (chars[i] == chars[i + 1]) {
            return false
        }
    }
    return true
}

fun main(args: Array<String>) {
    println("tes".isIsogram())
    println("tesir".isIsogram())
    println("test".isIsogram())
}