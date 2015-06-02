
#ifndef DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Danger_for_Shunting_information_Core
{
    // TransmissionMedia=Balise
    // Transmission of the aspect of a shunting signal   
    // Packet Number = 132

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_ASPECT;         // # 1
};

#ifdef __cplusplus

inline bool operator==(const Danger_for_Shunting_information_Core& a, const Danger_for_Shunting_information_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_ASPECT == b.Q_ASPECT);
}

inline bool operator!=(const Danger_for_Shunting_information_Core& a, const Danger_for_Shunting_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Danger_for_Shunting_information_Core Danger_for_Shunting_information_Core;

#define DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE 16

/*@
    logic integer BitSize{L}(Danger_for_Shunting_information_Core* p) = DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Danger_for_Shunting_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Danger_for_Shunting_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Danger_for_Shunting_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_ASPECT);

    predicate ZeroInitialized(Danger_for_Shunting_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_ASPECT);

    predicate EqualBits(Bitstream* stream, integer pos, Danger_for_Shunting_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

    predicate UpperBitsNotSet(Danger_for_Shunting_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_ASPECT,         1);

*/

#endif // DANGER_FOR_SHUNTING_INFORMATION_CORE_H_INCLUDED

