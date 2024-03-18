#include <stdio.h>

int main() {
    int numLines;
    printf("Enter the number of lines: ");
    scanf("%d", &numLines);

    for (int i = 1; i <= numLines; i++) {
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 0) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }

    return 0;
}
