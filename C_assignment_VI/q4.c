#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[50];
    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character you want to find occurrence: ");
    char c = getchar();
    if (c == '\n')
    {
        printf("You didn't enter any character.\n");
    }
    else
    {
        c = tolower(c);
        int count = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (tolower(str[i]) == c)
            {
                ++count;
            }
        }
        printf("Occurrence of given character in string is : %d\n", count);
    }

    return 0;
}