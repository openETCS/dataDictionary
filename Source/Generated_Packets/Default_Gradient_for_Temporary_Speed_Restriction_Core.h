
#ifndef DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED
#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Default_Gradient_for_Temporary_Speed_Restriction_Core
{
    // TransmissionMedia=Balise
    // It defines a default gradient to be used for TSR supervision
    // when no gradient profile (packet 21) is available   
    // Packet Number = 141

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_GDIR;           // # 1
    uint8_t   G_TSR;            // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Default_Gradient_for_Temporary_Speed_Restriction_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_GDIR << ','
       << +p.G_TSR;

    return stream;
}

inline bool operator==(const Default_Gradient_for_Temporary_Speed_Restriction_Core& a, const Default_Gradient_for_Temporary_Speed_Restriction_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_GDIR == b.Q_GDIR);
    status = status && (a.G_TSR == b.G_TSR);

    return status;
}

inline bool operator!=(const Default_Gradient_for_Temporary_Speed_Restriction_Core& a, const Default_Gradient_for_Temporary_Speed_Restriction_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Default_Gradient_for_Temporary_Speed_Restriction_Core Default_Gradient_for_Temporary_Speed_Restriction_Core;

#define DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE 4039

/*@
    logic integer BitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_Gradient_for_Temporary_Speed_Restriction_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = \true;

    predicate ZeroInitialized(Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = \true;

    predicate UpperBitsNotSet(Default_Gradient_for_Temporary_Speed_Restriction_Core* p) = \true;

*/

#endif // DEFAULT_GRADIENT_FOR_TEMPORARY_SPEED_RESTRICTION_CORE_H_INCLUDED

