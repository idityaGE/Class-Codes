#include <stdio.h>
#define MAX_SIZE 100

int countFrequency(int arr[], int size, int element)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[MAX_SIZE];
    int i, n, elem;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element for its frequency: ");
    scanf("%d", &elem);

    int frequency = countFrequency(arr, n, elem);

    printf("The frequency of %d in the array is %d\n", elem, frequency);

    return 0;
}