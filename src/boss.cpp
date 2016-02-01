#include <cassert>
#include <cstring>
#include "boss.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

ostream &operator <<(ostream &out, const Boss &boss)
{
  /*
    Todo
   */
  cout << boss.getSecondName() << "." << boss.getFirstName() <<
    " Earning: " << boss.getWeeklySalary();
  
  return out;
}

Boss::Boss(const char *first, const char *second, double salary)
  :Employee(first, second)
{
  this->setWeeklySalary(salary);
}

Boss::Boss(const Boss &boss)
  :Employee(boss.getFirstName(), boss.getSecondName())
{
  this->setWeeklySalary(boss.getWeeklySalary());
}

Boss::~Boss()
{
  
}

void Boss::setWeeklySalary(double salary)
{
  assert(salary > 0.0);

  this->salary = salary;
}

double Boss::getWeeklySalary() const
{
  return this->salary;
}

double Boss::earnings() const
{
  return this->salary;
}

void Boss::toString() const
{
  cout << "\nBoss: ";
  Employee::toString();
  cout << " Earning: " << this->getWeeklySalary() << endl;
}
