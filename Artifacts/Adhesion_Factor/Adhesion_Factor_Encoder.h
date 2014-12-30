
#ifndef ADHESION_FACTOR_ENCODER_H_INCLUDED
#define ADHESION_FACTOR_ENCODER_H_INCLUDED

#include "Adhesion_Factor.h"

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

    complete behaviors;
    disjoint behaviors;
*/
int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p);


#endif // ADHESION_FACTOR_ENCODER_H_INCLUDED
