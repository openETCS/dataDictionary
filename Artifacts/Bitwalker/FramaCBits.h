
#ifndef FramaCBits_defined
#define FramaCBits_defined

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
     BitsUnchanged{L}(uint8_t* addr, integer first, integer last ) =
        \forall integer i; first <= i < last ==>
           LeftBit8Array(addr, i) <==> \at(LeftBit8Array(addr, i), L);
*/

/*@
   predicate
     EqualBits{A}(uint8_t* Bitstream, uint64_t Value, integer Start, integer Length) =
        \forall integer i; 0 <= i < Length ==>
          (LeftBit8Array(Bitstream, Start + i) <==> LeftBit64(Value, 64-Length+i));
*/

/*@
   predicate
     LeftNotSet64{A}(uint64_t Value, integer Length) =
       \forall integer i; 0 <= i < Length ==> !LeftBit64(Value, i);

   predicate // legacy name
     NotSet{A}(uint64_t Value, integer Length) = LeftNotSet64{A}(Value, Length);
*/

/*@
   predicate
    IsCopied{A}(uint8_t* Bitstream, uint64_t Value, integer Start, integer Length) =
       \forall integer i; 0 <= i < Length ==>
                 (EqualBits(Bitstream, Value, Start, Length) && NotSet(Value, 64-i));
*/


#endif
