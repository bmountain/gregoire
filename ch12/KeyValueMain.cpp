#include "KeyValuePair.h"
#include <iostream>
#include <print>
#include <string>

template <typename Key, typename Value>
void printAge(const KeyValuePair<Key, Value>& kv)
{
  std::println("{}: {}", kv.getKey(), kv.getValue());
}

int main()
{
  KeyValuePair kv{1, 3.14};
}