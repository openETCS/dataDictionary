
#ifndef ADHESION_FACTOR_CORE_H_INCLUDED
#define ADHESION_FACTOR_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Adhesion_Factor_Core
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of
    // the adhesion factor to be used in the brake model. 
    // Packet Number = 71

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_ADHESION;       // # 15
    uint16_t  L_ADHESION;       // # 15
    uint32_t  M_ADHESION;       // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Adhesion_Factor_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_ADHESION << ','
       << +p.L_ADHESION << ','
       << +p.M_ADHESION;

    return stream;
}

inline bool operator==(const Adhesion_Factor_Core& a, const Adhesion_Factor_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_ADHESION == b.D_ADHESION);
    status = status && (a.L_ADHESION == b.L_ADHESION);
    status = status && (a.M_ADHESION == b.M_ADHESION);

    return status;
}

inline bool operator!=(const Adhesion_Factor_Core& a, const Adhesion_Factor_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Adhesion_Factor_Core Adhesion_Factor_Core;

#define ADHESION_FACTOR_CORE_BITSIZE 48

/*@
    logic integer BitSize{L}(Adhesion_Factor_Core* p) = ADHESION_FACTOR_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor_Core* p) = \true;

    predicate ZeroInitialized(Adhesion_Factor_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION)        &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION)        &&
      EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

    predicate UpperBitsNotSet(Adhesion_Factor_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_ADHESION,       15)  &&
      UpperBitsNotSet(p->L_ADHESION,       15)  &&
      UpperBitsNotSet(p->M_ADHESION,       1);

*/

#endif // ADHESION_FACTOR_CORE_H_INCLUDED

