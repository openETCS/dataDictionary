
#ifndef LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Level_23_transition_information
{
    // TransmissionMedia=RBC
    // Identity of the level 2/3 transition balise group
    // Packet Number = 9

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_LTRBG;        // # 24
};

typedef struct Level_23_transition_information Level_23_transition_information;

#define LEVEL_23_TRANSITION_INFORMATION_BITSIZE 45

/*@
    logic integer BitSize{L}(Level_23_transition_information* p) = LEVEL_23_TRANSITION_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_transition_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_transition_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_transition_information* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level_23_transition_information* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_transition_information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 45,  p->NID_LTRBG);


    predicate UpperBitsNotSet(Level_23_transition_information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

#endif // LEVEL_23_TRANSITION_INFORMATION_H_INCLUDED

