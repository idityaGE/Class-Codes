#include <stdio.h>

int main()
{
    int n, i, term = 1, nextTerm = 1;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Series: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", term);
        nextTerm = term + i;
        term = nextTerm;
    }

    return 0;
}