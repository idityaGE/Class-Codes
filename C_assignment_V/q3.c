#include <stdio.h>

#define MAX 100

void shiftRight(int arr[], int size)
{
    int i;
    int last = arr[size - 2]; // Store the second last element

    for (i = size - 3; i >= 0; i--)
    {
        arr[i + 1] = arr[i]; // Shift each element to the right by one position
    }

    arr[0] = last; // Assign the second last element to the first position
}

int main()
{
    int arr[MAX];
    int size, i;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 3)
    {
        printf("Size should be at least 3.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Shifting elements to the right by one position
    shiftRight(arr, size);

    // Printing the shifted array
    printf("Array after shifting elements to the right by one position:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


