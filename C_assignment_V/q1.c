#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    //sizeof(arr) return the size of the whole array in bytes
    //sizeof(arr) = 5 * 4 = 20 bytes (int size = 4 bytes)
    //sizeof(arr[0]) = 4 bytes 

    printf("Addresses of array elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: %d\n", i, &arr[i]);
    }

    return 0;
}