#include "Person.h"
#include <iostream>
#include <print>

int main()
{
  auto p = "Peter Van Weert"_p;
  std::println("{}", p.getFirstName());
  std::println("{}", p.getLastName());
}