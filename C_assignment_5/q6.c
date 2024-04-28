#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10, 0};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergedArr[size1 + size2];
    int i, j, k;
    i = j = k = 0;

    //Merging 1st array
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    //Merging 2nd array
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArr[i]);
    }

    return 0;
}