namespace rot47_cipher
{
    public class ROT_47_Cipher
    {
        public static string DoCipher(string text)
        {
            var result = "";
            
            foreach (char c in text)
            {
                if ((int) c >= 33 && (int) c <= 126)
                {
                    result += (char) (33 + ((int) c + 14) % 94);
                }
            }

            return result;
        }
    }
}