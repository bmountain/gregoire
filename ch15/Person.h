#ifndef PERSON_H
#define PERSON_H

#include <iostream>
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
  friend void swap(Person& lhs, Person& rhs) noexcept;
  friend std::ostream& operator<<(std::ostream& os, const Person& p);
  friend std::istream& operator>>(std::istream& is, Person& p);
  operator std::string() const;
  friend Person operator""_p(const char*, [[maybe_unused]] std::size_t len);

private:
  void swap(Person& other) noexcept;
  std::string firstName_;
  std::string lastName_;
};

Person operator""_p(const char*, [[maybe_unused]] std::size_t len);

#endif /* PERSON_H */