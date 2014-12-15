
#include "Z.h"

/*@
  predicate IsValidRange_Z(Z* a, integer n) =
    (0 <= n) && \valid(a+(0.. n-1));
*/

/*@
  predicate
    IsEqual_Z{A,B}(Z* a, integer n, Z* b) =
      \forall integer i; 0 <= i < n  ==>  \at(a[i], A) == \at(b[i], B);
*/
