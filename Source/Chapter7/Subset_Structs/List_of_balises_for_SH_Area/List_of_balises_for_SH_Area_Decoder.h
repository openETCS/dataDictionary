
#ifndef LIST_OF_BALISES_FOR_SH_AREA_DECODER_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_DECODER_H_INCLUDED

#include "List_of_balises_for_SH_Area.h"

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          EqualBits{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int List_of_balises_for_SH_Area_Decoder(Bitstream* stream, List_of_balises_for_SH_Area* p);


#endif // LIST_OF_BALISES_FOR_SH_AREA_DECODER_H_INCLUDED

