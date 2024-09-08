#include <cstdio>
#include <string>

int main() {
  char buffer[100];
  int value = 42;
  snprintf(buffer, sizeof(buffer), "The value is: %d", value);
  std::string result(buffer);
  printf("Result: %s\n", result.c_str());
  return 0;
}
