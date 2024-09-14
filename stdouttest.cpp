#include <iostream>

#include <SwitchStdout.hpp>
#include <print.hpp>

using my::print;

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

  print(2, "Hello", true, false, 2.3, 'a');

  // ====================================================================

  switchStandout.switch_stdout_to_console();
  std::string output = switchStandout.read_and_remove_file();

  std::cout << output;

  return 0;
}
