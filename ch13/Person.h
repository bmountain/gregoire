#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <ostream>
#include <string>

class Person
{
public:
  Person();
  Person(std::string firstName, std::string lastName);
  std::string getFirstName() const;
  std::string getLastName() const;
  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);
  friend void swap(Person& lhs, Person& rhs) noexcept
  {
    lhs.swap(rhs);
  }

  void output(std::ostream& os = std::cout) const;

private:
  void swap(Person& other) noexcept;
  std::string firstName_;
  std::string lastName_;
};

#endif /* PERSON_H */