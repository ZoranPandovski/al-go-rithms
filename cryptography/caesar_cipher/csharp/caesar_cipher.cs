using System;
using System.Linq;
 
namespace CaesarCipher
{
    class Program
    {
        static char Encrypt(char ch, int shift)
        {
            if (!char.IsLetter(ch)) return ch; 
            char offset = char.IsUpper(ch) ? 'A' : 'a';
            return (char)((ch + shift - offset) % 26 + offset);
        }
 
        static string Encrypt(string input, int shift)
        {
            return String.Join(String.Empty, input.Select(ch => Encrypt(ch, shift)));
        }
 
        static string Decrypt(string input, int shift)
        {
            return Encrypt(input, 26 - shift);
        }
  
        static void Main()
        {
            string original = "Hey al-go-rithms! Hello from C#";
            string encrypted = Encrypt(original, 5);
            string decrypted = Decrypt(encrypted, 5);
            Console.WriteLine($"Original: {original}");
            Console.WriteLine($"Encrypted: {encrypted}");
            Console.WriteLine($"Decrypted: {decrypted}");
        }
    }
}