#include <fstream>
#include <iostream>
#include <unistd.h>

void test_function(void)
{
  printf("[test_function]: print test\n");
}

class SwitchStdout
{
private:
  FILE *original_stdout;

public:
  SwitchStdout()
  {
    this->original_stdout = fdopen(dup(fileno(stdout)), "w");
  }

  int switch_stdout_to_file(std::string file_name)
  {
    if (!freopen(file_name.c_str(), "w", stdout))
    {
      std::cout << "ERROR!" << std::endl;
      return -1;
    }
    return 0;
  }

  void switch_stdout_to_console(std::string file_name)
  {
  }
};

void print_file(std::string file_name)
{
  std::ifstream f(file_name);
  if (f.is_open())
  {
    std::cout << f.rdbuf();
  }
  else
  {
    std::cout << "Error opening the file!" << std::endl;
  }
}

int main(int argc, char const *argv[])
{
  // SwitchStdout switchStandout;
  // switchStandout.switch_stdout_to_file("temp_output.txt");

  FILE *original_stdout = fdopen(dup(fileno(stdout)), "w");
  if (!freopen("temp_output.txt", "w", stdout))
  {
    std::cout << "ERROR!" << std::endl;
    return -1;
  }

  // printf will now save in file "temp_output.txt"
  printf("Hello world!\n");
  std::cout << "Heeeey!" << std::endl;
  fprintf(stdout, "fprint\n");
  //

  fflush(stdout);
  dup2(fileno(original_stdout), fileno(stdout));
  fclose(original_stdout);

  print_file("temp_output.txt");

  return 0;
}
