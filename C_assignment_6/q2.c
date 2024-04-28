#include <stdio.h>
#include <string.h>

int main()
{
    char enrol[50];
    char rev[50];
    printf("Enter your Enrollment No.: ");
    fgets(enrol, sizeof(enrol), stdin);

    for (int i = strlen(enrol) - 1; i >= 0; i--)
    {
        char c = enrol[i];
        rev[strlen(enrol) - 1 - i] = c;
    }
    rev[strlen(enrol)] = '\0';

    printf("Reverse of your Enrollment No.: %s\n", rev);

    return 0;
}