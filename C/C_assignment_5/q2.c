#include <stdio.h>

int main() {
    int arr[] = {59, 12, 69, 77, 49};
    int size = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("The smallest element in the array is: %d\n", smallest);

    return 0;
}