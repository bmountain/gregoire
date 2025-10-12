#include <algorithm>
#include <iostream>
#include <print>
#include <vector>
using namespace std;

int main()
{
  println("Enter two strings: ");
  vector<string> v;
  for (int i = 0; i < 2; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  println("{:=^10}", "Sorted");
  std::sort(v.begin(), v.end());
  for (const auto& str : v) {
    std::println("{}", str);
  }
}