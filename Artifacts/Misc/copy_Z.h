
#include "Predicates_Z.h"

/*@
  requires IsValidRange_Z(a, n);
  requires IsValidRange_Z(b, n);
  requires \separated(a+(0..n-1), b+(0..n-1));

  assigns b[0..n-1];

  ensures IsEqual_Z{Here,Old}(a, n, a);
  ensures IsEqual_Z{Here,Here}(a, n, b);
*/
void copy_Z(const Z* a, const unsigned int n, Z* b);
