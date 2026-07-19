#include <stdio.h>

#define MAX 100

// Function to display array
void traverse(int arr[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to insert an element
int insert(int arr[], int n)
{
    int pos, value, i;

    if (n == MAX)
    {
        printf("Array is full.\n");
        return n;
    }

    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("Invalid position.\n");
        return n;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;

    printf("Element inserted successfully.\n");
    return n + 1;
}

// Function to delete an element
int deleteElement(int arr[], int n)
{
    int pos, i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return n;
    }

    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("Invalid position.\n");
        return n;
    }

    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    printf("Element deleted successfully.\n");
    return n - 1;
}

// Function to search an element
void search(int arr[], int n)
{
    int key, i, found = 0;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found.\n");
}

// Main function
int main()
{
    int arr[MAX];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;

        case 2:
            n = insert(arr, n);
            break;

        case 3:
            n = deleteElement(arr, n);
            break;

        case 4:
            search(arr, n);
            break;

        case 5:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
