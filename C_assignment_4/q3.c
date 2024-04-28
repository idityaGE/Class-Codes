#include <stdio.h>

int main()
{
    int number, firstDigit, lastDigit, sum;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Extracting the first digit
    firstDigit = number;
    while (firstDigit >= 10)
    {
        firstDigit /= 10;
    }

    // Extracting the last digit
    lastDigit = number % 10;

    // Calculate the sum
    sum = firstDigit + lastDigit;

    printf("Sum of first and last digit: %d\n", sum);

    return 0;
}