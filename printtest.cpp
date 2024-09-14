#include <iostream>

namespace my
{
void for_each()
{
}

template <typename T, typename... Args>
void for_each(const T &first, const Args &...args)
{
  std::cout << first << std::endl;
  for_each(args...);
}
} // namespace my

int main()
{
  my::for_each(2, "Hello", 123, 45.67, 'A', true);

  return 0;
}