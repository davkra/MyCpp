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
  std::string filename;
  FILE *original_stdout;

public:
  SwitchStdout(std::string filename)
  {
    this->filename = filename;
    original_stdout = fdopen(dup(fileno(stdout)), "w");
  }

  int switch_stdout_to_file()
  {
    if (!freopen(filename.c_str(), "w", stdout))
    {
      std::cout << "ERROR!" << std::endl;
      return -1;
    }
    return 0;
  }

  void switch_stdout_to_console()
  {
    fflush(stdout);
    dup2(fileno(original_stdout), fileno(stdout));
    fclose(original_stdout);
  }

  std::string read_and_remove_file()
  {
    std::ifstream f(filename);
    if (f.is_open())
    {
      std::stringstream buffer;
      buffer << f.rdbuf();
      remove(filename.c_str());

      return buffer.str();
    }
    else
    {
      std::cout << "Error opening the file!" << std::endl;
      return nullptr;
    }
  }
};

int main(int argc, char const *argv[])
{
  SwitchStdout switchStandout("temp_output.txt");
  switchStandout.switch_stdout_to_file();

  // ====================================================================

  printf("Hello world!\n");
  std::cout << "Heeeey!" << std::endl;
  fprintf(stdout, "fprint\n");

  // ====================================================================

  switchStandout.switch_stdout_to_console();
  std::string output = switchStandout.read_and_remove_file();

  std::cout << output;

  return 0;
}
