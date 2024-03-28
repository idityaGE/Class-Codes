#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int i, n, pos1, pos2, temp;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of first element: ");
    scanf("%d", &pos1);
    
    printf("Enter the position of second element: ");
    scanf("%d", &pos2);

    temp = arr[pos1 - 1];
    arr[pos1 - 1] = arr[pos2 - 1];
    arr[pos2 - 1] = temp;

    printf("Array after swapping the elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
};