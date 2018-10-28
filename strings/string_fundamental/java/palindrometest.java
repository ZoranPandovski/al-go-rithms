import org.junit.Test;

public class palindrometest {

    @Test
    public void whenStringIsSingleLetterThenItIsAPalindrome() {
        assert (palindrome.isPalindrome("a"));
    }

    @Test
    public void checkForCaseInsensitivity(){
        assert (palindrome.isPalindrome("aAbbbBaa"));
    }

    @Test
    public void whenStringIsntPalindromeThenReturnFalse(){
        assert (!palindrome.isPalindrome("abbab"));
    }
}
