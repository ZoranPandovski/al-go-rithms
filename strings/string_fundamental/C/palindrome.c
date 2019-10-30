#include <stdio.h>
#include <string.h>

int
is_palindrome(char *string) {
    int i, n = strlen(string);

    // Only look through half the string
    for(i = 0; i < n/2; i++) {
        if(string[i] != string[n-i-1]) {
            return 0;
        }
    }
    return 1;
}

int
main(int argc, char *argv[]) {
    if(is_palindrome(argv[1])) {
        printf("%s is a palindrome", argv[1]);
    }
    else {
        printf("%s is NOT a palindrome", argv[1]);
    }
    return 0;
}