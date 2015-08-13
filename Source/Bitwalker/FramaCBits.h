
#ifndef FRAMACBITS_H_INCLUDED
#define FRAMACBITS_H_INCLUDED

#include <stdint.h>
#include <limits.h>

/*@ axiomatic b4fc_bit
  @ {
  @   logic       boolean LogicalBitTest(integer v, integer n);
  @
  @   predicate   BitTest(integer v, integer n);
  @ }
*/

#define BytePos(Pos) ((Pos)/8)
#define LeftBit8(Value,Pos)  (BitTest(Value,(7 - (Pos))))
#define LeftBit8Array(Stream,Pos) (LeftBit8(Stream[BytePos(Pos)],((Pos)%8)))
#define LeftBit32(Value,Pos)  (BitTest(Value,(31 - (Pos))))
#define LeftBit64(Value,Pos)  (BitTest(Value,(63 - (Pos))))

/*@
   predicate Invariant{A}(uint64_t x) = \true;

   predicate ZeroInitialized{A}(uint64_t x) = x == 0;

   predicate
     Unchanged{A,B}(uint8_t* addr, integer first, integer last) =
        \forall integer i; first <= i < last ==>
           (\at(LeftBit8Array(addr, i), A) <==> \at(LeftBit8Array(addr, i), B));

   predicate
     LeftEqualBits8{A}(uint8_t x, uint8_t y, integer first, integer last) =
        \forall integer i; 8 - last <= i < 8 - first ==> (BitTest(x, i) <==> BitTest(y, i));

   predicate
     LeftEqualBits64{A}(uint64_t x, uint64_t y, integer first, integer last) =
        \forall integer i; 64 - last <= i < 64 - first ==> (BitTest(x, i) <==> BitTest(y, i));

   predicate EqualBits{A}(uint8_t* addr, integer first, integer last,
                          uint64_t value, integer length) =
        \forall integer i; first <= i < last ==>
           (LeftBit8Array(addr, i) <==> LeftBit64(value, 64 - (first + length) + i));

   // overloaded version
   predicate EqualBits{A}(uint8_t* addr, integer first, integer last, uint64_t value) =
      EqualBits{A}(addr, first, last, value, last - first);

   predicate
     UpperBitsNotSet{A}(integer value, integer length) =
       \forall integer i; length <= i ==> !BitTest(value, i);
*/

#endif  // FRAMACBITS_H_INCLUDED

