#include "Person.h"
#include <print>

void sayHello(const Person& person);

int main()
{
  Person taro{"Taro", "Tanaka"};
  sayHello(taro);
  taro.setFirstName("Jiro");
  sayHello(taro);
}

void sayHello(const Person& person)
{
  std::println("Hello, {} {}", person.getFirstName(), person.getLastName());
}