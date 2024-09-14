#pragma once

#include <sstream>

class SwitchStdout
{
private:
  std::string filename;
  FILE *original_stdout;

public:
  SwitchStdout(std::string filename);
  int switch_stdout_to_file();
  void switch_stdout_to_console();
  std::string read_and_remove_file(bool removefile = true);
};
