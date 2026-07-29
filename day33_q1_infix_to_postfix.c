// Day 33 - Question 1: Infix to Postfix Conversion
// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation
char pop() {
    return stack[top--];
}

// Peek top element
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    // Input infix expression
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // Print postfix expression
    printf("%s", postfix);

    return 0;
}