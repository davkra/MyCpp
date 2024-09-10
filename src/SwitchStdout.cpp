#include <SwitchStdout.hpp>

#include <fstream>
#include <iostream>
#include <unistd.h>

SwitchStdout::SwitchStdout(std::string filename)
{
  this->filename = filename;
  original_stdout = fdopen(dup(fileno(stdout)), "w");
}

int SwitchStdout::switch_stdout_to_file()
{
  if (!freopen(filename.c_str(), "w", stdout))
  {
    std::cout << "ERROR!" << std::endl;
    return -1;
  }
  return 0;
}

void SwitchStdout::switch_stdout_to_console()
{
  fflush(stdout);
  dup2(fileno(original_stdout), fileno(stdout));
  fclose(original_stdout);
}

std::string SwitchStdout::read_and_remove_file()
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
