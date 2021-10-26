#include<stdio.h>
#include<ctype.h>
#include<string.h>

/*  
    About: 
        This program takes a contigous string without spaces and tells if it 
        is a palindrome or not. Uppercase or lowercase doesn't matter.
*/

/*
    TEST CASES:
        Input: Hello
        Output: The entered string is NOT PALINDROME!

    Input: NaMan
    Output: The entered string is a PALINDROME!

    Input: lOL
    Output: The entered string is a PALINDROME!
*/

int main() {
    char str[100], reversed_str[100], ch;
    int str_length, i;

    printf("Enter the string: ");
    scanf(" %[^\n]%*c", str); 
    /*
        - The [^\n] takes characters until a new line character is entered
        - The *c tells scanf to remove the newline character in the end of the entered string
    */

    
    str_length = strlen(str); // The strleng() function returns the length of the string given as parameter

    /*This loop converts all the uppercase charaters to lowercase characters*/
    while(i < str_length) {         
        ch = str[i];
        str[i] = tolower(ch); // tolower() converts the uppercase character to a lowercase
        i++;
    }

    /* 
        - The strcpy(str1, str2) function copies the str2 into str1    
    */
    strcpy(reversed_str, str);

    /*
        - The strcmp(str1, str2) function compares both the string and return:
            - 0 : If both the string match
            - >0 : If the first non-matching character in str1 is greater (in ASCII) than that of str2
            - <0 : If the first non-matching character in str1 is lower (in ASCII) than that of str2
        - The strrev(str) function is defined in string.h and is used to reverse the string
    */
    if(strcmp(str, strrev(reversed_str)) == 0) {
        printf("\nThe entered string is a PALINDROME!");
    } else {
        printf("The entered string is NOT PALINDROME!");
    }

    return 0;
}