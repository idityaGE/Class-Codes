#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[50];
    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character you want to search: ");
    char c = getchar();
    if (c == '\n')
    {
        printf("You didn't enter any character.\n");
    }
    else
    {
        c = tolower(c); // convert to lowercase and for uppercase use toupper()
        for(int i = 0; i < strlen(str); i++){
            if(tolower(str[i]) == c){
                printf("Character found at position: %d\n", ++i); //this will print the first occurrence of the character not all
                break;
            }
        }
    }

    return 0;
}