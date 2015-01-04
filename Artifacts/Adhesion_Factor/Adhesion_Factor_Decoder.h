
#ifndef ADHESION_FACTOR_DECODER_H_INCLUDED
#define ADHESION_FACTOR_DECODER_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid_stream:      Readable(stream);

    requires stream_invariant:  Invariant(stream, BitSize(p));

    requires valid_package:     \valid(p);

    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          BitstreamUnchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, BitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures result:     \result == 1;

      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);

      ensures equal:      BitstreamEqual(stream, \old(stream->bitpos), p);

      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, BitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p);


#endif // ADHESION_FACTOR_DECODER_H_INCLUDED
