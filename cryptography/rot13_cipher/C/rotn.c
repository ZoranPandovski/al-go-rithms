#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *test = "HELLO WORLD. This is a test";
    char out[strlen(test)];
    out[strlen(test)] = '\0';

    rot(test, &out, 13);
    printf("Input: %s\n", test);
    printf("Output: %s", out);

    return 0;
}

void rot(char *in, char *out, int n)
{
    int i;
    char c;
    for (i = 0; i < strlen(in); i++)
    {
        c = in[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c + n > 'z' || (c <= 'Z' && c + n > 'Z'))
            {
                c -= (26 - n);
            }
            else
            {
                c += n;
            }
        }
        out[i] = c;
    }
}
