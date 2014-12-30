
#ifndef PACKAGE_FOO_ENCODER_H_INCLUDED
#define PACKAGE_FOO_ENCODER_H_INCLUDED

#include "Package_Foo.h"

/*@
    requires \valid(stream);
    requires BitstreamInvariant(stream);
    requires stream->bitpos + BitSize(p) <= UINT32_MAX;
    requires \valid_read(p);
    requires \separated(stream, p);
    requires \separated(stream->addr + (0..stream->size-1), p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior invalid_bit_sequence:
      assumes !NormalBitsequence{Pre}(stream, BitSize(p));

      assigns \nothing;

      ensures \result == -1;

    behavior values_too_big:
      assumes NormalBitsequence{Pre}(stream, BitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures \result == -2;

    behavior normal_case:
      assumes NormalBitsequence{Pre}(stream, BitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures \result == 1;

      ensures stream->bitpos == \old(stream->bitpos) + BitSize(p);

      ensures unchanged_left:  BitstreamUnchanged{Here,Old}(stream, 0, \old(stream->bitpos));

      ensures BitstreamEqual(stream, \old(stream->bitpos), p);

      ensures unchanged_right: BitstreamUnchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

      ensures BitstreamInvariant(stream);

    complete behaviors;
    disjoint behaviors;
*/
int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p);


#endif // PACKAGE_FOO_ENCODER_H_INCLUDED

