
#include "copy_Z.h"

void copy_Z(const Z* a, unsigned int n, Z* b)
{
  /*@
    loop invariant 0 <= i <= n;
    loop invariant IsEqual_Z{Here,Here}(a, i, b);
    loop assigns   i, b[0..n-1];
    loop variant n-i;
  */
  for (unsigned int i = 0; i < n; ++i)
  {
    b[i] = a[i];
  }
}
