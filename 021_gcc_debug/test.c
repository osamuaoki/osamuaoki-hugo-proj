#include <stdlib.h>
#include <stdio.h>
int main() {
  int i, final, factorial = 1;
  printf("Enter the number: ");
  if (scanf("%d", &final)) {
    exit(1);
  } else {
    for (i = 1; i <= final; i++)
      factorial = factorial * i;
    printf("The factorial of %d is %d\n", final, factorial);
    exit(0);
  }
}
