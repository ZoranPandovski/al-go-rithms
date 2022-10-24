using System;

namespace CaesarCipher {
    public class CaesarCipher {
        public string encrypt(string message, int key) {
            // If message is null or empty, return.
            if (String.IsNullOrEmpty(message)) {
                return message;
            }

            // Create a char array and insert all the chars from the string message.
            char[] messageArray = message.ToCharArray();

            // Add the encryption key to each letter of the string.
            for (int i = 0; i < messageArray.Length; i++) {
                messageArray[i] = (char)(messageArray[i] + key);
            }

            return new string(messageArray);
        }

        public static void Main (string[] args) {
            // Get a message to encrypt from user.
            Console.Write("Give me a message to encrypt: ");
            string messageToEncrypt = Console.ReadLine();

            // Get the encryption key.
            Console.Write("Give me an encryption key (negative/possitive integer): ");
            int key = Int32.Parse(Console.ReadLine());

            // Encrypt the message with the given key.
            CaesarCipher cc = new CaesarCipher();
            string encryptedMessage = cc.encrypt(messageToEncrypt, key);

            // // Show the user the encrypted message.
            Console.WriteLine($"Encrypted Message: {encryptedMessage}");
        }
    }
}