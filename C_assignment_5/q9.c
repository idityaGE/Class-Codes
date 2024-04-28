#include <stdio.h>
#define MAX_SIZE 100

int countEvenElem(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[MAX_SIZE];
    int i, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int noOfEven = countEvenElem(arr, n);

    printf("The number of Even elements in the array is %d\n", noOfEven);

    return 0;
}