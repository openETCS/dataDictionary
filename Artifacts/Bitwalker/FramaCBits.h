
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
   predicate
     BitsUnchanged{A,B}(uint8_t* addr, integer first, integer last ) =
        \forall integer i; first <= i < last ==>
           (\at(LeftBit8Array(addr, i), A) <==> \at(LeftBit8Array(addr, i), B));
*/

/*@
   predicate EqualBits64{A}(uint8_t* addr,
                            integer first, integer last,
                            uint64_t value, integer length) =
        \forall integer i; first <= i < last ==>
           (LeftBit8Array(addr, i) <==> LeftBit64(value, 64 - length + i - first));

   // overloaded version
   predicate EqualBits64{A}(uint8_t* addr, integer first, integer last, uint64_t value) =
        EqualBits64(addr, first, last, value, last - first);
*/

/*@
   predicate
     UpperBitsNotSet{A}(integer value, integer length) =
       \forall integer i; length <= i ==> !BitTest(value, i);
*/


#endif  // FRAMACBITS_H_INCLUDED

