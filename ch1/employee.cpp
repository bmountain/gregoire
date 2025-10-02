#include "employee.h"
#include <array>
#include <print>
#include <vector>

using namespace std;
using namespace HR;

void printEmployee(Employee);

int main()
{
  using enum Title;
  Employee emp1 = {.firstName = "John", .lastName = "Doe", .employeeNumber = 42, .salary = 80000, .title = Manager};
  Employee emp2 = {.firstName = "Taro", .lastName = "Taro", .employeeNumber = 1, .salary = 100, .title = Engineer};

  array<Employee, 2> empArray{emp1, emp2};
  println("Printing array...\n");
  for (const auto& emp : empArray) {
    printEmployee(emp);
  }

  vector<Employee> empVector;
  empVector.push_back(emp1);
  empVector.push_back(emp2);
  println("Printing vector...\n");
  for (const auto& emp : empVector) {
    printEmployee(emp);
  }
}

void printEmployee(Employee emp)
{
  using enum Title;
  println("Employee {} {}", emp.firstName, emp.lastName);
  println("Number: {}", emp.employeeNumber);
  println("Salary: {}", emp.salary);

  string title;
  switch (emp.title) {
  case Manager:
    title = "Manager";
    break;
  case SeniorEngineer:
    title = "Senior Manager";
    break;
  case Engineer:
    title = "Engineer";
    break;
  default:
    throw runtime_error{"Unknown title"};
  }
  println("Title: {}", title);
  println("");
}