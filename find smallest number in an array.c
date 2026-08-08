#include <stdio.h>

int findSmallest(int arr[], int n)
{
    
    if (n == 1)
        return arr[0];

    
    int smallest = findSmallest(arr, n - 1);

  
    if (arr[n - 1] < smallest)
        return arr[n - 1];
    else
        return smallest;
}

int main()
{
    int arr[100], n, i, smallest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    smallest = findSmallest(arr, n);

    printf("Smallest number in the array = %d", smallest);

    return 0;
}
