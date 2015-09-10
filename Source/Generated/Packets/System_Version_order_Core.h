
#ifndef SYSTEM_VERSION_ORDER_CORE_H_INCLUDED
#define SYSTEM_VERSION_ORDER_CORE_H_INCLUDED

#include "Bitstream.h"

struct System_Version_order_Core
{
    // TransmissionMedia=Balise
    // This packet is used to tell the on-board which is the
    // operated system version
    // Packet Number = 2

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   M_VERSION;        // # 7
};

typedef struct System_Version_order_Core System_Version_order_Core;

#define SYSTEM_VERSION_ORDER_CORE_BITSIZE 22

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
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 22,  p->M_VERSION);

    predicate UpperBitsNotSet(System_Version_order_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_VERSION,        7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int System_Version_order_UpperBitsNotSet(const System_Version_order_Core* p);

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
int System_Version_order_Encoder(Bitstream* stream, const System_Version_order_Core* p);

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
int System_Version_order_Decoder(Bitstream* stream, System_Version_order_Core* p);

#ifdef __cplusplus

#include <iostream>

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

inline int encode(Bitstream& stream, const System_Version_order_Core& p)
{
    return System_Version_order_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, System_Version_order_Core& p)
{
    return System_Version_order_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // SYSTEM_VERSION_ORDER_CORE_H_INCLUDED

