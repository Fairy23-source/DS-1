#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function to Push an element
void push()
{
    int item;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow!\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &item);

    top++;
    stack[top] = item;

    printf("%d inserted into the stack.\n", item);
}

// Function to Pop an element
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    printf("Deleted element is %d\n", stack[top]);
    top--;
}

// Function to Peek the top element
void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("Top element is %d\n", stack[top]);
}

// Function to Display stack
void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting Program...\n");
                return 0;

            default:
                printf("\nInvalid Choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
