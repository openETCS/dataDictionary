
#ifndef LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED
#define LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Level_Transition_Order_Core_1
{

    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_NTC;          // # 8
    uint64_t  L_ACKLEVELTR;     // # 15
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Level_Transition_Order_Core_1& p)
{
    stream 
       << +p.M_LEVELTR << ','
       << +p.NID_NTC << ','
       << +p.L_ACKLEVELTR;

    return stream;
}

inline bool operator==(const Level_Transition_Order_Core_1& a, const Level_Transition_Order_Core_1& b)
{
    bool status = true;
    
    status = status && (a.M_LEVELTR == b.M_LEVELTR);
    if (a.M_LEVELTR == 1)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }
    status = status && (a.L_ACKLEVELTR == b.L_ACKLEVELTR);

    return status;
}

inline bool operator!=(const Level_Transition_Order_Core_1& a, const Level_Transition_Order_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Level_Transition_Order_Core_1 Level_Transition_Order_Core_1;

#define LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE 18

/*@
    logic integer BitSize{L}(Level_Transition_Order_Core_1* p) = LEVEL_TRANSITION_ORDER_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Level_Transition_Order_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level_Transition_Order_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level_Transition_Order_Core_1* p) =
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(Level_Transition_Order_Core_1* p) =
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, Level_Transition_Order_Core_1* p) =
      EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

    predicate UpperBitsNotSet(Level_Transition_Order_Core_1* p) =
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level_Transition_Order_Core_1_UpperBitsNotSet(const Level_Transition_Order_Core_1* p);

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
int Level_Transition_Order_Core_1_Encoder(Bitstream* stream, const Level_Transition_Order_Core_1* p);

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
int Level_Transition_Order_Core_1_Decoder(Bitstream* stream, Level_Transition_Order_Core_1* p);

#endif // LEVEL_TRANSITION_ORDER_CORE_1_CORE_H_INCLUDED

