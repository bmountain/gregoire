#include "Database.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>
#include <sstream>

using std::filesystem::create_directory;
using std::filesystem::directory_entry;
using std::filesystem::directory_iterator;
using std::filesystem::path;

void Database::add(const Person& person)
{
  data_.push_back(person);
}

void Database::save(std::string_view dirName)
{
  path p{dirName};
  directory_entry dir{p};
  if (!dir.exists()) { // 存在しなければ作成する
    create_directory(p);
  } else if (!dir.is_directory()) { // 存在するがファイルである
    std::println(std::cerr, "Error: file {} exists.", dirName);
    exit(1);
  }

  for (const auto& person : data_) {
    std::string fileName = person.getFirstName() + '_' + person.getLastName() + ".person";
    path filePath{p};
    filePath /= fileName;
    directory_entry file{filePath};
    if (file.is_directory()) {
      std::println(std::cerr, "Error: directory {} exists.", filePath.string());
      exit(1);
    } else if (file.exists()) {
      std::println("Warning: file {} will be overwritten.", filePath.string());
    }

    std::ofstream os{filePath};
    std::println(os, "{},{}", person.getFirstName(), person.getLastName());
  }
}

void Database::load(std::string_view dirName)
{
  data_.clear();
  path dirPath{dirName};
  directory_entry dir{dirPath};
  if (!dir.exists() || !dir.is_directory()) {
    std::println(std::cerr, "Error: directory {} not found.", dirPath.string());
  }

  for (auto& file : directory_iterator{dirPath}) {
    if (!(file.path().extension() == ".person") || !file.is_regular_file()) {
      continue;
    }

    std::ifstream is{file.path()};
    std::string firstName, lastName;
    getline(is, firstName, ',');
    getline(is, lastName);
    add(Person{firstName, lastName});
  }
}

void Database::clear()
{
  data_.clear();
}

void Database::output(std::ostream& os)
{
  for (const auto& person : data_) {
    person.output(os);
  }
}
