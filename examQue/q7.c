#include <stdio.h>
#include <time.h>

// Function to calculate the number of days between two dates
int calculateAgeInDays(int birthYear, int birthMonth, int birthDay)
{
  // Get the current date
  time_t now;
  time(&now);
  struct tm *currentTime = localtime(&now); 

  // Set the birth date
  struct tm birthDate = {0};
  birthDate.tm_year = birthYear - 1900;
  birthDate.tm_mon = birthMonth - 1; // Month is zero-based
  birthDate.tm_mday = birthDay;

  // Convert both dates to time_t
  time_t birthTime = mktime(&birthDate);

  // Calculate the difference in seconds
  double difference = difftime(now, birthTime);

  // Convert seconds to days
  int days = difference / (60 * 60 * 24);

  return days;
}

int main()
{
  int birthYear, birthMonth, birthDay;

  // Prompt user to enter date of birth
  printf("Enter your date of birth (YYYY MM DD): ");
  scanf("%d %d %d", &birthYear, &birthMonth, &birthDay);

  // Calculate age in days
  int ageInDays = calculateAgeInDays(birthYear, birthMonth, birthDay);

  // Display the result
  printf("Your age in days is: %d\n", ageInDays);

  return 0;
}
