
#ifndef PACKAGE_FOO_DECODER_H_INCLUDED
#define PACKAGE_FOO_DECODER_H_INCLUDED

#include "Package_Foo.h"

/*@
    requires Readable(stream);

    requires Invariant(stream, BitSize(p));

    requires \valid(p);

    requires Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:    EqualBits{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, BitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures \result == 1;
      ensures stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures EqualBits(stream, \old(stream->bitpos), p);
      ensures UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, BitSize(p));

      assigns \nothing;

      ensures \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p);


#endif // PACKAGE_FOO_DECODER_H_INCLUDED
