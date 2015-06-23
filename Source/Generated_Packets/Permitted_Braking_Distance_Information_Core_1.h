
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Permitted_Braking_Distance_Information_Core_1
{

    uint16_t  D_PBD_k;          // # 15
    uint8_t   Q_GDIR_k;         // # 1
    uint8_t   G_PBDSR_k;        // # 8
    uint8_t   Q_PBDSR_k;        // # 1
    uint16_t  D_PBDSR_k;        // # 15
    uint16_t  L_PBDSR_k;        // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Permitted_Braking_Distance_Information_Core_1& p)
{
    stream 
       << +p.D_PBD_k << ','
       << +p.Q_GDIR_k << ','
       << +p.G_PBDSR_k << ','
       << +p.Q_PBDSR_k << ','
       << +p.D_PBDSR_k << ','
       << +p.L_PBDSR_k;

    return stream;
}

inline bool operator==(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_PBD_k == b.D_PBD_k);
    status = status && (a.Q_GDIR_k == b.Q_GDIR_k);
    status = status && (a.G_PBDSR_k == b.G_PBDSR_k);
    status = status && (a.Q_PBDSR_k == b.Q_PBDSR_k);
    status = status && (a.D_PBDSR_k == b.D_PBDSR_k);
    status = status && (a.L_PBDSR_k == b.L_PBDSR_k);

    return status;
}

inline bool operator!=(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Permitted_Braking_Distance_Information_Core_1 Permitted_Braking_Distance_Information_Core_1;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE 148

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information_Core_1* p) = \true;

    predicate ZeroInitialized(Permitted_Braking_Distance_Information_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information_Core_1* p) = \true;

    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information_Core_1* p) = \true;

*/

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

