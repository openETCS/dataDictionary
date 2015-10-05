
#ifndef SYSTEM_VERSION_ORDER_H_INCLUDED
#define SYSTEM_VERSION_ORDER_H_INCLUDED

#include "Bitstream.h"

struct System_Version_order
{
    // TransmissionMedia=Balise
    // This packet is used to tell the on-board which is the
    // operated system version        
    // Packet Number = 2

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  M_VERSION;        // # 7
};

typedef struct System_Version_order System_Version_order;

#define SYSTEM_VERSION_ORDER_BITSIZE 22

/*@
    logic integer BitSize{L}(System_Version_order* p) = SYSTEM_VERSION_ORDER_BITSIZE;

    logic integer MaxBitSize{L}(System_Version_order* p) = BitSize(p);

    predicate Separated(Bitstream* stream, System_Version_order* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(System_Version_order* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_VERSION);

    predicate ZeroInitialized(System_Version_order* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_VERSION);

    predicate EqualBits(Bitstream* stream, integer pos, System_Version_order* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);


    predicate UpperBitsNotSet(System_Version_order* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_VERSION,        7);

*/

#endif // SYSTEM_VERSION_ORDER_H_INCLUDED

