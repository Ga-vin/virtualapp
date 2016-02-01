#include <iostream>
#include <cassert>
#include <cstring>
#include "employee.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

ostream &operator <<(ostream &out, const Employee &emp)
{
  /*
    Todo
   */
  cout << emp.getSecondName() << "." << emp.getFirstName();
  return out;
}

Employee::Employee(const char *first, const char *second)
{
  this->setFirstName(first);
  this->setSecondName(second);
}

Employee::Employee(const Employee &emp)
{
  this->setFirstName(emp.getFirstName());
  this->setSecondName(emp.getSecondName());
}

Employee::~Employee()
{
  delete [] this->first_name;
  delete [] this->last_name;

  this->first_name = 0;
  this->last_name  = 0;
}

const char *Employee::getFirstName() const
{
  return this->first_name;
}

const char *Employee::getSecondName() const
{
  return this->last_name;
}

void Employee::setFirstName(const char *first)
{
  assert(0 != strcmp(first, ""));

  this->first_name = new char[strlen(first) + 1];
  strcpy(this->first_name, first);
  this->first_name[strlen(first)] = '\0';
}

void Employee::setSecondName(const char *second)
{
  assert(0 != strcmp(second, ""));

  this->last_name = new char[strlen(second) + 1];
  strcpy(this->last_name, second);
  this->last_name[strlen(second)] = '\0';
}

Employee &Employee::operator =(const Employee &emp)
{
  if (this != &emp) {
    if (0 != strcmp(this->getFirstName(), emp.getFirstName())) {
      delete [] this->first_name;
      this->first_name = new char[strlen(emp.getFirstName()) + 1];
      strcpy(this->first_name, emp.getFirstName());
      this->first_name[strlen(emp.getFirstName())] = '\0';
    }

    if (0 != strcmp(this->getSecondName(), emp.getSecondName())) {
      delete [] this->last_name;
      this->last_name = new char[strlen(emp.getSecondName()) + 1];
      strcpy(this->last_name, emp.getSecondName());
      this->last_name[strlen(emp.getSecondName())] = '\0';
    }
  }

  return *this;
}

bool Employee::operator ==(const Employee &emp) const
{
  return ((0 == strcmp(this->getFirstName(), emp.getFirstName())) &&
	  (0 == strcmp(this->getSecondName(), emp.getSecondName())));
}

void Employee::toString() const
{
  cout << this->getSecondName() << "." << this->getFirstName() << endl;
}
