
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
    /*@
        assigns b[i];
        ensures b[i] == \old(a[i]);
        ensures \forall integer k; 0 <= k < i ==> a[k] == \old(a[k]);
        ensures \forall integer k; 0 <= k < i ==> b[k] == \old(b[k]);
    */
    b[i] = a[i];
  }
}
