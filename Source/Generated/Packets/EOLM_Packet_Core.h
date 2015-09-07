
#ifndef EOLM_PACKET_CORE_H_INCLUDED
#define EOLM_PACKET_CORE_H_INCLUDED

#include "Bitstream.h"

struct EOLM_Packet_Core
{
    // TransmissionMedia=Balise
    // This packet announces a loop.
    // Packet Number = 134

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  NID_LOOP;         // # 14
    uint64_t  D_LOOP;           // # 15
    uint64_t  L_LOOP;           // # 15
    uint64_t   Q_LOOPDIR;        // # 1
    uint64_t   Q_SSCODE;         // # 4
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const EOLM_Packet_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.NID_LOOP << ','
            << +p.D_LOOP << ','
            << +p.L_LOOP << ','
            << +p.Q_LOOPDIR << ','
            << +p.Q_SSCODE;

    return stream;
}

inline bool operator==(const EOLM_Packet_Core& a, const EOLM_Packet_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.NID_LOOP == b.NID_LOOP);
    status = status && (a.D_LOOP == b.D_LOOP);
    status = status && (a.L_LOOP == b.L_LOOP);
    status = status && (a.Q_LOOPDIR == b.Q_LOOPDIR);
    status = status && (a.Q_SSCODE == b.Q_SSCODE);

    return status;
}

inline bool operator!=(const EOLM_Packet_Core& a, const EOLM_Packet_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct EOLM_Packet_Core EOLM_Packet_Core;

#define EOLM_PACKET_CORE_BITSIZE 66

/*@
    logic integer BitSize{L}(EOLM_Packet_Core* p) = EOLM_PACKET_CORE_BITSIZE;

    logic integer MaxBitSize{L}(EOLM_Packet_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, EOLM_Packet_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(EOLM_Packet_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_LOOP)          &&
      Invariant(p->D_LOOP)            &&
      Invariant(p->L_LOOP)            &&
      Invariant(p->Q_LOOPDIR)         &&
      Invariant(p->Q_SSCODE);

    predicate ZeroInitialized(EOLM_Packet_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_LOOP)          &&
      ZeroInitialized(p->D_LOOP)            &&
      ZeroInitialized(p->L_LOOP)            &&
      ZeroInitialized(p->Q_LOOPDIR)         &&
      ZeroInitialized(p->Q_SSCODE);

    predicate EqualBits(Bitstream* stream, integer pos, EOLM_Packet_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP)          &&
      EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP)            &&
      EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP)            &&
      EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR)         &&
      EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

    predicate UpperBitsNotSet(EOLM_Packet_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_LOOP,         14)  &&
      UpperBitsNotSet(p->D_LOOP,           15)  &&
      UpperBitsNotSet(p->L_LOOP,           15)  &&
      UpperBitsNotSet(p->Q_LOOPDIR,        1)   &&
      UpperBitsNotSet(p->Q_SSCODE,         4);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int EOLM_Packet_UpperBitsNotSet(const EOLM_Packet_Core* p);

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
int EOLM_Packet_Encoder(Bitstream* stream, const EOLM_Packet_Core* p);

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
int EOLM_Packet_Decoder(Bitstream* stream, EOLM_Packet_Core* p);

#endif // EOLM_PACKET_CORE_H_INCLUDED

