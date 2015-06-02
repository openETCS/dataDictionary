
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Temporary_Speed_Restriction_Revocation_Core
{
    // TransmissionMedia=Any
    // Transmission of temporary speed restriction revocation.     
    // Packet Number = 66

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint8_t   NID_TSR;          // # 8
};

#ifdef __cplusplus

inline bool operator==(const Temporary_Speed_Restriction_Revocation_Core& a, const Temporary_Speed_Restriction_Revocation_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.NID_TSR == b.NID_TSR);
}

inline bool operator!=(const Temporary_Speed_Restriction_Revocation_Core& a, const Temporary_Speed_Restriction_Revocation_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Temporary_Speed_Restriction_Revocation_Core Temporary_Speed_Restriction_Revocation_Core;

#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_BITSIZE 23

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Revocation_Core* p) = TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Revocation_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Revocation_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Revocation_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_TSR);

    predicate ZeroInitialized(Temporary_Speed_Restriction_Revocation_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Revocation_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Revocation_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_TSR,          8);

*/

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED

