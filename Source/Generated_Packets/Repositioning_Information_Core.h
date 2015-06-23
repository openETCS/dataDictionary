
#ifndef REPOSITIONING_INFORMATION_CORE_H_INCLUDED
#define REPOSITIONING_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Repositioning_Information_Core
{
    // TransmissionMedia=Balise
    // Transmission of the update of the current distance   
    // Packet Number = 16

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  L_SECTION;        // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Repositioning_Information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.L_SECTION;

    return stream;
}

inline bool operator==(const Repositioning_Information_Core& a, const Repositioning_Information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.L_SECTION == b.L_SECTION);

    return status;
}

inline bool operator!=(const Repositioning_Information_Core& a, const Repositioning_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Repositioning_Information_Core Repositioning_Information_Core;

#define REPOSITIONING_INFORMATION_CORE_BITSIZE 32

/*@
    logic integer BitSize{L}(Repositioning_Information_Core* p) = REPOSITIONING_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Repositioning_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Repositioning_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Repositioning_Information_Core* p) = \true;

    predicate ZeroInitialized(Repositioning_Information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Repositioning_Information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

    predicate UpperBitsNotSet(Repositioning_Information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->L_SECTION,        15);

*/

#endif // REPOSITIONING_INFORMATION_CORE_H_INCLUDED

