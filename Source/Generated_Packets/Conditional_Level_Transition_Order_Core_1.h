
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Conditional_Level_Transition_Order_Core_1
{

    uint64_t   M_LEVELTR_k;      // # 3
    uint64_t   NID_NTC_k;        // # 8
};

#ifdef __cplusplus

#include <iostream>

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

#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE 3

/*@
    logic integer BitSize{L}(Conditional_Level_Transition_Order_Core_1* p) = CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Conditional_Level_Transition_Order_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Conditional_Level_Transition_Order_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Conditional_Level_Transition_Order_Core_1* p) =
      Invariant(p->M_LEVELTR_k);

    predicate ZeroInitialized(Conditional_Level_Transition_Order_Core_1* p) =
      ZeroInitialized(p->M_LEVELTR_k);

    predicate EqualBits(Bitstream* stream, integer pos, Conditional_Level_Transition_Order_Core_1* p) =
      EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR_k);

    predicate UpperBitsNotSet(Conditional_Level_Transition_Order_Core_1* p) =
      UpperBitsNotSet(p->M_LEVELTR_k,      3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Conditional_Level_Transition_Order_Core_1_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core_1* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Conditional_Level_Transition_Order_Core_1_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order_Core_1* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Conditional_Level_Transition_Order_Core_1_Decoder(Bitstream* stream, Conditional_Level_Transition_Order_Core_1* p);

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

