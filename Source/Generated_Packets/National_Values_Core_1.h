
#ifndef NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct National_Values_Core_1
{

    uint16_t  NID_C_p;          // # 10
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_1& p)
{
    stream 
       << +p.NID_C_p;

    return stream;
}

inline bool operator==(const National_Values_Core_1& a, const National_Values_Core_1& b)
{
    bool status = true;
    
    status = status && (a.NID_C_p == b.NID_C_p);

    return status;
}

inline bool operator!=(const National_Values_Core_1& a, const National_Values_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_1 National_Values_Core_1;

#define NATIONAL_VALUES_CORE_1_CORE_BITSIZE 57

/*@
    logic integer BitSize{L}(National_Values_Core_1* p) = NATIONAL_VALUES_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_1* p) =
      Invariant(p->NID_C_p);

    predicate ZeroInitialized(National_Values_Core_1* p) =
      ZeroInitialized(p->NID_C_p);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_1* p) =
      EqualBits(stream, pos + 47,  pos + 57,  p->NID_C_p);

    predicate UpperBitsNotSet(National_Values_Core_1* p) =
      UpperBitsNotSet(p->NID_C_p,          10);

*/

#endif // NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED

