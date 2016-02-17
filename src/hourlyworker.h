#ifndef __EX_HOURLYWORKER_H_
#define __EX_HOURLYWORKER_H_

#include "employee.h"
#include <iostream>

using std::ostream;

class HourlyWorker : public Employee {
  friend ostream &operator <<(ostream &out, const HourlyWorker &worker);

 public:
  HourlyWorker(const char *ptr_first, const char *ptr_last,
	       double wage = 0.0, double hours = 0.0);
  HourlyWorker(const HourlyWorker &worker);
  ~HourlyWorker();

  void   setWage(double wage);
  double getWage() const;
  void   setHours(double hours);
  double getHours() const;

  virtual double earnings() const;
  virtual void   toString() const;

 private:
  double wage;
  double hours;
};

#endif /* __EX_HOURLYWORKER_H_ */
