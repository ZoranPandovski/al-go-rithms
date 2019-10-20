fun String.isPalindrome() : Boolean {
    for (i in 0..(this.length-1)/2) {
        if (this[i] != this[this.length-1-i]){
            return false
        }
    }
    return true
}

fun main(args: Array<String>) {
    println("testtset".isPalindrome())
    println("testxtset".isPalindrome())
    println("testertset".isPalindrome())
}