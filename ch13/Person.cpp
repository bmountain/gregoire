#include "Person.h"
#include <print>

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

void Person::output(std::ostream& os) const
{
  std::println(os, "{} {}", getFirstName(), getLastName());
}