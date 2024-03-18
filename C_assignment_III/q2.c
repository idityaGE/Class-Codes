#include <stdio.h>

int main()
{
    int n, i, sum = 0;
    float average;

    printf("Enter the number of values: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        sum += num;
    }

    average = (float)sum / n;
    printf("The average is: %.2f\n", average);

    return 0;
}
