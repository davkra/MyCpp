#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sstream>

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
    fflush(stdout);
    dup2(fileno(original_stdout), fileno(stdout));
    fclose(original_stdout);
  }
};

void switch_stdout_to_console(FILE *original_stdout)
{
  fflush(stdout);
  dup2(fileno(original_stdout), fileno(stdout));
  fclose(original_stdout);
}

std::string read_and_remove_file(std::string file_name)
{
  std::ifstream f(file_name);
  if (f.is_open())
  {
    std::stringstream buffer;
    buffer << f.rdbuf();
    remove(file_name.c_str());

    return buffer.str();
  }
  else
  {
    std::cout << "Error opening the file!" << std::endl;
    return nullptr;
  }
}

int main(int argc, char const *argv[])
{
  // SwitchStdout switchStandout;
  // switchStandout.switch_stdout_to_file("temp_output.txt");

  FILE *original_stdout = fdopen(dup(fileno(stdout)), "w");
  std::string filename = "temp_output.txt";

  if (!freopen(filename.c_str(), "w", stdout))
  {
    std::cout << "ERROR!" << std::endl;
    return -1;
  }

  // printf will now save in file "temp_output.txt"
  printf("Hello world!\n");
  std::cout << "Heeeey!" << std::endl;
  fprintf(stdout, "fprint\n");
  //

  switch_stdout_to_console(original_stdout);

  // save "temp_output.txt" in string
  std::string output = read_and_remove_file("temp_output.txt");

  // string can be changed or printed
  std::cout << output;

  return 0;
}
