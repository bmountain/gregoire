#ifndef CONCAT_H
#define CONCAT_H

#include <concepts>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T>
concept StringLike = requires(T x) { std::to_string(x); } || std::is_convertible_v<T, std::string> || std::convertible_to<T, std::string_view>;

template <StringLike T>
std::string force_to_string(const T& x)
{
  if constexpr (requires { std::to_string(x); }) {
    return std::to_string(x);
  } else {
    return x;
  }
}

decltype(auto) concat(const StringLike auto& first, const StringLike auto& second)
{
  return force_to_string(first) + force_to_string(second);
}

#endif /* CONCAT_H */