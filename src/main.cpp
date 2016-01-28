#include <iostream>
#include "employee.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

/* ============================================================ */
#define    SELFTEST    0
#define    EMPLOYEE    1
/* ============================================================ */

/* ============================================================ */
void selfTestApp(void);
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
#endif
  return 0;
}

void
selfTestApp(void)
{
  cout << "It is running..." << endl;
}
