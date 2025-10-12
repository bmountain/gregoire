#include <iostream>
#include <print>
#include <string>
#include <string_view>

std::string replace_one(std::string haystack, std::string_view needle, std::string_view sub)
{
  auto pos = haystack.find(needle);
  if (pos == std::string::npos) {
    return std::string{haystack};
  }
  return std::string{haystack.substr(0, pos) + std::string{sub} + haystack.substr(pos + needle.size())};
}

std::string replace_all(std::string haystack, std::string_view needle, std::string_view sub)
{
  size_t pos = 0;
  while ((pos = haystack.find(needle)) != std::string_view::npos) {
    haystack = haystack.substr(0, pos) + std::string{sub} + haystack.substr(pos + needle.size());
  }
  return std::string{haystack};
}

int main()
{
  std::string haystack, needle, sub;
  std::cin >> haystack >> needle >> sub;
  std::println("{}", replace_all(haystack, needle, sub));
}