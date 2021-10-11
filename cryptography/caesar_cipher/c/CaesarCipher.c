//including libraries

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char ctext;

//main function which accepts key as its parameter

int main(int argc, string argv[])
{
    //checking if key consists of 2 words or not

    if (argc == 2)
    {
        //iterating to check the digits and aplhabets in the key

        for (int j = 0; j < argc; j++)
        {
            if (isalpha(argv[1][j]) != 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //getting the user input for plaintext

        string pt = get_string("plaintext: ");
        int key = atoi(argv[1]);
        //wrapping the plaintext

        if (key > 26)
        {
            key = key % 26;
        }
        printf("ciphertext: ");
        for (int i = 0, len = strlen(pt); i < len; i++)
        {
            if (islower(pt[i]) != 0 && isupper(pt[i]) == 0)
            {
                pt[i] = pt[i] - 'a';
                ctext = ((pt[i] + key) % 26) + 'a';
            }
            else if (isupper(pt[i]) != 0 && islower(pt[i]) == 0)
            {
                pt[i] = pt[i] - 'A';
                ctext = ((pt[i] + key) % 26) + 'A';
            }
            else
            {
                ctext = pt[i];
            }
            printf("%c", ctext);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
