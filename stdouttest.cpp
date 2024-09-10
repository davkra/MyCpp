#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

void test_function(void)
{
  printf("[test_function]: print test\n");
}

int main(int argc, char const *argv[])
{
  std::cout << "Debug Test" << std::endl;

  // Backup original stdout
  FILE *original_stdout = fdopen(dup(fileno(stdout)), "w");

  if (freopen("temp_output.txt", "w", stdout))
  {
    printf("Hello world!\n");

    // Flush the output to the file, but don't close stdout
    fflush(stdout);

    // Restore stdout to the original stream
    dup2(fileno(original_stdout), fileno(stdout));
    fclose(original_stdout); // Close the copy of stdout
  }
  else
  {
    std::cout << "ERROR!" << std::endl;
    return -1;
  }

  // Read and print the file content
  std::ifstream f("temp_output.txt");
  if (f.is_open())
  {
    std::cout << "file is open" << std::endl;
    std::cout << f.rdbuf();
  }
  else
  {
    std::cerr << "Error opening the file!" << std::endl;
  }

  // Now printf and cout will work again
  return 0;
}
