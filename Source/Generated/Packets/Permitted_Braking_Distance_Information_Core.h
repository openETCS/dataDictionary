
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Permitted_Braking_Distance_Information_Core_1.h"

struct Permitted_Braking_Distance_Information_Core
{
    // TransmissionMedia=Any
    // This packet requests the on-board calculation of speed restrictions which ensure
    // a given permitted brake distance in case of an EB, or
    // SB, intervention
    // Packet Number = 52

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_PBD;            // # 15
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_PBDSR;          // # 8
    uint64_t   Q_PBDSR;          // # 1
    uint64_t  D_PBDSR;          // # 15
    uint64_t  L_PBDSR;          // # 15
    uint64_t   N_ITER_1;         // # 5
    Permitted_Braking_Distance_Information_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Permitted_Braking_Distance_Information_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.Q_TRACKINIT << ','
            << +p.D_TRACKINIT << ','
            << +p.D_PBD << ','
            << +p.Q_GDIR << ','
            << +p.G_PBDSR << ','
            << +p.Q_PBDSR << ','
            << +p.D_PBDSR << ','
            << +p.L_PBDSR << ','
            << +p.N_ITER_1;

    for (uint32_t i = 0; i < p.N_ITER_1; ++i)
    {
        stream << ',' << p.sub_1[i];
    }


    return stream;
}

inline bool operator==(const Permitted_Braking_Distance_Information_Core& a, const Permitted_Braking_Distance_Information_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_TRACKINIT == b.Q_TRACKINIT);

    if (a.Q_TRACKINIT == 1)
    {
        status = status && (a.D_TRACKINIT == b.D_TRACKINIT);
    }

    if (a.Q_TRACKINIT == 0)
    {
        status = status && (a.D_PBD == b.D_PBD);
        status = status && (a.Q_GDIR == b.Q_GDIR);
        status = status && (a.G_PBDSR == b.G_PBDSR);
        status = status && (a.Q_PBDSR == b.Q_PBDSR);
        status = status && (a.D_PBDSR == b.D_PBDSR);
        status = status && (a.L_PBDSR == b.L_PBDSR);
        status = status && (a.N_ITER_1 == b.N_ITER_1);

        if (a.N_ITER_1 == b.N_ITER_1)
        {
            for (uint32_t i = 0; i < a.N_ITER_1; ++i)
            {
                status = status && (a.sub_1[i] == b.sub_1[i]);
            }
        }
        else
        {
            status = false;
        }
    }

    return status;
}

inline bool operator!=(const Permitted_Braking_Distance_Information_Core& a, const Permitted_Braking_Distance_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Permitted_Braking_Distance_Information_Core Permitted_Braking_Distance_Information_Core;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE 18

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information_Core* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT);

    predicate ZeroInitialized(Permitted_Braking_Distance_Information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT);

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Permitted_Braking_Distance_Information_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core* p);

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
int Permitted_Braking_Distance_Information_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core* p);

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
int Permitted_Braking_Distance_Information_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core* p);

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_H_INCLUDED

