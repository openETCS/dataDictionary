
#ifndef ADHESION_FACTOR_ENCODER_H_INCLUDED
#define ADHESION_FACTOR_ENCODER_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires \valid_read(p);

    requires Writeable(stream);

    requires Invariant(stream, BitSize(p));

    requires Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, BitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures \result == 1;

      ensures stream->bitpos == \old(stream->bitpos) + BitSize(p);

      ensures left:   BitstreamUnchanged{Here,Old}(stream, 0, \old(stream->bitpos));

      ensures middle: BitstreamEqual(stream, \old(stream->bitpos), p);

      ensures right:  BitstreamUnchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, BitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, BitSize(p));

      assigns \nothing;

      ensures \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Adhesion_Factor_Encoder(Bitstream* stream, const Adhesion_Factor* p);


#endif // ADHESION_FACTOR_ENCODER_H_INCLUDED

