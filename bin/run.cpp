#include <iostream>
#include <string.h>

#include <print.hpp>
#define ALWAYS                                                                 \
  "clear && cmake . && make && echo "                                          \
  " && "

using my::print;

int main(int argc, char const *argv[])
{
  std::string str(ALWAYS);

  print("argc: ", argc);

  for (int ctr = 0; ctr < argc; ctr++)
  {
    print("argv[", ctr, "]:", argv[ctr]);
  }

  if (argc == 2)
  {
    print("Case 1");

    str.append(argv[1]);
    print(str);
    std::system(str.c_str());
    return 0;
  }
  else if ((argc == 3) && (strcmp(argv[2], "valgrind") == 0))
  {
    print("Case 2");

    std::string str("valgrind ");
    str.append(argv[1]);
    print(str);
    std::system(str.c_str());
    return 0;
  }
  else
  {
    print("Case 3");

    print("Error!");
    exit(EXIT_FAILURE);

    return 0;
  }
}