
#ifndef NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct National_Values_Core_2
{

    uint8_t   V_NVKVINT_n;      // # 7
    uint8_t   M_NVKVINT_n;      // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_2& p)
{
    stream 
       << +p.V_NVKVINT_n << ','
       << +p.M_NVKVINT_n;

    return stream;
}

inline bool operator==(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    bool status = true;
    
    status = status && (a.V_NVKVINT_n == b.V_NVKVINT_n);
    status = status && (a.M_NVKVINT_n == b.M_NVKVINT_n);

    return status;
}

inline bool operator!=(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_2 National_Values_Core_2;

#define NATIONAL_VALUES_CORE_2_CORE_BITSIZE 279

/*@
    logic integer BitSize{L}(National_Values_Core_2* p) = NATIONAL_VALUES_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_2* p) = \true;

    predicate ZeroInitialized(National_Values_Core_2* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_2* p) =
      EqualBits(stream, pos + 265, pos + 272, p->V_NVKVINT_n)       &&
      EqualBits(stream, pos + 272, pos + 279, p->M_NVKVINT_n);

    predicate UpperBitsNotSet(National_Values_Core_2* p) =
      UpperBitsNotSet(p->V_NVKVINT_n,      7)   &&
      UpperBitsNotSet(p->M_NVKVINT_n,      7);

*/

#endif // NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

