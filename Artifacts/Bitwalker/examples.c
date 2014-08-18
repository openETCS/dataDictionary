

#include "stdint.h"
#include "stdlib.h"
#include "Bits.h"


/*@
    assigns \nothing;
    ensures \forall integer i; 0 <= i < 32 ==> !BitTest(\result,i);
*/
unsigned int example1()
{
  return 0u;
}

/*@
    assigns \nothing;
    ensures BitTest(\result, 3);
*/
unsigned int example2()
{
  unsigned int a = 1u << 3u;
  return a;
}

