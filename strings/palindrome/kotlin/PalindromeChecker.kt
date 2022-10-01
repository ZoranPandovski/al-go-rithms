class PalindromeChecker() {
    fun isPalindrome(sample: String): Boolean {
        val testWord: String = sample.toLowerCase()

        val words: List<String> = testWord.split("")
        var reversed: String = ""

        var index: Int = words.size - 1

        for (word in words) {
            reversed += words[index]
            index--
        }

        if (reversed == testWord) {
            return true
        }

        return false
    }
}