#include <iostream>
#include <string.h>

#include <print.hpp>

using my::print;

int main(int argc, char const *argv[])
{
  if (argc == 2)
  {
    std::system(argv[1]);
    return 0;
  }
  else if ((argc == 3) && (strcmp(argv[2], "valgrind") == 0))
  {
    std::string str("valgrind ");
    str.append(argv[1]);

    std::system(str.c_str());
    return 0;
  }
  else
  {
    print("Error!");
    exit(EXIT_FAILURE);

    return 0;
  }
}