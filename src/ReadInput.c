#include <ReadInput.h>

#include <stdio.h>
#include <stdlib.h>

void checkIfNull(void *ptr)
{
  if (ptr == NULL)
  {
    perror("Out of memory!");
    exit(EXIT_FAILURE);
  }
}

char *readInput(void)
{
  char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
  checkIfNull(buffer);

  size_t ctr = 0;
  char c = 0;
  while (c != '\n')
  {
    c = getchar();
    buffer[ctr++] = c;
  }
  buffer[ctr] = '\0';

  return buffer;
}

char *dynamicReadInput(void)
{
  size_t buffer_size = BUFFER_SIZE;
  char *buffer = (char *)calloc(buffer_size, sizeof(char));
  checkIfNull(buffer);

  size_t ctr = 0;
  char c = 0;
  while (c != EOF && c != '\n')
  {
    c = getchar();
    buffer[ctr++] = c;
    if (ctr >= buffer_size)
    {
      buffer_size *= 2;
      buffer = (char *)realloc(buffer, buffer_size);
      checkIfNull(buffer);
    }
  }
  buffer[ctr] = '\0';

  return buffer;
}
