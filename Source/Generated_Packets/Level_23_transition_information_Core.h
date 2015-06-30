
#ifndef LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED
#define LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Level_23_transition_information_Core
{
    // TransmissionMedia=RBC
    // Identity of the level 2/3 transition balise group   
    // Packet Number = 9

    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_LTRBG;        // # 24
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_23_transition_information_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.NID_LTRBG;

    return stream;
}

inline bool operator==(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_LTRBG == b.NID_LTRBG);

    return status;
}

inline bool operator!=(const Level_23_transition_information_Core& a, const Level_23_transition_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_23_transition_information_Core Level_23_transition_information_Core;

#define LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE 4640

/*@
    logic integer BitSize{L}(Level_23_transition_information_Core* p) = LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_23_transition_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_23_transition_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_23_transition_information_Core* p) = \true;

    predicate ZeroInitialized(Level_23_transition_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_23_transition_information_Core* p) = \true;

    predicate UpperBitsNotSet(Level_23_transition_information_Core* p) = \true;

*/

#endif // LEVEL_23_TRANSITION_INFORMATION_CORE_H_INCLUDED

