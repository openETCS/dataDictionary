
#include "BitsFramaC.h"

/*@
    assigns \nothing;
    ensures \forall integer i; 0 <= i < 32 ==> !BitTest(\result,i);
*/
uint32_t example1()
{
  return 0u;
}

/*@
    assigns \nothing;
    ensures BitTest(\result, 3);
*/
uint32_t example2()
{
  uint32_t a = 1u << 3u;
  return a;
}

