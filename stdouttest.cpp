#include <iostream>

#include <SwitchStdout.hpp>

void test_function(void)
{
  printf("[test_function]: print test\n");
}

int main(int argc, char const *argv[])
{
  SwitchStdout switchStandout("temp_output.txt");
  switchStandout.switch_stdout_to_file();

  // ====================================================================

  printf("Hello world!\n");
  std::cout << "Hello stdout!" << std::endl;
  fprintf(stdout, "fprint\n");

  test_function();

  // ====================================================================

  switchStandout.switch_stdout_to_console();
  std::string output = switchStandout.read_and_remove_file();

  std::cout << output;

  return 0;
}
