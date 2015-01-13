
#ifndef VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

#include "Bitstream.h"

struct Virtual_Balise_Cover_order
{
    // TransmissionMedia=Balise
    // The packet sets/removes a Virtual Balise Cover.
    // Packet Number = 6

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_VBCO;           // # 1
    uint64_t  NID_VBCMK;        // # 6
    uint64_t  NID_C;            // # 10
    uint64_t  T_VBC;            // # 8
};

typedef struct Virtual_Balise_Cover_order Virtual_Balise_Cover_order;

#define VIRTUAL_BALISE_COVER_ORDER_BITSIZE 48

/*@
    logic integer BitSize{L}(Virtual_Balise_Cover_order* p) = VIRTUAL_BALISE_COVER_ORDER_BITSIZE;

    logic integer MaxBitSize{L}(Virtual_Balise_Cover_order* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Virtual_Balise_Cover_order* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Virtual_Balise_Cover_order* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_VBCO)            &&
      Invariant(p->NID_VBCMK)         &&
      Invariant(p->NID_C)             &&
      Invariant(p->T_VBC);

    predicate ZeroInitialized(Virtual_Balise_Cover_order* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_VBCO)            &&
      ZeroInitialized(p->NID_VBCMK)         &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->T_VBC);

    predicate EqualBits(Bitstream* stream, integer pos, Virtual_Balise_Cover_order* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 24,  p->Q_VBCO)            &&
      EqualBits(stream, pos + 24,  pos + 30,  p->NID_VBCMK)         &&
      EqualBits(stream, pos + 30,  pos + 40,  p->NID_C)             &&
      EqualBits(stream, pos + 40,  pos + 48,  p->T_VBC);


    predicate UpperBitsNotSet(Virtual_Balise_Cover_order* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_VBCO,           1)   &&
      UpperBitsNotSet(p->NID_VBCMK,        6)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->T_VBC,            8);

*/

#endif // VIRTUAL_BALISE_COVER_ORDER_H_INCLUDED

