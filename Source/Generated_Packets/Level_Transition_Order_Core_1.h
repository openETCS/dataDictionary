
#ifndef LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Level_Transition_Order_Core_1
{

    uint8_t   M_LEVELTR_k;      // # 3
    uint8_t   NID_NTC_k;        // # 8
    uint16_t  L_ACKLEVELTR_k;   // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Level_Transition_Order_Core_1& p)
{
    stream 
       << +p.M_LEVELTR_k << ','
       << +p.NID_NTC_k << ','
       << +p.L_ACKLEVELTR_k;

    return stream;
}

inline bool operator==(const Level_Transition_Order_Core_1& a, const Level_Transition_Order_Core_1& b)
{
    bool status = true;
    
    status = status && (a.M_LEVELTR_k == b.M_LEVELTR_k);
    if (a.M_LEVELTR_k == 1)
    {
    status = status && (a.NID_NTC_k == b.NID_NTC_k);
    }
    status = status && (a.L_ACKLEVELTR_k == b.L_ACKLEVELTR_k);

    return status;
}

inline bool operator!=(const Level_Transition_Order_Core_1& a, const Level_Transition_Order_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_Transition_Order_Core_1 Level_Transition_Order_Core_1;

#define LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE 1510

/*@
    logic integer BitSize{L}(Level_Transition_Order_Core_1* p) = LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_Transition_Order_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Transition_Order_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Transition_Order_Core_1* p) = \true;

    predicate ZeroInitialized(Level_Transition_Order_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Level_Transition_Order_Core_1* p) = \true;

    predicate UpperBitsNotSet(Level_Transition_Order_Core_1* p) = \true;

*/

#endif // LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

