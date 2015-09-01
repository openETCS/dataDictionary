
#ifndef TRACK_CONDITION_CORE_H_INCLUDED
#define TRACK_CONDITION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Core_1.h"

struct Track_Condition_Core
{
    // TransmissionMedia=Any
    // The packet gives details concerning the track ahead to support the
    // driver when e.g. lower pantograph      
    // Packet Number = 68

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t   M_TRACKCOND;      // # 4
    uint64_t   N_ITER_1;         // # 5
    Track_Condition_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_TRACKCOND << ','
       << +p.L_TRACKCOND << ','
       << +p.M_TRACKCOND << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Track_Condition_Core& a, const Track_Condition_Core& b)
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
    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);
    status = status && (a.M_TRACKCOND == b.M_TRACKCOND);
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

inline bool operator!=(const Track_Condition_Core& a, const Track_Condition_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Core Track_Condition_Core;

#define TRACK_CONDITION_CORE_BITSIZE 18

/*@
    logic integer BitSize{L}(Track_Condition_Core* p) = TRACK_CONDITION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT);

    predicate ZeroInitialized(Track_Condition_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

    predicate UpperBitsNotSet(Track_Condition_Core* p) =
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
int Track_Condition_UpperBitsNotSet(const Track_Condition_Core* p);

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
int Track_Condition_Encoder(Bitstream* stream, const Track_Condition_Core* p);

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
int Track_Condition_Decoder(Bitstream* stream, Track_Condition_Core* p);

#endif // TRACK_CONDITION_CORE_H_INCLUDED

