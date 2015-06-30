
#ifndef GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED
#define GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Gradient_Profile_Core_1
{

    uint16_t  D_GRADIENT_k;     // # 15
    uint8_t   Q_GDIR_k;         // # 1
    uint8_t   G_A_k;            // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Gradient_Profile_Core_1& p)
{
    stream 
       << +p.D_GRADIENT_k << ','
       << +p.Q_GDIR_k << ','
       << +p.G_A_k;

    return stream;
}

inline bool operator==(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_GRADIENT_k == b.D_GRADIENT_k);
    status = status && (a.Q_GDIR_k == b.Q_GDIR_k);
    status = status && (a.G_A_k == b.G_A_k);

    return status;
}

inline bool operator!=(const Gradient_Profile_Core_1& a, const Gradient_Profile_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Gradient_Profile_Core_1 Gradient_Profile_Core_1;

#define GRADIENT_PROFILE_CORE_1_CORE_BITSIZE 1221

/*@
    logic integer BitSize{L}(Gradient_Profile_Core_1* p) = GRADIENT_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Gradient_Profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Gradient_Profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Gradient_Profile_Core_1* p) = \true;

    predicate ZeroInitialized(Gradient_Profile_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Gradient_Profile_Core_1* p) = \true;

    predicate UpperBitsNotSet(Gradient_Profile_Core_1* p) = \true;

*/

#endif // GRADIENT_PROFILE_CORE_1_CORE_H_INCLUDED

