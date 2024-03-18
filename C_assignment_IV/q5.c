#include <stdio.h>

int main() {
    int number, product = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number != 0) {
        int digit = number % 10;
        product *= digit;
        number /= 10;
    }

    printf("Product of digits: %d\n", product);

    return 0;
}