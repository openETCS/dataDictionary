
#ifndef REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

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

inline bool operator==(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_SCALE == b.Q_SCALE) &&
        (a.D_REVERSE == b.D_REVERSE) &&
        (a.V_REVERSE == b.V_REVERSE);
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

    predicate Invariant(Reversing_supervision_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_REVERSE)         &&
      Invariant(p->V_REVERSE);

    predicate ZeroInitialized(Reversing_supervision_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_REVERSE)         &&
      ZeroInitialized(p->V_REVERSE);

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

