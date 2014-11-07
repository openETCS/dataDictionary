
#ifndef BitsFramaC_defined
#define BitsFramaC_defined

#include <stdint.h>
#include <limits.h>

/*@ axiomatic b4fc_btest
  @ {
  @   logic boolean LogicalBitTest(integer v, integer n);
  @
  @   predicate     BitTest(integer v, integer n);
  @ }
*/

#define BytePos(Pos) ((Pos)/8)

#define LeftBit8(Value,Pos)  (BitTest(Value,(7 - (Pos))))

#define LeftBitInStream(Stream,Pos) (LeftBit8(Stream[BytePos(Pos)],((Pos)%8)))

#define LeftBit64(Value,Pos)  (BitTest(Value,(63 - (Pos))))

/*@
   predicate
     EqualBits{A}(uint8_t* Bitstream, uint64_t Value, integer Start, integer Length) =
        \forall integer i; 0 <= i < Length ==>
          (LeftBitInStream(Bitstream, Start + i) <==> LeftBit64(Value, 64-Length+i));
*/
 
/*@
   predicate
     NotSet{A}(uint64_t Value, integer Length) =
       \forall integer i; 0 <= i < Length ==>
         !LeftBit64(Value, i);
*/
 
/*@
   predicate
    IsCopied{A}(uint8_t* Bitstream, uint64_t Value, integer Start, integer Length) =
       \forall integer i; 0 <= i < Length ==>
                 (EqualBits(Bitstream, Value, Start, Length) && NotSet(Value, 64-i));
*/
 
/*@
   predicate
     Unchanged{A}(uint8_t* Bitstream1, uint8_t* Bitstream2, integer Start, integer Length, integer Size) =
       \forall integer i; ((0 <= i < Start ==> (LeftBitInStream(Bitstream1, i) <==> LeftBitInStream(Bitstream2, i))) &&
                         (Start+Length <= i < Size ==> (LeftBitInStream(Bitstream1, i) <==> LeftBitInStream(Bitstream2, i))));
*/
 
/*
    // not used
    lemma BitsAndBound :
      \forall integer x, integer n;
        0 <= x  ==>
        0 <= n  ==>
        ((x < (1 << n)) <==> (\forall integer k; n <= k ==> !BitTest(x, k)));
*/

/*
    // not used
    lemma BitsAndEquality :
       \forall uint64_t x, y;
       (\forall integer i; 0 <= i && i < 64 ==> (LeftBit64(x, i) <==> LeftBit64(y, i)))
       ==> (x == y);
*/


#endif
