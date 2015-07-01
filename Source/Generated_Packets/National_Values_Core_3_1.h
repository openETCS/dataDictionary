
#ifndef NATIONAL_VALUES_CORE_3_1_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_3_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct National_Values_Core_3_1
{

    uint8_t   V_NVKVINT_k_m;    // # 7
    uint8_t   M_NVKVINT_k_m;    // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_3_1& p)
{
    stream 
       << +p.V_NVKVINT_k_m << ','
       << +p.M_NVKVINT_k_m;

    return stream;
}

inline bool operator==(const National_Values_Core_3_1& a, const National_Values_Core_3_1& b)
{
    bool status = true;
    
    status = status && (a.V_NVKVINT_k_m == b.V_NVKVINT_k_m);
    status = status && (a.M_NVKVINT_k_m == b.M_NVKVINT_k_m);

    return status;
}

inline bool operator!=(const National_Values_Core_3_1& a, const National_Values_Core_3_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_3_1 National_Values_Core_3_1;

#define NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE 331

/*@
    logic integer BitSize{L}(National_Values_Core_3_1* p) = NATIONAL_VALUES_CORE_3_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_3_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_3_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_3_1* p) = \true;

    predicate ZeroInitialized(National_Values_Core_3_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_3_1* p) =
      EqualBits(stream, pos + 317, pos + 324, p->V_NVKVINT_k_m)     &&
      EqualBits(stream, pos + 324, pos + 331, p->M_NVKVINT_k_m);

    predicate UpperBitsNotSet(National_Values_Core_3_1* p) =
      UpperBitsNotSet(p->V_NVKVINT_k_m,    7)   &&
      UpperBitsNotSet(p->M_NVKVINT_k_m,    7);

*/

#endif // NATIONAL_VALUES_CORE_3_1_CORE_H_INCLUDED

