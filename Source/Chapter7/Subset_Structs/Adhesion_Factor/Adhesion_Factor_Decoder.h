
#ifndef ADHESION_FACTOR_DECODER_H_INCLUDED
#define ADHESION_FACTOR_DECODER_H_INCLUDED

#include "Adhesion_Factor.h"

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);
    requires equal:		EqualBits(stream, stream->bitpos-BitSize(&p->header), &p->header);
    requires upper:             UpperBitsNotSet(&p->header);

    assigns stream->bitpos;
    assigns p->data;

    ensures unchanged:          EqualBits{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns p->data;

      ensures invariant:  Invariant(&p->header);
      ensures invariant:  Invariant(&p->data);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos)-BitSize(&p->header), &p->header);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), &p->data);
      ensures upper:      UpperBitsNotSet(&p->header);
      ensures upper:      UpperBitsNotSet(&p->data);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p);


#endif // ADHESION_FACTOR_DECODER_H_INCLUDED

