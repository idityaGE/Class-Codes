#include <stdio.h>

//what is a palindrome?
//A palindrome is a number that is the same when reversed

//function to check if a number is a palindrome
int isPalindrome(int num) {
    int reversedNum = 0, originalNum = num;
    
    while (num != 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }
    
    if (originalNum == reversedNum) {
        return 1; // Palindrome
    } else {
        return 0; // Not a palindrome
    }
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }
    
    return 0;
}