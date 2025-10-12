#include <iostream>
#include <print>
#include <vector>

int main()
{
  std::vector<double> vec;
  double val;
  while (std::cin >> val) {
    if (val == 0) {
      break;
    }
    vec.push_back(val);
  }

  std::println("{:^8}|{:^8}|{:^8}", ":8e", ":8f", ":8a");
  std::println("{:=>26}", "");
  for (const auto& value : vec) {
    std::println("{0:^8.1e}| {0:^8.5f}| {0:^8.4a}", value);
  }
}