
#ifndef TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Temporary_Speed_Restriction_Core
{
    // TransmissionMedia=Any
    // Transmission of temporary speed restriction.      
    // Packet Number = 65

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   NID_TSR;          // # 8
    uint16_t  D_TSR;            // # 15
    uint16_t  L_TSR;            // # 15
    uint32_t  Q_FRONT;          // # 1
    uint8_t   V_TSR;            // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Temporary_Speed_Restriction_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.NID_TSR << ','
       << +p.D_TSR << ','
       << +p.L_TSR << ','
       << +p.Q_FRONT << ','
       << +p.V_TSR;

    return stream;
}

inline bool operator==(const Temporary_Speed_Restriction_Core& a, const Temporary_Speed_Restriction_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_TSR == b.NID_TSR);
    status = status && (a.D_TSR == b.D_TSR);
    status = status && (a.L_TSR == b.L_TSR);
    status = status && (a.Q_FRONT == b.Q_FRONT);
    status = status && (a.V_TSR == b.V_TSR);

    return status;
}

inline bool operator!=(const Temporary_Speed_Restriction_Core& a, const Temporary_Speed_Restriction_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Temporary_Speed_Restriction_Core Temporary_Speed_Restriction_Core;

#define TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE 63

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Core* p) = TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_TSR)           &&
      Invariant(p->D_TSR)             &&
      Invariant(p->L_TSR)             &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->V_TSR);

    predicate ZeroInitialized(Temporary_Speed_Restriction_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_TSR)           &&
      ZeroInitialized(p->D_TSR)             &&
      ZeroInitialized(p->L_TSR)             &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->V_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR)             &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR)             &&
      EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_TSR,          8)   &&
      UpperBitsNotSet(p->D_TSR,            15)  &&
      UpperBitsNotSet(p->L_TSR,            15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->V_TSR,            7);

*/

#endif // TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED

