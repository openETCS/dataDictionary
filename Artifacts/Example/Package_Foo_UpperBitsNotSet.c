
#include "Package_Foo_UpperBitsNotSet.h"
#include "Bit64.h"

int Package_Foo_UpperBitsNotSet(const Package_Foo* p)
{
  if (UpperBitsNotSet64(p->ABC, 8) &&
      UpperBitsNotSet64(p->DEF, 3) &&
      UpperBitsNotSet64(p->GHI, 17))
  {
     return 1;
  }
  else
  {
     return 0;
  }
}

