#ifndef __EX_COMMIS_H
#define __EX_COMMIS_H

#include <iostream>
#include "employee.h"

using std::ostream;

class Commis : public Employee {
  friend ostream &operator <<(ostream &out, const Commis &comm);

 public:
  Commis(const char *first, const char *second, double salary, double commission, int quantity);
  Commis(const Commis &comm);
  ~Commis();

  void   setSalary(double salary);
  double getSalary() const;
  void   setCommission(double commission);
  double getCommission() const;
  void   setQuantity(int quantity);
  int    getQuantity() const;

  Commis &operator  =(const Commis &comm);
  bool    operator ==(const Commis &comm) const;
  bool    operator !=(const Commis &comm) const {return !(*this == comm);}
  virtual void   toString() const;
  virtual double earnings() const;

 private:
  double salary;
  double commission;
  int    quantity;
};

#endif /* __EX_COMMIS_H */
