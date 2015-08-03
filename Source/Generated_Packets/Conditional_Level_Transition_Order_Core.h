
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Conditional_Level_Transition_Order_Core_1.h"

struct Conditional_Level_Transition_Order_Core
{
    // TransmissionMedia=Balise
    // Packet for a conditional level transition. The successive M_LEVELTR go from
    // the highest priority level to the lowest one.   
    // Packet Number = 46

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  M_LEVELTR;        // # 3
    uint8_t   NID_NTC;          // # 8
    uint8_t   N_ITER_1;         // # 5
    Conditional_Level_Transition_Order_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Conditional_Level_Transition_Order_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.M_LEVELTR << ','
       << +p.NID_NTC << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Conditional_Level_Transition_Order_Core& a, const Conditional_Level_Transition_Order_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.M_LEVELTR == b.M_LEVELTR);
    if (a.M_LEVELTR == 1)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }
    status = status && (a.N_ITER_1 == b.N_ITER_1);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Conditional_Level_Transition_Order_Core& a, const Conditional_Level_Transition_Order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Conditional_Level_Transition_Order_Core Conditional_Level_Transition_Order_Core;

#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE 23

/*@
    logic integer BitSize{L}(Conditional_Level_Transition_Order_Core* p) = CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Conditional_Level_Transition_Order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Conditional_Level_Transition_Order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Conditional_Level_Transition_Order_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(Conditional_Level_Transition_Order_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, Conditional_Level_Transition_Order_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 18,  p->M_LEVELTR);

    predicate UpperBitsNotSet(Conditional_Level_Transition_Order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Conditional_Level_Transition_Order_UpperBitsNotSet(const Conditional_Level_Transition_Order_Core* p);

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
int Conditional_Level_Transition_Order_Encoder(Bitstream* stream, const Conditional_Level_Transition_Order_Core* p);

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
int Conditional_Level_Transition_Order_Decoder(Bitstream* stream, Conditional_Level_Transition_Order_Core* p);

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

