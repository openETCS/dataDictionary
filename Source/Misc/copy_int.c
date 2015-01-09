
#include "copy_int.h"

void copy_int(const int* a, unsigned int n, int* b)
{
    /*@
      loop invariant 0 <= i <= n;
      loop invariant IsEqual{Here,Here}(a, i, b);
      loop assigns   i, b[0..n-1];
      loop variant n-i;
    */
    for (unsigned int i = 0; i < n; ++i)
    {
        b[i] = a[i];
    }
}
