#include "hourlyworker.h"
#include <cassert>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

ostream &operator <<(ostream &out, const HourlyWorker &worker)
{
  /*
    Todo here
   */
  
  return out;
}

HourlyWorker::HourlyWorker(const char *ptr_first,
			   const char *ptr_last,
			   double wage,
			   double hours)
  :Employee(ptr_first, ptr_last)
{
  this->setWage(wage);
  this->setHours(hours);
}

HourlyWorker::HourlyWorker(const HourlyWorker &worker)
  :Employee(worker.getFirstName(), worker.getSecondName())
{
  this->setWage(worker.getWage());
  this->setHours(worker.getHours());
}

HourlyWorker::~HourlyWorker()
{
  
}

void HourlyWorker::setWage(double wage)
{
  assert(wage > 0.0);

  if (this->wage != wage) {
    this->wage = wage;
  }
}

void HourlyWorker::setHours(double hours)
{
  assert(hours > 0.0 && hours < 168.0);
  if (this->hours != hours) {
    this->hours = hours;
  }
}

double HourlyWorker::getWage() const
{
  return this->wage;
}

double HourlyWorker::getHours() const
{
  return this->hours;
}

double HourlyWorker::earnings() const
{
  if (this->getHours() <= 40) {
    return this->getWage() * this->getHours();
  } else {
    return 40 * this->getWage() + (this->getHours() - 40.0) * this->getWage() * 1.5;
  }
}

void HourlyWorker::toString() const
{
  cout << "In HourlyWorker: ";
  Employee::toString();
  cout << "Wage: " << this->getWage()
       << "\nHours: " << this->getHours()
       << "\nEarning: " << this->earnings() << endl;
}
