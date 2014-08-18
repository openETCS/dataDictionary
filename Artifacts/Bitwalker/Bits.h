
#ifndef Bits_defined
#define Bits_defined

/*@ axiomatic b4fc_btest
  @ {
  @   logic boolean LogicalBitTest(integer v, integer n);
  @   predicate     BitTest (integer v, integer n);
  @ }
*/

#define BytePos(Pos) ((Pos)/8)
#define LeftBit8(Value,Pos)  (BitTest(Value,(7 - (Pos))))
#define LeftBitInStream(Stream,Pos) (LeftBit8(Stream[BytePos(Pos)],((Pos)%8)))
#define LeftBit64(Value,Pos)  (BitTest(Value,(63 - (Pos))))

/*
   // not used
   lemma BitsAndMore :
      \forall uint64_t x, integer n;
        (0 <= n < 64)  ==>
        ((x < (1 << n)) <==> (\forall integer i; 0 <= i && i < 64-n ==> !LeftBit64(x, i)));
*/

/*
   // not used
   lemma BitsAndEquality :
      \forall uint64_t x, y;
      (\forall integer i; 0 <= i && i < 64 ==> (LeftBit64(x, i) <==> LeftBit64(y, i)))
      ==> (x == y);
*/

#endif
