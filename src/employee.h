#ifndef __EX_EMPLOYEE_H
#define __EX_EMPLOYEE_H

#include <iostream>

using std::ostream;

class Employee {
  friend ostream &operator <<(ostream &out, const Employee &emp);

 public:
  Employee(const char *first, const char *second);
  Employee(const Employee &emp);
  ~Employee();

  const char *getFirstName() const;
  const char *getSecondName() const;
  void        setFirstName(const char *first);
  void        setSecondName(const char *second);
  void        toString() const;

  Employee &operator  =(const Employee &emp);

  bool operator ==(const Employee &emp) const;
  bool operator !=(const Employee &emp) const {return !(this == &emp);}

 private:
  char *first_name;
  char *last_name;
};

#endif /* __EX_EMPOYEE_H */
