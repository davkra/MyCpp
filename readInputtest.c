#include <ReadInput.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  char *buffer = readInput();

  printf("=============\n");
  printf("%s\n", buffer);

  free(buffer);
  return 0;
}
