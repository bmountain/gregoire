#include "Person.h"
#include <print>
#include <sstream>

Person::Person()
: firstName_{""}
, lastName_{""}
{
}

Person::Person(std::string firstName, std::string lastName)
: firstName_{std::move(firstName)}
, lastName_{std::move(lastName)}
{
}

std::string Person::getFirstName() const
{
  return firstName_;
}

std::string Person::getLastName() const
{
  return lastName_;
}

void Person::setFirstName(std::string firstName)
{
  firstName_ = std::move(firstName);
}

void Person::setLastName(std::string lastName)
{
  lastName_ = std::move(lastName);
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
  os << p.getFirstName() << " " << p.getLastName();
  return os;
}

std::istream& operator>>(std::istream& is, Person& p)
{
  is >> p.firstName_ >> p.lastName_;
  while (is) {
    std::string tmp;
    is >> tmp;
    p.lastName_ += " " + tmp;
  }
  return is;
}

void Person::swap(Person& rhs) noexcept
{
  std::swap(firstName_, rhs.firstName_);
  std::swap(lastName_, rhs.lastName_);
}

void swap(Person& lhs, Person& rhs) noexcept
{
  lhs.swap(rhs);
}

Person::operator std::string() const
{
  return firstName_ + " " + lastName_;
}

Person operator""_p(const char* name, [[maybe_unused]] std::size_t len)
{
  std::istringstream is{name};
  Person p;
  is >> p;
  return p;
}