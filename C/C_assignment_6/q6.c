#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    char str2[50];
    char result[50];
    printf("Enter your first string: ");
    fgets(str1, sizeof(str1), stdin); //fgets() draw back is that it also copies '\n' from input

    printf("Enter your second string: ");
    fgets(str2, sizeof(str2), stdin);

    int i = 0;
    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    } //here problem is that it is copying '\n' from str1 to result
    i = 0;
    while (str2[i] != '\0')
    {
        result[(strlen(str1)-1) + i] = str2[i]; //that's why we are using strlen(str1)-1 to avoid '\n' from str1
        i++;
    }
    result[(strlen(str1) + strlen(str2))-1] = '\0';

    printf("%s", result);
    
    return 0;
}