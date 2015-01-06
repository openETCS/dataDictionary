
/*@
  predicate IsValidRange(int* a, integer n) =
    (0 <= n) && \valid(a+(0.. n-1));
*/

/*@
  predicate
    IsEqual{A,B}(int* a, integer n, int* b) =
      \forall integer i; 0 <= i < n ==>
        \at(a[i], A) == \at(b[i], B);
*/
