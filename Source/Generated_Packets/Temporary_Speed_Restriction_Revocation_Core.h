
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

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

inline std::ostream& operator<<(std::ostream& stream, const Temporary_Speed_Restriction_Revocation_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_TSR;

    return stream;
}

inline bool operator==(const Temporary_Speed_Restriction_Revocation_Core& a, const Temporary_Speed_Restriction_Revocation_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_TSR == b.NID_TSR);

    return status;
}

inline bool operator!=(const Temporary_Speed_Restriction_Revocation_Core& a, const Temporary_Speed_Restriction_Revocation_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Temporary_Speed_Restriction_Revocation_Core Temporary_Speed_Restriction_Revocation_Core;

#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_BITSIZE 2318

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Revocation_Core* p) = TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Revocation_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Revocation_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Revocation_Core* p) = \true;

    predicate ZeroInitialized(Temporary_Speed_Restriction_Revocation_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Revocation_Core* p) = \true;

    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Revocation_Core* p) = \true;

*/

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_CORE_H_INCLUDED

