
#ifndef NATIONAL_VALUES_CORE_3_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_3_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "National_Values_Core_3_1.h"

struct National_Values_Core_3
{

    uint8_t   Q_NVKVINTSET_k;   // # 2
    uint8_t   A_NVP12_k;        // # 6
    uint8_t   A_NVP23_k;        // # 6
    uint8_t   V_NVKVINT_k;      // # 7
    uint8_t   M_NVKVINT_k;      // # 7
    uint8_t   N_ITER_3_1;       // # 5
    National_Values_Core_3_1   sub_3_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_3& p)
{
    stream 
       << +p.Q_NVKVINTSET_k << ','
       << +p.A_NVP12_k << ','
       << +p.A_NVP23_k << ','
       << +p.V_NVKVINT_k << ','
       << +p.M_NVKVINT_k << ','
       << +p.N_ITER_3_1;
       for (uint32_t i = 0; i < p.N_ITER_3_1; ++i)
       {
           stream << ',' << p.sub_3_1[i];
       }
    

    return stream;
}

inline bool operator==(const National_Values_Core_3& a, const National_Values_Core_3& b)
{
    bool status = true;
    
    status = status && (a.Q_NVKVINTSET_k == b.Q_NVKVINTSET_k);
    if (a.Q_NVKVINTSET_k == 1)
    {
    status = status && (a.A_NVP12_k == b.A_NVP12_k);
    status = status && (a.A_NVP23_k == b.A_NVP23_k);
    }
    status = status && (a.V_NVKVINT_k == b.V_NVKVINT_k);
    status = status && (a.M_NVKVINT_k == b.M_NVKVINT_k);
    status = status && (a.N_ITER_3_1 == b.N_ITER_3_1);
    if (a.N_ITER_3_1 == b.N_ITER_3_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_3_1; ++i)
        {
            status = status && (a.sub_3_1[i] == b.sub_3_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const National_Values_Core_3& a, const National_Values_Core_3& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_3 National_Values_Core_3;

#define NATIONAL_VALUES_CORE_3_CORE_BITSIZE 331

/*@
    logic integer BitSize{L}(National_Values_Core_3* p) = NATIONAL_VALUES_CORE_3_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_3* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_3* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_3* p) = \true;

    predicate ZeroInitialized(National_Values_Core_3* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_3* p) =
      EqualBits(stream, pos + 284, pos + 286, p->Q_NVKVINTSET_k)    &&
      EqualBits(stream, pos + 298, pos + 305, p->V_NVKVINT_k)       &&
      EqualBits(stream, pos + 305, pos + 312, p->M_NVKVINT_k);

    predicate UpperBitsNotSet(National_Values_Core_3* p) =
      UpperBitsNotSet(p->Q_NVKVINTSET_k,   2)   &&
      UpperBitsNotSet(p->V_NVKVINT_k,      7)   &&
      UpperBitsNotSet(p->M_NVKVINT_k,      7)   &&
      UpperBitsNotSet(p->N_ITER_3_1         5;

*/

#endif // NATIONAL_VALUES_CORE_3_CORE_H_INCLUDED

