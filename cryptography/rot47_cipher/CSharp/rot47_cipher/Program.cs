using System;

namespace rot47_cipher
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter text to encrypt");
            var textToEncrypt = Console.ReadLine();

            var encrypted = ROT_47_Cipher.DoCipher(textToEncrypt);
            var decrypted = ROT_47_Cipher.DoCipher(encrypted);
            
            Console.WriteLine("Encrypted: " + encrypted);
            Console.WriteLine("Decrypted: " + decrypted);
        }
    }
}