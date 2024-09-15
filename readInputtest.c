#include <ReadInput.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  printf("Input: ");
  char *buffer = dynamicReadInput();

  printf("=============\n");
  printf("%s\n", buffer);

  free(buffer);
  return 0;
}
