
#ifndef REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Reversing_supervision_information_Core
{
    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing
    // area to the on-board       
    // Packet Number = 139

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_REVERSE;        // # 15
    uint8_t   V_REVERSE;        // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Reversing_supervision_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_REVERSE << ','
       << +p.V_REVERSE;

    return stream;
}

inline bool operator==(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_REVERSE == b.D_REVERSE);
    status = status && (a.V_REVERSE == b.V_REVERSE);

    return status;
}

inline bool operator!=(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Reversing_supervision_information_Core Reversing_supervision_information_Core;

#define REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE 39

/*@
    logic integer BitSize{L}(Reversing_supervision_information_Core* p) = REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_supervision_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_supervision_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_supervision_information_Core* p) = \true;

    predicate ZeroInitialized(Reversing_supervision_information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_supervision_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE)         &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

    predicate UpperBitsNotSet(Reversing_supervision_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_REVERSE,        15)  &&
      UpperBitsNotSet(p->V_REVERSE,        7);

*/

#endif // REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

