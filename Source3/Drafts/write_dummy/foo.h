
#ifndef FOO_H_INCLUDED
#define FOO_H_INCLUDED

#include "Bitstream.h"

struct foo
{
    uint16_t  Q_NEWCOUNTRY;	// # 1
    uint16_t  NID_C;            // # 10
};

typedef struct foo foo;

#define FOO_BITSIZE 10

/*@
    logic integer BitSize{L}(foo* p) = FOO_BITSIZE;

    logic integer MaxBitSize{L}(foo* p) = BitSize(p);

    logic integer NID_C_B{L}(foo* p) = 0;

    axiomatic NID_C_E_Axiomatic
    {
        logic integer NID_C_E{L}(foo* p)
	    reads p->Q_NEWCOUNTRY;
	
	axiom NID_C_E_read{L}: \forall foo* p;
	    p->Q_NEWCOUNTRY == 1 ==> NID_C_E(p) == NID_C_B(p) + 10;

	axiom NID_C_E_skip: \forall foo* p;
	    p->Q_NEWCOUNTRY != 1 ==> NID_C_E(p) == NID_C_B(p);
    }


    predicate Separated(Bitstream* stream, foo* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(foo* p) =
      Invariant(p->NID_C);
      
    predicate ZeroInitialized(foo* p) =
      ZeroInitialized(p->NID_C);

    predicate EqualBits{L}(Bitstream* stream, integer pos, foo* p) =
      EqualBits(stream, pos + NID_C_B{L}(p), pos + NID_C_E{L}(p), p->NID_C);


    predicate UpperBitsNotSet(foo* p) =
      UpperBitsNotSet(p->NID_C,            10);

*/

#endif // FOO_H_INCLUDED

