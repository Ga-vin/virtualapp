#ifndef __EX_BOSS_H
#define __EX_BOSS_H

#include <iostream>
#include "employee.h"

using std::ostream;

class Boss : public Employee {
  friend ostream &operator <<(ostream &out, const Boss &boss);

 public:
  Boss(const char *first, const char *second, double earning);
  Boss(const Boss &boss);
  ~Boss();

  void setWeeklySalary(double salary);
  double getWeeklySalary() const;

  virtual double earnings() const;
  virtual void   toString() const;

 private:
  double salary;
};

#endif /* __EX_BOSS_H */
