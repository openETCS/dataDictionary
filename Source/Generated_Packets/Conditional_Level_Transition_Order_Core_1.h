
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Conditional_Level_Transition_Order_Core_1
{

    uint8_t   M_LEVELTR_k;      // # 3
    uint8_t   NID_NTC_k;        // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Conditional_Level_Transition_Order_Core_1& p)
{
    stream 
       << +p.M_LEVELTR_k << ','
       << +p.NID_NTC_k;

    return stream;
}

inline bool operator==(const Conditional_Level_Transition_Order_Core_1& a, const Conditional_Level_Transition_Order_Core_1& b)
{
    bool status = true;
    
    status = status && (a.M_LEVELTR_k == b.M_LEVELTR_k);
    if (a.M_LEVELTR_k == 1)
    {
    status = status && (a.NID_NTC_k == b.NID_NTC_k);
    }

    return status;
}

inline bool operator!=(const Conditional_Level_Transition_Order_Core_1& a, const Conditional_Level_Transition_Order_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Conditional_Level_Transition_Order_Core_1 Conditional_Level_Transition_Order_Core_1;

#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE 42

/*@
    logic integer BitSize{L}(Conditional_Level_Transition_Order_Core_1* p) = CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Conditional_Level_Transition_Order_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Conditional_Level_Transition_Order_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Conditional_Level_Transition_Order_Core_1* p) = \true;

    predicate ZeroInitialized(Conditional_Level_Transition_Order_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Conditional_Level_Transition_Order_Core_1* p) =
      EqualBits(stream, pos + 31,  pos + 34,  p->M_LEVELTR_k);

    predicate UpperBitsNotSet(Conditional_Level_Transition_Order_Core_1* p) =
      UpperBitsNotSet(p->M_LEVELTR_k,      3);

*/

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

