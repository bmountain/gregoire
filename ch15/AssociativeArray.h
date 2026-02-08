#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRAY_H
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class AssociativeArray
{
  struct Element
  {
    std::string key;
    T value;
  };

  using Data = std::vector<Element>;
  Data mData;

  const T& operator[](const std::string& key) const
  {
    auto it = find(key);
    if (it == mData.end()) {
      throw std::out_of_range("no such data.");
    }
    return it->value;
  }

  T& operator[](const std::string& s)
  {
    return const_cast<T&>(as_const(*this)[s]);
  }

  Data::iterator find(const std::string s)
  {
    return std::find_if(mData.begin(),
                        mData.end(),
                        [this, &s](const Element d)
                        {
                          return d.key == s;
                        });
  }

public:
  Data::iterator insert(std::string key, T value)
  {
    auto it = find(key);
    if (it == mData.end()) {
      mData.push_back(Element{std::move(key), std::move(value)});
      return mData.end() - 1;
    } else {
      return it;
    }
  }

  void print(std::ostream& os) const
  {
    for (const auto& e : mData) {
      os << "{" << e.key << " : " << e.value << "}\n";
    }
  }
};
#endif /* ASSOCIATIVE_ARRAY_H */