#include <stdio.h>

int main(int argc, char const *argv[])
{
  printf("Hello world!\n");

  char buffer[400];
  char c = 0;

  size_t ctr = 0;
  while (c != '\n')
  {
    c = getchar();
    buffer[ctr++] = c;
  }
  buffer[ctr] = '\0';

  printf("=============\n");
  printf("%s\n", buffer);

  return 0;
}
