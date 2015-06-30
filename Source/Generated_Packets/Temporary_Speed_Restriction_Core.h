
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

#define TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE 2295

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Core* p) = TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Core* p) = \true;

    predicate ZeroInitialized(Temporary_Speed_Restriction_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Core* p) = \true;

    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Core* p) = \true;

*/

#endif // TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED

