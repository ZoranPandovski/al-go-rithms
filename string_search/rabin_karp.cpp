#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256
 
void search(char pattern[], char text[], int modulo_prime = 101) {

    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int pattern_hash = 0; 
    int text_hash = 0; 
    int power_hash = 1;
 
    for (i = 0; i < M-1; i++) {
        power_hash = (power_hash*MAX_CHAR)%modulo_prime;
    }

    for (i = 0; i < M; i++) {
        pattern_hash = (MAX_CHAR*pattern_hash + pattern[i])%modulo_prime;
        text_hash = (MAX_CHAR*text_hash + text[i])%modulo_prime;
    }
 
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text
        // and pattern. 
        if (pattern_hash == text_hash) {
            for (j = 0; j < M; j++) {
                if (text[i+j] != pattern[j]) {
                    break;
                }
            }
            if (j == M) {
                cout << "Pattern found at index: " << i << "\n";
            }
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N-M) {
            text_hash = (MAX_CHAR*(text_hash - text[i]*power_hash) + text[i+M])%modulo_prime;
            if (text_hash < 0) {
                text_hash = (text_hash + modulo_prime);
            }
        }
    }
}
