#include <stdio.h>

int main()
{
  FILE *fp = fopen("1to100.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  for (int i = 1; i <= 100; i++)
  {
    fprintf(fp, "%d\n", i);
  }

  fclose(fp);

  return 0;
}