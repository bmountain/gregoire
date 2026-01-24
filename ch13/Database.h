#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"
#include <string_view>
#include <vector>

class Database
{
public:
  void add(const Person& person);
  void save(std::string_view dirName);
  void load(std::string_view dirName);
  void clear();
  void output(std::ostream& os = std::cout);

private:
  std::vector<Person> data_;
};

#endif /* DATABASE_H */