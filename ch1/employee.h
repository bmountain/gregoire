#ifndef EMPLOYEE__H
#define EMPLOYEE__H
#include <string>

namespace HR
{

enum class Title
{
  Manager,
  SeniorEngineer,
  Engineer
};

struct Employee
{
  std::string firstName;
  std::string lastName;
  int employeeNumber;
  int salary;
  Title title;
};

} // namespace HR

#endif /* EMPLOYEE__H */