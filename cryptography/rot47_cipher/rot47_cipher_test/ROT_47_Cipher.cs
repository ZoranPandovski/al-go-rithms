using Xunit;

namespace rot47_cipher_test
{
    public class ROT_47_Cipher
    {
        [Theory]
        [InlineData("Hello World!")]
        [InlineData("!@#$%   ^&*&^&*    %$PO  IUYTR  EWQ")]
        [InlineData("+_{}:LJHJY^%$$DFDHH&&dfghdfgh")]
        public void DoCipher_Should_Decrypt_Successfully(string text)
        {
            var result = rot47_cipher.ROT_47_Cipher.DoCipher(text);
            result = rot47_cipher.ROT_47_Cipher.DoCipher(result);
            Assert.Equal(text, result);
        }
    }
}