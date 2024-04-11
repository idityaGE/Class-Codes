// Q6. Write a C program to arrange addresses in the array of pointers (created in question no. 5) in ascending order of the respective integer values at the addresses.

#include <stdio.h>

int main() {
    int num1 = 100, num2 = 10, num3 = 70, num4 = 50, num5 = 50;
    int *ptr[5];

    ptr[0] = &num1;
    ptr[1] = &num2;
    ptr[2] = &num3;
    ptr[3] = &num4;
    ptr[4] = &num5;

    printf("Addresses and corresponding values before sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address: %d, Value: %d\n", ptr[i], *(ptr[i]));
    }

    // Bubble sort
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (*(ptr[j]) > *(ptr[j + 1])) {
                int *temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("Addresses and corresponding values after sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("Address: %d, Value: %d\n", ptr[i], *(ptr[i]));
    }

    return 0;
}
