#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[50];
    char str2[50];
    printf("Enter your first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter your second string: ");
    fgets(str2, sizeof(str2), stdin);

    int i = 0;
    if (strlen(str1) != strlen(str2))
    {
        printf("Strings are not equal.\n");
    }
    else
    {
        while (str1[i] != '\0')
        {
            if (tolower(str1[i]) != tolower(str2[i]))
            {
                printf("Strings are not equal.\n");
                break;
            }
            i++;
        }
        if (str1[i] == '\0')
        {
            printf("Strings are equal.\n");
        }
    }
    return 0;
}