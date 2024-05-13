#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num)
{
  if (num <= 1)
  {
    return 0;
  }
  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  FILE *file = fopen("prime.txt", "w");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // Iterate through numbers from 1 to 100 and print primes to the file
  for (int i = 1; i <= 100; i++)
  {
    if (isPrime(i))
    {
      fprintf(file, "%d\n", i);
    }
  }

  printf("Prime numbers from 1 to 100 written to prime.txt\n");

  fclose(file);
  return 0;
}
