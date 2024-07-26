#include <stdio.h>

int main() {
  FILE *file = fopen("1to100.txt", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  FILE *odd = fopen("odd.txt", "w");
  if (odd == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  FILE *even = fopen("even.txt", "w");
  if (even == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int num;
  while (fscanf(file, "%d", &num) != EOF) {
    if (num % 2 == 0) {
      fprintf(even, "%d\n", num);
    } else {
      fprintf(odd, "%d\n", num);
    }
  }

  fclose(file);
  fclose(odd);
  fclose(even);

  return 0;
}