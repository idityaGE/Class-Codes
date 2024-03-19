#include <stdio.h>

#define MAX_SIZE 100 // define the maximum size of the array

int main()
{
    int arr[MAX_SIZE];
    int size, i, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    arr[size] = element;
    size++;

    printf("Array after inserting the element: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}