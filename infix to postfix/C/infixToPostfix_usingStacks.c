/*
 Program to convert an infix expression into postfix expression using 'stack' data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Linked List Implementation of Stacks
struct node {
    char data;
    struct node *next;
} *head;

// Prototype of functions - Function Declaration
bool isEmpty(void);
char pop(void);
char top(void);

// Note: Instead, type 'void' in fxn definition if function takes no arguments

bool isEmpty() {
    return (head == NULL);
}

void push(char elt) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->next = head;
    temp->data = elt;
    head = temp;
}

char pop() {
    char retVal = head->data;
    head = head->next;
    return retVal;
}

char top() {
    return isEmpty() ? '\0' : head->data;    // Ternary operator in C
    // Format: (condition) ? (exec. if cond. is true) : (exec. if cond. is false)
    
    /*
    (or)
     
    if (isEmpty()) {
        return '\0';
    }
    else {
        return head->data;
    }
     */
}

// Returns precedence of the argument character
int preced(char elt) {
    if (elt == '\0') {
        return -1;
    }
    else if (elt == '(') {
        return 0;
    }
    else {
        int flag = 0;
        char sym[4] = {'+', '-', '*', '/'};
        int preced[4] = {1, 1, 2, 2};
        
        for (int i = 0; i < 4; i++) {
            if (sym[i] == elt) {
                flag = 1;
                return preced[i];
            }
        }
        return '\0';
    }
}

// Checks if argument character is an alphabet (a-z & A-Z) or not
bool isAlp(char alp) {
    char alpArr[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for (int i = 0; i < 52; i++) {
        if (alp == alpArr[i]) {
            return true;
        }
    }
    return false;
}

// Checks if argument character is a number (0-9) or not
bool isNum(char num) {
    char numArr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i = 0; i < 10; i++) {
        if (num == numArr[i]) {
            return true;
        }
    }
    return false;
}

// Checks if argument character is a symbol (+,-,/,*) or not
bool isSym(char sym) {
    char symArr[4] = {'+', '-', '*', '/'};
    
    for (int i = 0; i < 4; i++) {
        if (sym == symArr[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    
    printf("*** Infix to Postfix Converter *** \n");
    
    // Input
    char infix[100];
    printf("\nEnter infix expression: ");
    scanf("%s", infix);
    
    char postfix[100] = {};
    int i;
    int pos = 0;
    
    for (i = 0; i < strlen(infix); i++) {
        // Check for number & Add to Postfix
        if (isNum(infix[i])) {
            postfix[pos++] = infix[i];
        }
        
        // Check for alphabet & Add to Postfix
        else if (isAlp(infix[i])) {
            postfix[pos++] = infix[i];
        }
        
        // Check for symbol
        else if (isSym(infix[i])) {
            while ((preced(infix[i])) <= preced(top())) {
                postfix[pos++] = pop();
            }
            push(infix[i]);
        }
        
        // Check for parenthesis
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            // Pop all elements of stack until '(' is reached
            while (top() != '(') {
                postfix[pos++] = pop();
            }
            // Pop '('
            pop();
        }
        else {
            printf("Invalid character(s) in expression. Only numbers (0-9), alphabets (A-Z & a-z) and \'+\', \'-\', \'/\' and \'*\' are allowed. \n");
            exit(0);
        }
    }
    
    // Pop remaning elements of stack
    while(!(isEmpty())) {
        postfix[pos++] = pop();
    }
    
    // Output
    printf("Postfix: %s \n", postfix);
    
    return 0;
}

/*
 i) Note:
 
 postfix[pos] = pop();
 pos++
 
 (alternative)
 
 postfix[pos++] = pop();
 
 ii) Note:
 
 <type> foo() {    <- Definition
    <statements>
 }
 
 is an old-style function definition in C without any parameters.
 
 If no parameters, declare function with parameter 'void' to avoid errors.
 E.g. <type> foo(void);    <- Declaration
 
 (or)
 
 Type 'void' in function definition itself if function takes no parmeters.
 */

