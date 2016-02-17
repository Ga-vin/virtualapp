#include <iostream>
#include "employee.h"
#include <iomanip>
#include "boss.h"
#include "commis.h"
#include "hourlyworker.h"
#include "pieceworker.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ios;
using std::setiosflags;
using std::setprecision;

/* ============================================================ */
#define    SELFTEST    0
#define    EMPLOYEE    0
#define    COMPLEX     1
/* ============================================================ */

/* ============================================================ */
void selfTestApp(void);
void virtualViaPointer(const Employee *ptr);
void virtualViaReference(const Employee &ref);
/* ============================================================ */

int
main(int argc, char *argv[])
{
#if    1 == SELFTEST
  selfTestApp();
#elif  1 == EMPLOYEE
  Employee emp("Bai", "Gavin"), emp2("Wang", "Chunxi");

  cout << "#Using first: " << emp << endl;
  cout << "#Using second: " << emp2 << endl;

  emp = emp2;
  cout << "#Using = first: " << emp << endl;
  cout << "#Using = second: " << emp2 << endl;

  cout << (emp == emp2 ? "True" : "False") << endl;
  cout << (emp != emp2 ? "True" : "False") << endl;
#elif 1 == COMPLEX
  /* Set output formatting */
  cout << setiosflags(ios::fixed | ios::showpoint);
  cout << setprecision(2);

  Boss b("John", "Smith", 800.00);
  b.toString();
  cout << "earned $ " << b.earnings() << endl;
  virtualViaPointer(&b);
  virtualViaReference(b);

  
#endif
  
  return 0;
}

void
selfTestApp(void)
{
  cout << "It is running..." << endl;
}

void virtualViaPointer(const Employee *ptr_base_class)
{
  ptr_base_class->toString();
  cout << "earned $ " << ptr_base_class->earnings();
}

void virtualViaReference(const Employee &ref_base_class)
{
  ref_base_class.toString();
  cout << "earned $ " << ref_base_class.earnings();
}
