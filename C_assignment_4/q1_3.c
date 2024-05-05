#include <stdio.h>
//     1
//   2 3 4
// 5 6 7 8 9
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j =  ( n - i - 1); j > 0; j--)
        {
            printf("\t");
        }
        for (int k = 1; k <= (2 * i + 1); k++)
        {
            printf("%d\t", count++);
        }
        printf("\n");
    }
    return 0;
}
