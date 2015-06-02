
#ifndef LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Level_23_transition_information_Core
{
    // TransmissionMedia=RBC
    // Identity of the level 2/3 transition balise group   
    // Packet Number = 9

    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_LTRBG;        // # 24
};

#ifdef __cplusplus

inline bool operator==(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    return
        (a.L_PACKET == b.L_PACKET) &&
        (a.NID_LTRBG == b.NID_LTRBG);
}

inline bool operator!=(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_23_transition_information_Core Level_23_transition_information_Core;

#define LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE 37

/*@
    logic integer BitSize{L}(Level_23_transition_information_Core* p) = LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_transition_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_transition_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_transition_information_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level_23_transition_information_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_transition_information_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

    predicate UpperBitsNotSet(Level_23_transition_information_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

#endif // LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

