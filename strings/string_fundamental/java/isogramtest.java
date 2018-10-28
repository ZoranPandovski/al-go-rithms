import org.junit.Test;

public class isogramtest {

    @Test
    public void whenStringHasRepeatingCharactersThenItIsNotAnIsogram() {
        assert (!isogram.isIsogram("abcdefb"));
    }

    @Test
    public void whenStringHasNoRepeatingCharactersThenItIsAnIsogram(){
        assert (isogram.isIsogram("bacdefg"));
    }

    @Test
    public void whenStringIsEmptyThenItIsAnIsogram(){
        assert (isogram.isIsogram(""));
    }

    @Test
    public void whenStringIsOneLetterThenItIsAnIsogram(){
        assert (isogram.isIsogram("A"));
    }
}
