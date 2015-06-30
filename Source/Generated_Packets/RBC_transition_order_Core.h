
#ifndef RBC_TRANSITION_ORDER_CORE_H_INCLUDED
#define RBC_TRANSITION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct RBC_transition_order_Core
{
    // TransmissionMedia=Balise, RBC
    // Packet to order an RBC transition     
    // Packet Number = 131

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_RBCTR;          // # 15
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint32_t  Q_SLEEPSESSION;   // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const RBC_transition_order_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_RBCTR << ','
       << +p.NID_C << ','
       << +p.NID_RBC << ','
       << +p.NID_RADIO << ','
       << +p.Q_SLEEPSESSION;

    return stream;
}

inline bool operator==(const RBC_transition_order_Core& a, const RBC_transition_order_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_RBCTR == b.D_RBCTR);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RBC == b.NID_RBC);
    status = status && (a.NID_RADIO == b.NID_RADIO);
    status = status && (a.Q_SLEEPSESSION == b.Q_SLEEPSESSION);

    return status;
}

inline bool operator!=(const RBC_transition_order_Core& a, const RBC_transition_order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct RBC_transition_order_Core RBC_transition_order_Core;

#define RBC_TRANSITION_ORDER_CORE_BITSIZE 3594

/*@
    logic integer BitSize{L}(RBC_transition_order_Core* p) = RBC_TRANSITION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(RBC_transition_order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RBC_transition_order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RBC_transition_order_Core* p) = \true;

    predicate ZeroInitialized(RBC_transition_order_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, RBC_transition_order_Core* p) = \true;

    predicate UpperBitsNotSet(RBC_transition_order_Core* p) = \true;

*/

#endif // RBC_TRANSITION_ORDER_CORE_H_INCLUDED

