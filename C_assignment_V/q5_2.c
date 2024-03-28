#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Delete element from the end
    if (size > 0)
    {
        size--;
        printf("Element %d deleted from the end.\n", arr[size]);
    }
    else
    {
        printf("Array is empty.\n");
    }

    printf("Array after deletion:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}