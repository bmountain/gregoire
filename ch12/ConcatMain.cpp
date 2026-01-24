#include "Concat.h"
#include <print>

int main()
{
  double f = 3.14;
  int s = 1592;
  std::println("{}", concat(f, s));

  const char* f2 = "hoge";
  std::string s2 = "fuga";
  std::println("{}", concat(f2, s2));
}