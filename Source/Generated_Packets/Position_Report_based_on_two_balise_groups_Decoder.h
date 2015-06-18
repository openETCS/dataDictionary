
#ifndef POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_DECODER_H_INCLUDED
#define POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_DECODER_H_INCLUDED

#include "Position_Report_based_on_two_balise_groups_Core.h"

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
int Position_Report_based_on_two_balise_groups_Decoder(Bitstream* stream, Position_Report_based_on_two_balise_groups_Core* p);


#endif // POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_DECODER_H_INCLUDED

