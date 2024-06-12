#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("Hello world!\n");
  printf("argc = %i\n", argc);
  for (int i = 1; i <= argc; i++)
    printf("arg[%i] = %s\n", i, argv[i]);
  exit(0);
}
