
#ifndef NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct National_Values_Core_4
{

    uint8_t   L_NVKRINT_l;      // # 5
    uint8_t   M_NVKRINT_l;      // # 5
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_4& p)
{
    stream 
       << +p.L_NVKRINT_l << ','
       << +p.M_NVKRINT_l;

    return stream;
}

inline bool operator==(const National_Values_Core_4& a, const National_Values_Core_4& b)
{
    bool status = true;
    
    status = status && (a.L_NVKRINT_l == b.L_NVKRINT_l);
    status = status && (a.M_NVKRINT_l == b.M_NVKRINT_l);

    return status;
}

inline bool operator!=(const National_Values_Core_4& a, const National_Values_Core_4& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_4 National_Values_Core_4;

#define NATIONAL_VALUES_CORE_4_CORE_BITSIZE 384

/*@
    logic integer BitSize{L}(National_Values_Core_4* p) = NATIONAL_VALUES_CORE_4_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_4* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_4* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_4* p) = \true;

    predicate ZeroInitialized(National_Values_Core_4* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_4* p) = \true;

    predicate UpperBitsNotSet(National_Values_Core_4* p) = \true;

*/

#endif // NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED

