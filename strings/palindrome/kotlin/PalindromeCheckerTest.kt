import org.junit.jupiter.api.Test
import org.junit.jupiter.api.Assertions.assertEquals

internal class PalindromeCheckerTest {

    private val testPalindromeChecker: PalindromeChecker = PalindromeChecker()

    @Test
    internal fun isPalindrome() {
        val sample: String = "kasur rusak"
        val expected: Boolean = true

        assertEquals(expected, testPalindromeChecker.isPalindrome(sample))
    }

    @Test
    internal fun isNotPalindrome() {
        val sample: String = "the quick fox"
        val expected: Boolean = false

        assertEquals(expected, testPalindromeChecker.isPalindrome(sample))
    }
}