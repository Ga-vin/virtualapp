#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

/* ============================================================ */
#define    SELFTEST    1
/* ============================================================ */

/* ============================================================ */
void selfTestApp(void);
/* ============================================================ */

int
main(int argc, char *argv[])
{
#if    1 == SELFTEST
  selfTestApp();
#endif
  return 0;
}

void
selfTestApp(void)
{
  cout << "It is running..." << endl;
}
