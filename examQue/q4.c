// Write a C program to compute your age in number of days by given date of birth.

#include <stdio.h>

int main() {
  int date, month, year;
  printf("Enter date: ");
  scanf("%d", &date);
  printf("Enter month: ");
  scanf("%d", &month);
  printf("Enter year: ");
  scanf("%d", &year);

  int days = 0;
  for (int i = 1; i < year; i++) {
    if (i % 4 == 0) {
      days += 366;
    } else {
      days += 365;
    }
  }

  for (int i = 1; i < month; i++) {
    if (i == 2) {
      if (year % 4 == 0) {
        days += 29;
      } else {
        days += 28;
      }
    } else if (i == 4 || i == 6 || i == 9 || i == 11) {
      days += 30;
    } else {
      days += 31;
    }
  }

  days += date;

  printf("Your age in days: %d\n", days);
  return 0;
}