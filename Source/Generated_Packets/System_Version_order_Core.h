
#ifndef SYSTEM_VERSION_ORDER_CORE_H_INCLUDED
#define SYSTEM_VERSION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct System_Version_order_Core
{
    // TransmissionMedia=Balise
    // This packet is used to tell the on-board which is the
    // operated system version        
    // Packet Number = 2

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  M_VERSION;        // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const System_Version_order_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.M_VERSION;

    return stream;
}

inline bool operator==(const System_Version_order_Core& a, const System_Version_order_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.M_VERSION == b.M_VERSION);

    return status;
}

inline bool operator!=(const System_Version_order_Core& a, const System_Version_order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct System_Version_order_Core System_Version_order_Core;

#define SYSTEM_VERSION_ORDER_CORE_BITSIZE 28

/*@
    logic integer BitSize{L}(System_Version_order_Core* p) = SYSTEM_VERSION_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(System_Version_order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, System_Version_order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(System_Version_order_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_VERSION);

    predicate ZeroInitialized(System_Version_order_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_VERSION);

    predicate EqualBits(Bitstream* stream, integer pos, System_Version_order_Core* p) =
      EqualBits(stream, pos + 6,   pos + 8,   p->Q_DIR)             &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 28,  p->M_VERSION);

    predicate UpperBitsNotSet(System_Version_order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_VERSION,        7);

*/

#endif // SYSTEM_VERSION_ORDER_CORE_H_INCLUDED

