
#ifndef CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED
#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
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

#define CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE 42

/*@
    logic integer BitSize{L}(Conditional_Level_Transition_Order_Core* p) = CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Conditional_Level_Transition_Order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Conditional_Level_Transition_Order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Conditional_Level_Transition_Order_Core* p) = \true;

    predicate ZeroInitialized(Conditional_Level_Transition_Order_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Conditional_Level_Transition_Order_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 18,  p->M_LEVELTR);

    predicate UpperBitsNotSet(Conditional_Level_Transition_Order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3)   &&
      UpperBitsNotSet(p->N_ITER_1           5;

*/

#endif // CONDITIONAL_LEVEL_TRANSITION_ORDER_CORE_H_INCLUDED

