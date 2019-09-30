// Implements a basic Vigenere Cipher

// Basic Libraries
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// Enter string to encrypt here
	char* passwordText = "string to encrypt");

	// Enter key to cipher here
    char* key = "key";

    for (int i = 0, k = strlen(key); i < k; i++)
    {
        if (isalpha(key[i])) 
        {
            key[i] = toupper(key[i]); // Ignores case for encryption.
        }
        else // Exits program for non letter keys
        {
            return 1;
        }
    }

    int d = 0, p = 0;

    // Text is encripted with rotating key phrase.
    for (int i = 0, n = strlen(passwordText), k = strlen(key); i < n; i++)
    {
        d = p % k; // Check current character of key being used to encrypt

        if (isalpha(passwordText[i]))  // Skips non letters
        {
            p++;
            //uses case, letter, and rotating key for encription here.
            if (isupper(passwordText[i]))
            {
                pText[i] = (passwordText[i] + key[d] - 130) % 26 + 65;
            }
            if (islower(passwordText[i]))
            {
                pText[i] = (passwordText[i] + key[d] - 162) % 26 + 97;
            }
        }
    }

    // Prints encrypted Text
    printf("ciphertext: %s\n", passwordText);
}
