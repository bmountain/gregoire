#include <algorithm>
#include <iostream>
#include <numeric>
#include <print>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> vec;
  std::string word{""};
  while (std::cin >> word) {
    if (word == "*") {
      break;
    }
    vec.push_back(word);
  }

  const int numcol = 5;
  std::vector<std::vector<std::string>> columns(numcol);
  for (size_t i = 0; i != vec.size(); ++i) {
    columns[i % numcol].push_back(vec[i]);
  }

  std::vector<int> length(numcol);
  for (size_t i = 0; i != numcol; ++i) {
    length[i] = std::max_element(columns[i].begin(), columns[i].end(),
                                 [](std::string left, std::string right)
                                 {
                                   return left.size() < right.size();
                                 })
                    ->size();
  }

  std::vector<std::vector<std::string>::iterator> iterators, ends;
  for (auto& column : columns) {
    iterators.emplace_back(column.begin());
    ends.emplace_back(column.end());
  }

  while (iterators != ends) {
    for (int i = 0; i != numcol; ++i) {
      std::string word;
      if (iterators[i] == ends[i]) {
        word = "";
      } else {
        word = *iterators[i];
        iterators[i]++;
      }
      std::print("{:^{}}", word, length[i]);
      if (i != numcol - 1) {
        std::print("|");
      }
    }
    std::println("");
  }
}