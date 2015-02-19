
#ifndef SYSTEM_VERSION_ORDER_DATA_H_INCLUDED
#define SYSTEM_VERSION_ORDER_DATA_H_INCLUDED

#include "Bitstream.h"

struct System_Version_order_Data
{
    // TransmissionMedia=Balise
    // This packet is used to tell the on-board which is the operated system version
    // Packet Number = 2

    uint32_t  Q_DIR;            // # 2
    uint32_t  M_VERSION;        // # 7
};

typedef struct System_Version_order_Data System_Version_order_Data;

#define SYSTEM_VERSION_ORDER_DATA_BITSIZE 22

/*@
    logic integer BitSize{L}(System_Version_order_Data* p) = SYSTEM_VERSION_ORDER_DATA_BITSIZE;

    logic integer MaxBitSize{L}(System_Version_order_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, System_Version_order_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(System_Version_order_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->M_VERSION);

    predicate ZeroInitialized(System_Version_order_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->M_VERSION);

    predicate EqualBits(Bitstream* stream, integer pos, System_Version_order_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);


    predicate UpperBitsNotSet(System_Version_order_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->M_VERSION,        7);

*/

#endif // SYSTEM_VERSION_ORDER_DATA_H_INCLUDED

