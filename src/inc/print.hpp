#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace my
{
void hello(void);
void printf(string str);

// base case to end recursion
template <typename T> void print(const T &first)
{
  cout << first << endl;
}

template <typename T, typename... Args>
void print(const T &first, const Args &...args)
{
  cout << first << " ";
  print(args...);
}

} // namespace my
