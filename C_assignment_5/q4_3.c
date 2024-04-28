#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size, position, newValue;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert the new element: ");
    scanf("%d", &position);

    printf("Enter the value of the new element: ");
    scanf("%d", &newValue);

    for (int i = size - 1; i >= position - 1; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the specific position
    arr[position - 1] = newValue;
    size++;

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
