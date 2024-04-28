#include <stdio.h>

#define MAX_SIZE 100 // define the maximum size of the array

int main()
{
    int arr[MAX_SIZE];
    int size, i, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    // Shift elements to the right
    for (i = size - 1; i >= 0; i--) //"(size -1)" is the last element index of the array
    {
        arr[i + 1] = arr[i];
    }

    // Insert the element at the start
    arr[0] = element;

    size++; // Increase the size of the array

    printf("Array after inserting the element: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}