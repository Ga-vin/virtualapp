#include <cassert>
#include <cstring>
#include "commis.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

ostream &operator <<(ostream &out, const Commis &comm)
{
  /*
    Todo 
   */

  return out;
}

Commis::Commis(const char *first, const char *second, double salary, double commission, int quantity)
  :Employee(first, second)
{
  this->setSalary(salary);
  this->setCommission(commission);
  this->setQuantity(quantity);
}

Commis::Commis(const Commis &comm)
  :Employee(comm.getFirstName(), comm.getSecondName())
{
  this->setSalary(comm.getSalary());
  this->setCommission(comm.getCommission());
  this->setQuantity(comm.getQuantity());
}

Commis::~Commis()
{
  
}

void Commis::setSalary(double salary)
{
  assert(salary >= 0);

  if (this->salary != salary) {
    this->salary = salary;
  }
}

double Commis::getSalary() const
{
  return this->salary;
}

void Commis::setCommission(double commission)
{
  assert(commission >= 0);

  if (this->commission != commission) {
    this->commission = commission;
  }
}

double Commis::getCommission() const
{
  return this->commission;
}

int Commis::getQuantity() const
{
  return this->quantity;
}

void Commis::setQuantity(int quantity)
{
  assert(quantity >= 0);

  if (this->quantity != quantity) {
    this->quantity = quantity;
  }
}

Commis &Commis::operator =(const Commis &comm)
{
  if (this != &comm) {
    if ((0 != strcmp(this->getFirstName(), comm.getFirstName())) ||
	(0 != strcmp(this->getSecondName(), comm.getSecondName())) ||
	(this->getSalary() != comm.getSalary()) ||
	(this->getCommission() != comm.getCommission()) ||
	(this->getQuantity() != comm.getQuantity())) {
      this->setFirstName(comm.getFirstName());
      this->setSecondName(comm.getSecondName());
      this->setSalary(comm.getSalary());
      this->setCommission(comm.getCommission());
      this->setQuantity(comm.getQuantity());
    }
  }

  return *this;
}

bool Commis::operator ==(const Commis &comm) const
{
  return ((this->getFirstName() == comm.getFirstName())
	  && (this->getSecondName() == comm.getSecondName())
	  && (this->getSalary() == comm.getSalary())
	  && (this->getCommission() == comm.getCommission())
	  && (this->getQuantity() == comm.getQuantity()));
}

void Commis::toString() const
{
  cout << "\nIn Commis: ";
  Employee::toString();
  cout << "\nSalary: " << this->getSalary()
       << "\nCommission: " << this->getCommission()
       << "\nQuantity: " << this->getQuantity() << endl;
}

double Commis::earnings() const
{
  return this->getSalary() + this->getCommission() * this->getQuantity();
}
