#include "Database.h"
#include "Person.h"
#include <fstream>
#include <print>

int main()
{
  Database db;
  // Person john = {"John", "Doh"};
  // Person hanako = {"Hanako", "Yamada"};
  // db.add(john);
  // db.add(hanako);
  // db.save("db");
  db.load("db");
  db.output();
}