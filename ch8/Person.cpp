#include "Person.h"
#include <utility>

class Person::Impl
{
public:
  Impl() = default;
  ~Impl() = default;
  Impl(std::string firstName, std::string lastName);
  Impl(const Impl& other);
  Impl& operator=(const Impl& other);
  Impl(Impl&& person) noexcept;
  Impl& operator=(Impl&& other) noexcept;
  std::string getFirstName() const;
  std::string getLastName() const;
  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);
  void swap(Impl& other) noexcept;

private:
  std::string firstName_ = "John";
  std::string lastName_ = "Doe";
};

Person::Impl::Impl(std::string firstName, std::string lastName)
: firstName_{std::move(firstName)}
, lastName_{std::move(lastName)}
{
}

Person::Impl::Impl(const Person::Impl& other)
: firstName_{other.firstName_}
, lastName_{other.lastName_}
{
}

Person::Impl& Person::Impl::operator=(const Person::Impl& other)
{
  Person::Impl tmp{other};
  swap(tmp);
  return *this;
}

Person::Impl::Impl(Person::Impl&& person) noexcept
{
  swap(person);
}

Person::Impl& Person::Impl::operator=(Person::Impl&& other) noexcept
{
  swap(other);
  return *this;
}

std::string Person::Impl::getFirstName() const
{
  return firstName_;
}
std::string Person::Impl::getLastName() const
{
  return lastName_;
}
void Person::Impl::setFirstName(std::string firstName)
{
  firstName_ = std::move(firstName);
}
void Person::Impl::setLastName(std::string lastName)
{
  lastName_ = std::move(lastName);
}

void Person::Impl::swap(Person::Impl& other) noexcept
{
  std::swap(firstName_, other.firstName_);
  std::swap(lastName_, other.lastName_);
}

Person::Person()
: impl_{std::make_unique<Person::Impl>()}
{
}
Person::~Person() = default;
Person::Person(std::string firstName, std::string lastName)
: impl_{std::make_unique<Impl>(firstName, lastName)}
{
}
Person::Person(const Person& other)
: impl_{std::make_unique<Impl>(*other.impl_)}
{
}
Person& Person::operator=(const Person& other)
{
  Person tmp{other};
  swap(tmp);
  return *this;
}
Person::Person(Person&& other) noexcept
: impl_{std::exchange(other.impl_, nullptr)}
{
}
Person& Person::operator=(Person&& other) noexcept
{
  impl_ = std::exchange(other.impl_, nullptr);
  return *this;
}

std::string Person::getFirstName() const
{
  return impl_->getFirstName();
}

std::string Person::getLastName() const
{
  return impl_->getLastName();
}

void Person::setFirstName(std::string firstName)
{
  impl_->setFirstName(firstName);
}

void Person::setLastName(std::string lastName)
{
  impl_->setLastName(lastName);
}

void Person::swap(Person& other) noexcept
{
  std::swap(impl_, other.impl_);
}