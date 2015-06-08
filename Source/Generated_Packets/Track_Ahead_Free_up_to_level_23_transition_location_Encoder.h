
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_ENCODER_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_ENCODER_H_INCLUDED

#include "Track_Ahead_Free_up_to_level_23_transition_location_Core.h"

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Track_Ahead_Free_up_to_level_23_transition_location_Encoder(Bitstream* stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_ENCODER_H_INCLUDED

