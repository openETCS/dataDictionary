
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Track_Condition_Big_Metal_Masses_Core_1
{

    uint16_t  D_TRACKCOND_k;    // # 15
    uint16_t  L_TRACKCOND_k;    // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Big_Metal_Masses_Core_1& p)
{
    stream 
       << +p.D_TRACKCOND_k << ','
       << +p.L_TRACKCOND_k;

    return stream;
}

inline bool operator==(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_TRACKCOND_k == b.D_TRACKCOND_k);
    status = status && (a.L_TRACKCOND_k == b.L_TRACKCOND_k);

    return status;
}

inline bool operator!=(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Big_Metal_Masses_Core_1 Track_Condition_Big_Metal_Masses_Core_1;

#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE 82

/*@
    logic integer BitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Big_Metal_Masses_Core_1* p) = \true;

    predicate ZeroInitialized(Track_Condition_Big_Metal_Masses_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Big_Metal_Masses_Core_1* p) =
      EqualBits(stream, pos + 52,  pos + 67,  p->D_TRACKCOND_k)     &&
      EqualBits(stream, pos + 67,  pos + 82,  p->L_TRACKCOND_k);

    predicate UpperBitsNotSet(Track_Condition_Big_Metal_Masses_Core_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND_k,    15)  &&
      UpperBitsNotSet(p->L_TRACKCOND_k,    15);

*/

#endif // TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

