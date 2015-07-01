
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_DECODER_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_DECODER_H_INCLUDED

#include "International_Static_Speed_Profile_Core_2_1.h"

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

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
int International_Static_Speed_Profile_Core_2_1_Decoder(Bitstream* stream, International_Static_Speed_Profile_Core_2_1* p);


#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_2_1_DECODER_H_INCLUDED

