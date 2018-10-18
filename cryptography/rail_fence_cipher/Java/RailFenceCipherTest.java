import org.junit.Test;
import static org.junit.Assert.assertEquals;
import org.junit.runners.JUnit4;

// TODO: Replace examples and use TDD development by writing your own tests

public class RailFenceCipherTest {

    @Test
    public void encodeSampleTests() {
        String[][] encodes = {{"WEAREDISCOVEREDFLEEATONCE", "WECRLTEERDSOEEFEAOCAIVDEN"},  // 3 rails
                              {"Hello, World!", "Hoo!el,Wrdl l"},    // 3 rails
                              {"Hello, World!", "H !e,Wdloollr"},    // 4 rails
                              {"", ""}                               // 3 rails (even if...)
                             };
        int[] rails = {3,3,4,3};
        for (int i=0 ; i<encodes.length ; i++) {
            assertEquals(encodes[i][1], RailFenceCipher.encode(encodes[i][0], rails[i]));
        }
    }


    @Test
    public void decodeSampleTests() {
        String[][] decodes = {{"WECRLTEERDSOEEFEAOCAIVDEN", "WEAREDISCOVEREDFLEEATONCE"},    // 3 rails
                              {"H !e,Wdloollr", "Hello, World!"},    // 4 rails
                              {"", ""}                               // 3 rails (even if...)
                             };
        int[] rails = {3,4,3};
        for (int i=0 ; i<decodes.length ; i++) {
            assertEquals(decodes[i][1], RailFenceCipher.decode(decodes[i][0], rails[i]));
        }
    }
    @Test
    public void testWithEncodingEmptyString()
    {
        System.out.println("Test with encoding empty string...");
        assertEquals("", RailFenceCipher.encode("", 3));
    }

    @Test
    public void testWithDecodingEmptyString()
    {
        System.out.println("Test with decoding empty string...");
        assertEquals("", RailFenceCipher.decode("", 3));
    }

    @Test
    public void testWithEncodingSmallStringWithTwoRails()
    {
        System.out.println("Test with encoding small string with two rails...");
        String str = "TESTING";
        String encodedStr = "TSIGETN";
        assertEquals(encodedStr, RailFenceCipher.encode(str, 2));
    }

    @Test
    public void testWithEncodingSmallStringWithThreeRails()
    {
        System.out.println("Test with encoding small string with three rails...");
        String str = "TESTING";
        String encodedStr = "TIETNSG";
        assertEquals(encodedStr, RailFenceCipher.encode(str, 3));
    }

    @Test
    public void testWithDecodingSmallStringWithTwoRails()
    {
        System.out.println("Test with decoding small string with two rails...");

        String str = "TSIGETN";
        String decodedStr = "TESTING";
        assertEquals(decodedStr, RailFenceCipher.decode(str, 2));
    }

    @Test
    public void testWithDecodingSmallStringWithThreeRails()
    {
        System.out.println("Test with decoding small string with three rails...");

        String str = "TIETNSG";
        String decodedStr = "TESTING";
        assertEquals(decodedStr, RailFenceCipher.decode(str, 3));
    }
}
