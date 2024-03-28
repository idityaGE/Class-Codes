#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to find the median of an array
float findMedian(int arr[], int size) {
    // Sort the array in ascending order
    bubbleSort(arr, size);

    // Check if the size of the array is even or odd
    if (size % 2 == 0) {
        // If the size is even, return the average of the middle two elements
        return (float)(arr[size / 2 - 1] + arr[size / 2]) / 2;
    } else {
        // If the size is odd, return the middle element
        return (float)arr[size / 2];
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6, 3, 8, 4}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    float median = findMedian(arr, size);
    printf("Median: %.2f\n", median);

    return 0;
}