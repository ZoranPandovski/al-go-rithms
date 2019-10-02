using System;

namespace rot47_cipher
{
    public class ROT_47_Cipher
    {
        public static string DoCipher(string text)
        {
            var result = "";
            
            foreach (char c in text)
            {
                if ((int) c >= 32 && (int) c <= 126)
                {
                    if (Char.IsWhiteSpace((char) c))
                    {
                        result += " ";
                    }
                    else
                    {
                        result += (char) (33 + ((int) c + 14) % 94);
                    }
                }
            }

            return result;
        }
    }
}