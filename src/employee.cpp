#include <iostream>
#include <cassert>
#include <cstring>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

ostream &operator <<(ostream &out, const Employee &emp)
{
  /*
    Todo
   */
  return out;
}

Employee::Employee(const char *first, const char *second)
{
  
}

Employee::Employee(const Employee &emp)
{
  
}

Employee::~Employee()
{
  
}

const char *Employee::getFirstName() const
{
  return this->first_name;
}

const char *Employee::getSecondName() const
{
  return this->second_name;
}

void Employee::setFirstName(const char *first)
{
  
}

void Employee::setSecondName(const char *second)
{
  
}

Employee &Employee::operator =(const Employee &emp)
{
  
}

Employee &Employee::operator +=(const Employee &emp)
{
  
}
