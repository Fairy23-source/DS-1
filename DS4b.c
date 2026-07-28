#include <stdio.h>


#define MAX 100

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int value) {
    stack[++top] = value;
}

// Pop element from stack
int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');   // Convert character to integer
        } else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = op1 % op2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    return 1;
            }
            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
