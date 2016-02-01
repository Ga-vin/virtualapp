#include <cassert>
#include <cstring>
#include "pieceworker.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

ostream &operator <<(ostream &out, const PieceWorker &worker)
{
  /*
    Todo
   */
  cout << "\n" << worker.getSecondName() << "."
       << worker.getFirstName()
       << "\nWage: " << worker.getWage()
       << "\nQuantity: " << worker.getQuantity();
  
  return out;
}

PieceWorker::PieceWorker(const char *first, const char *second, double wage, int quantity)
  :Employee(first, second)
{
  this->setWage(wage);
  this->setQuantity(quantity);
}

PieceWorker::PieceWorker(const PieceWorker &worker)
  :Employee(worker.getFirstName(), worker.getSecondName())
{
  this->setWage(worker.getWage());
  this->setQuantity(worker.getQuantity());
}

PieceWorker::~PieceWorker()
{
  
}

void PieceWorker::setWage(double wage)
{
  if (wage > 0 && wage != this->wage) {
    this->wage = wage;
  }
}

double PieceWorker::getWage() const
{
  return this->wage;
}

void PieceWorker::setQuantity(int quantity)
{
  if (quantity > 0 && this->quantity != quantity) {
    this->quantity = quantity;
  }
}

int PieceWorker::getQuantity() const
{
  return this->quantity;
}

PieceWorker &PieceWorker::operator =(const PieceWorker &worker)
{
  if (this != &worker) {
    if ((this->getFirstName() != worker.getFirstName())
	|| (this->getSecondName() != worker.getSecondName())
	|| (this->getWage() != worker.getWage())
	|| (this->getQuantity() != worker.getQuantity())) {
      this->setFirstName(worker.getFirstName());
      this->setSecondName(worker.getSecondName());
      this->setWage(worker.getWage());
      this->setQuantity(worker.getQuantity());
    }
  }

  return *this;
}

bool PieceWorker::operator ==(const PieceWorker &worker) const
{
  return ((this->getFirstName() == worker.getFirstName())
	  && (this->getSecondName() == worker.getSecondName())
	  && (this->getWage() == worker.getWage())
	  && (this->getQuantity() == worker.getQuantity()));
}

void PieceWorker::toString() const
{
  cout << "\nIn PieceWorker: ";
  Employee::toString();
  cout << "\nWage: " << this->getWage()
       << "\nQuantity: " << this->getQuantity() << endl;
}

double PieceWorker::earnings() const
{
  return this->getWage() * this->getQuantity();
}
