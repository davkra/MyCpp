#include <ReadInput.h>

#include <stdio.h>
#include <stdlib.h>

char *readInput(void)
{
  char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
  char c = 0;

  size_t ctr = 0;
  while (c != '\n')
  {
    c = getchar();
    buffer[ctr++] = c;
  }
  buffer[ctr] = '\0';

  return buffer;
}
