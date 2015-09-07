
#ifndef INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED

#include "Bitstream.h"

struct Infill_location_reference_Core
{
    // TransmissionMedia=Balise, Loop, RIU
    // Defines location reference for all data contained in the same radio
    // message or balise/loop telegram respectively, following this packet.
    // Packet Number = 136

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Infill_location_reference_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_NEWCOUNTRY << ','
            << +p.NID_C << ','
            << +p.NID_BG;

    return stream;
}

inline bool operator==(const Infill_location_reference_Core& a, const Infill_location_reference_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);

    if (a.Q_NEWCOUNTRY == 1)
    {
        status = status && (a.NID_C == b.NID_C);
    }

    status = status && (a.NID_BG == b.NID_BG);

    return status;
}

inline bool operator!=(const Infill_location_reference_Core& a, const Infill_location_reference_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Infill_location_reference_Core Infill_location_reference_Core;

#define INFILL_LOCATION_REFERENCE_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Infill_location_reference_Core* p) = INFILL_LOCATION_REFERENCE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Infill_location_reference_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Infill_location_reference_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Infill_location_reference_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Infill_location_reference_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Infill_location_reference_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Infill_location_reference_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Infill_location_reference_UpperBitsNotSet(const Infill_location_reference_Core* p);

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
int Infill_location_reference_Encoder(Bitstream* stream, const Infill_location_reference_Core* p);

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
int Infill_location_reference_Decoder(Bitstream* stream, Infill_location_reference_Core* p);

#endif // INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED

