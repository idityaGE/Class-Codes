#include <stdio.h>
#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

float findMedian(int arr[], int size) {
    bubbleSort(arr, size);

    if (size % 2 == 0) {
        return (float)(arr[size / 2 - 1] + arr[size / 2]) / 2;
    } else {
        return (float)arr[size / 2];
    }
}

int main() {
    int arr[MAX_SIZE];
    int i, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    float median = findMedian(arr, n);
    printf("Median: %.2f\n", median);

    return 0;
}