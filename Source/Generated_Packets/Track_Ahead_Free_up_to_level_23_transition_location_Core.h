
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Track_Ahead_Free_up_to_level_23_transition_location_Core
{
    // TransmissionMedia=Balise
    // Notification to on-board that track ahead is free from the balise
    // group transmitting this information up to the level 2/3 transition location
    // Packet Number = 90

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_NEWCOUNTRY;     // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
};

#ifdef __cplusplus

inline bool operator==(const Track_Ahead_Free_up_to_level_23_transition_location_Core& a, const Track_Ahead_Free_up_to_level_23_transition_location_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY) &&
        (a.NID_C == b.NID_C) &&
        (a.NID_BG == b.NID_BG);
}

inline bool operator!=(const Track_Ahead_Free_up_to_level_23_transition_location_Core& a, const Track_Ahead_Free_up_to_level_23_transition_location_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Ahead_Free_up_to_level_23_transition_location_Core Track_Ahead_Free_up_to_level_23_transition_location_Core;

#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE 40

/*@
    logic integer BitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) = TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED
