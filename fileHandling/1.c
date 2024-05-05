#include <stdio.h>

int main()
{
  FILE *fp;
  fp = fopen("test.txt", "w");
  putc('A', fp);
  putc('B', fp);
  putc('C', fp);
  fclose(fp);
  return 0;
}