#include <stdio.h>
//     1
//   2 3 4
// 5 6 7 8 9
int main()
{
    int count = 1;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j <= (2 - i); j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            printf("%d", count++);
        }

        printf("\n");
    }

    return 0;
}