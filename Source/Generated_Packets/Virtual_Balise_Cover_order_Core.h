
#ifndef VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"

struct Virtual_Balise_Cover_order_Core
{
    // TransmissionMedia=Balise
    // The packet sets/removes a Virtual Balise Cover.    
    // Packet Number = 6

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_VBCO;           // # 1
    uint8_t   NID_VBCMK;        // # 6
    uint16_t  NID_C;            // # 10
    uint8_t   T_VBC;            // # 8
};

#ifdef __cplusplus

inline bool operator==(const Virtual_Balise_Cover_order_Core& a, const Virtual_Balise_Cover_order_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_VBCO == b.Q_VBCO) &&
        (a.NID_VBCMK == b.NID_VBCMK) &&
        (a.NID_C == b.NID_C) &&
        (a.T_VBC == b.T_VBC);
}

inline bool operator!=(const Virtual_Balise_Cover_order_Core& a, const Virtual_Balise_Cover_order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Virtual_Balise_Cover_order_Core Virtual_Balise_Cover_order_Core;

#define VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE 40

/*@
    logic integer BitSize{L}(Virtual_Balise_Cover_order_Core* p) = VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Virtual_Balise_Cover_order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Virtual_Balise_Cover_order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Virtual_Balise_Cover_order_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_VBCO)            &&
      Invariant(p->NID_VBCMK)         &&
      Invariant(p->NID_C);

    predicate ZeroInitialized(Virtual_Balise_Cover_order_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_VBCO)            &&
      ZeroInitialized(p->NID_VBCMK)         &&
      ZeroInitialized(p->NID_C);

    predicate EqualBits(Bitstream* stream, integer pos, Virtual_Balise_Cover_order_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_VBCO)            &&
      EqualBits(stream, pos + 16,  pos + 22,  p->NID_VBCMK)         &&
      EqualBits(stream, pos + 22,  pos + 32,  p->NID_C);

    predicate UpperBitsNotSet(Virtual_Balise_Cover_order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_VBCO,           1)   &&
      UpperBitsNotSet(p->NID_VBCMK,        6)   &&
      UpperBitsNotSet(p->NID_C,            10);

*/

#endif // VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED

