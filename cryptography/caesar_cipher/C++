#include <iostream>
#include <cstring>
using namespace std;

char* caesar(const char* text, int shift) {
    char* code = new char[strlen(text)+1]();

    shift %= 26;

    for (int i = 0; i < strlen(text); i++) {

        if (text[i] >= 'a' && text[i] <= 'z') {

            if (text[i]+shift >= 128) {
                shift -= 26;
            }

            code[i] = (char)(text[i]+shift);

            if (code[i] < 'a') {
                code[i] += 26;
            } else if (code[i] > 'z') {
                code[i] -= 26;
            }

        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            code[i] = (char)(text[i]+shift);

            if (code[i] < 'A') {
                code[i] += 26;
            } else if (code[i] > 'Z') {
                code[i] -= 26;
            }

        } else {
            code[i] = text[i];
        }
    }

    return code;
}

int main()
{
    char text[] = "The quick brown fox jumps over the lazy dog.";
    cout<<caesar(text, 13);
    return 0;
}
