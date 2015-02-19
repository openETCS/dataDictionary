
#ifndef LEVEL_23_TRANSITION_INFORMATION_DATA_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Level_23_transition_information_Data
{
    // TransmissionMedia=RBC
    // Identity of the level 2/3 transition balise group
    // Packet Number = 9

    uint32_t  NID_LTRBG;        // # 24
};

typedef struct Level_23_transition_information_Data Level_23_transition_information_Data;

#define LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE 24

/*@
    logic integer BitSize{L}(Level_23_transition_information_Data* p) = LEVEL_23_TRANSITION_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_transition_information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_transition_information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_transition_information_Data* p) =
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level_23_transition_information_Data* p) =
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_transition_information_Data* p) =
      EqualBits(stream, pos,       pos + 24,  p->NID_LTRBG);


    predicate UpperBitsNotSet(Level_23_transition_information_Data* p) =
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

#endif // LEVEL_23_TRANSITION_INFORMATION_DATA_H_INCLUDED

