
#ifndef PACKAGE_FOO_ENCODER_H_INCLUDED
#define PACKAGE_FOO_ENCODER_H_INCLUDED

#include "Package_Foo.h"

/*@
    requires \valid_read(p);

    requires Writeable(stream);

    requires Invariant(stream, BitSize(p));

    requires Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, BitSize(p));

      assigns \nothing;

      ensures \result == -1;

    behavior values_too_big:
      assumes Normal{Pre}(stream, BitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures \result == -2;

    behavior normal_case:
      assumes Normal{Pre}(stream, BitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures \result == 1;

      ensures stream->bitpos == \old(stream->bitpos) + BitSize(p);

      ensures left:   EqualBits{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle: EqualBits(stream, \old(stream->bitpos), p);
      ensures right:  EqualBits{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p);


#endif // PACKAGE_FOO_ENCODER_H_INCLUDED

