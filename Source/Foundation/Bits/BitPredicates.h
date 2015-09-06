
#ifndef BITPREDICATES_H_INCLUDED
#define BITPREDICATES_H_INCLUDED

#include <stdint.h>
#include <limits.h>

/*@ axiomatic b4fc_bit
  @ {
  @   logic       boolean LogicalBitTest(integer v, integer n);
  @
  @   predicate   BitTest(integer v, integer n);
  @ }
*/

/*@
   predicate Bit8{A}(integer v, integer n)  = BitTest(v, 7 - n);

   predicate Bit64{A}(integer v, integer n) = BitTest(v, 63 - n);
*/
  
#define Bit8Array(Stream,Pos) (Bit8(Stream[((Pos)/8)],((Pos)%8)))

/*@
   predicate Invariant{A}(uint64_t x) = \true;

   predicate ZeroInitialized{A}(uint64_t x) = x == 0;

   predicate
     Unchanged{A,B}(uint8_t* addr, integer first, integer last) =
        \forall integer i; first <= i < last ==>
           (\at(Bit8Array(addr, i), A) <==> \at(Bit8Array(addr, i), B));

   predicate
     EqualBits8{A}(uint8_t x, uint8_t y, integer first, integer last) =
        \forall integer i; 8 - last <= i < 8 - first ==> (BitTest(x, i) <==> BitTest(y, i));

   predicate
     EqualBits64{A}(uint64_t x, uint64_t y, integer first, integer last) =
        \forall integer i; 64 - last <= i < 64 - first ==> (BitTest(x, i) <==> BitTest(y, i));

   predicate EqualBits{A}(uint8_t* addr, integer first, integer last,
                          uint64_t value, integer length) =
        \forall integer i; first <= i < last ==>
           (Bit8Array(addr, i) <==> BitTest(value, length + first - 1 - i));

   // overloaded version
   predicate EqualBits{A}(uint8_t* addr, integer first, integer last, uint64_t value) =
        \forall integer i; first <= i < last ==>
           (Bit8Array(addr, i) <==> BitTest(value, last - 1 - i));

   predicate
     UpperBitsNotSet{A}(integer value, integer length) =
       \forall integer i; length <= i ==> !BitTest(value, i);
*/

#endif  // BITPREDICATES_H_INCLUDED

