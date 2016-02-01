#ifndef __EX_PIECEWORKER_H_
#define __EX_PIECEWORKER_H_

#include <iostream>
#include "employee.h"

using std::ostream;

class PieceWorker : public Employee {
  friend ostream &operator <<(ostream &out, const PieceWorker &worker);

 public:
  PieceWorker(const char *first, const char *second, double wage, int quantity);
  PieceWorker(const PieceWorker &worker);
  ~PieceWorker();

  void   setWage(double wage);
  double getWage() const;
  void   setQuantity(int quantity);
  int    getQuantity() const;

  PieceWorker &operator =(const PieceWorker &worker);
  bool operator ==(const PieceWorker &worker) const;
  bool operator !=(const PieceWorker &worker) const {return !(*this == worker);}

  virtual void   toString() const;
  virtual double earnings() const;

 private:
  double wage;
  int    quantity;
};

#endif /* __EX_PIECEWORKER_H_ */
