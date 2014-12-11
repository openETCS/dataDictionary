
#include "Predicates.h"

/*@
  requires IsValidRange(a, n);
  requires IsValidRange(b, n);
  requires \separated(a+(0..n-1), b+(0..n-1));

  assigns b[0..n-1];

  ensures IsEqual{Here,Old}(a, n, a);
  ensures IsEqual{Here,Here}(a, n, b);
*/
void copy_int(const int* a, const unsigned int n, int* b);
