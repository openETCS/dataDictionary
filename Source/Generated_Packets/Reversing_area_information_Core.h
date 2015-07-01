
#ifndef REVERSING_AREA_INFORMATION_CORE_H_INCLUDED
#define REVERSING_AREA_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Reversing_area_information_Core
{
    // TransmissionMedia=Any
    // Used to send start and length of reversing area to the
    // on-board          
    // Packet Number = 138

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_STARTREVERSE;   // # 15
    uint16_t  L_REVERSEAREA;    // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Reversing_area_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_STARTREVERSE << ','
       << +p.L_REVERSEAREA;

    return stream;
}

inline bool operator==(const Reversing_area_information_Core& a, const Reversing_area_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_STARTREVERSE == b.D_STARTREVERSE);
    status = status && (a.L_REVERSEAREA == b.L_REVERSEAREA);

    return status;
}

inline bool operator!=(const Reversing_area_information_Core& a, const Reversing_area_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Reversing_area_information_Core Reversing_area_information_Core;

#define REVERSING_AREA_INFORMATION_CORE_BITSIZE 47

/*@
    logic integer BitSize{L}(Reversing_area_information_Core* p) = REVERSING_AREA_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_area_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_area_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_area_information_Core* p) = \true;

    predicate ZeroInitialized(Reversing_area_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_area_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE)    &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

    predicate UpperBitsNotSet(Reversing_area_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STARTREVERSE,   15)  &&
      UpperBitsNotSet(p->L_REVERSEAREA,    15);

*/

#endif // REVERSING_AREA_INFORMATION_CORE_H_INCLUDED

