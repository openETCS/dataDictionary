
#ifndef VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED
#define VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

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

inline std::ostream& operator<<(std::ostream& stream, const Virtual_Balise_Cover_order_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_VBCO << ','
       << +p.NID_VBCMK << ','
       << +p.NID_C << ','
       << +p.T_VBC;

    return stream;
}

inline bool operator==(const Virtual_Balise_Cover_order_Core& a, const Virtual_Balise_Cover_order_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_VBCO == b.Q_VBCO);
    status = status && (a.NID_VBCMK == b.NID_VBCMK);
    status = status && (a.NID_C == b.NID_C);
    if (a.Q_VBCO == 1)
    {
    status = status && (a.T_VBC == b.T_VBC);
    }

    return status;
}

inline bool operator!=(const Virtual_Balise_Cover_order_Core& a, const Virtual_Balise_Cover_order_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Virtual_Balise_Cover_order_Core Virtual_Balise_Cover_order_Core;

#define VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE 549

/*@
    logic integer BitSize{L}(Virtual_Balise_Cover_order_Core* p) = VIRTUAL_BALISE_COVER_ORDER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Virtual_Balise_Cover_order_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Virtual_Balise_Cover_order_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Virtual_Balise_Cover_order_Core* p) = \true;

    predicate ZeroInitialized(Virtual_Balise_Cover_order_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Virtual_Balise_Cover_order_Core* p) = \true;

    predicate UpperBitsNotSet(Virtual_Balise_Cover_order_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Virtual_Balise_Cover_order_UpperBitsNotSet(const Virtual_Balise_Cover_order_Core* p);

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
int Virtual_Balise_Cover_order_Encoder(Bitstream* stream, const Virtual_Balise_Cover_order_Core* p);

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
int Virtual_Balise_Cover_order_Decoder(Bitstream* stream, Virtual_Balise_Cover_order_Core* p);

#endif // VIRTUAL_BALISE_COVER_ORDER_CORE_H_INCLUDED

