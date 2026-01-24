#ifndef PERSON_H
#define PERSON_H

#include <memory>
#include <print>
#include <string>

class Person
{
public:
  Person();
  ~Person();
  Person(std::string firstName, std::string lastName);
  Person(const Person& other);
  Person& operator=(const Person& other);
  Person(Person&& person) noexcept;
  Person& operator=(Person&& other) noexcept;

  std::string getFirstName() const;
  std::string getLastName() const;
  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);

  void swap(Person& other) noexcept;

private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

#endif /* PERSON_H */