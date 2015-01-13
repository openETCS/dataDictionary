
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

#include "Bitstream.h"

struct Track_Ahead_Free_up_to_level_23_transition_location
{
    // TransmissionMedia=Balise
    // Notification to on-board that track ahead is free from the balise group transmitting this information up to the level 2/3 transition location
    // Packet Number = 90

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct Track_Ahead_Free_up_to_level_23_transition_location Track_Ahead_Free_up_to_level_23_transition_location;

#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_BITSIZE 48

/*@
    logic integer BitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location* p) = TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_BITSIZE;

    logic integer MaxBitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Ahead_Free_up_to_level_23_transition_location* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Ahead_Free_up_to_level_23_transition_location* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY)      &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_BG);

    predicate ZeroInitialized(Track_Ahead_Free_up_to_level_23_transition_location* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY)      &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_BG);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Ahead_Free_up_to_level_23_transition_location* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_NEWCOUNTRY)      &&
      EqualBits(stream, pos + 24,  pos + 34,  p->NID_C)             &&
      EqualBits(stream, pos + 34,  pos + 48,  p->NID_BG);


    predicate UpperBitsNotSet(Track_Ahead_Free_up_to_level_23_transition_location* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_BG,           14);

*/

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

