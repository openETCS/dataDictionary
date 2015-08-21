
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_CORE_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Big_Metal_Masses_Core_1.h"

struct Track_Condition_Big_Metal_Masses_Core
{
    // TransmissionMedia=Balise
    // The packet gives details concerning where to ignore integrity check alarms
    // of balise transmission due to big metal masses trackside.  
    // Packet Number = 67

    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t   N_ITER_1;         // # 5
    Track_Condition_Big_Metal_Masses_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Big_Metal_Masses_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_TRACKCOND << ','
       << +p.L_TRACKCOND << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Track_Condition_Big_Metal_Masses_Core& a, const Track_Condition_Big_Metal_Masses_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);
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

    return status;
}

inline bool operator!=(const Track_Condition_Big_Metal_Masses_Core& a, const Track_Condition_Big_Metal_Masses_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Big_Metal_Masses_Core Track_Condition_Big_Metal_Masses_Core;

#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_BITSIZE 52

/*@
    logic integer BitSize{L}(Track_Condition_Big_Metal_Masses_Core* p) = TRACK_CONDITION_BIG_METAL_MASSES_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Big_Metal_Masses_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Big_Metal_Masses_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND);

    predicate ZeroInitialized(Track_Condition_Big_Metal_Masses_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Big_Metal_Masses_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_TRACKCOND);

    predicate UpperBitsNotSet(Track_Condition_Big_Metal_Masses_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Big_Metal_Masses_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core* p);

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
int Track_Condition_Big_Metal_Masses_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core* p);

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
int Track_Condition_Big_Metal_Masses_Decoder(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core* p);

#endif // TRACK_CONDITION_BIG_METAL_MASSES_CORE_H_INCLUDED

