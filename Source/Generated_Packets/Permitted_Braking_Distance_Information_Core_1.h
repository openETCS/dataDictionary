
#ifndef PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED
#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Permitted_Braking_Distance_Information_Core_1
{

    uint16_t  D_PBD_k;          // # 15
    uint8_t   Q_GDIR_k;         // # 1
    uint8_t   G_PBDSR_k;        // # 8
    uint8_t   Q_PBDSR_k;        // # 1
    uint16_t  D_PBDSR_k;        // # 15
    uint16_t  L_PBDSR_k;        // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Permitted_Braking_Distance_Information_Core_1& p)
{
    stream 
       << +p.D_PBD_k << ','
       << +p.Q_GDIR_k << ','
       << +p.G_PBDSR_k << ','
       << +p.Q_PBDSR_k << ','
       << +p.D_PBDSR_k << ','
       << +p.L_PBDSR_k;

    return stream;
}

inline bool operator==(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_PBD_k == b.D_PBD_k);
    status = status && (a.Q_GDIR_k == b.Q_GDIR_k);
    status = status && (a.G_PBDSR_k == b.G_PBDSR_k);
    status = status && (a.Q_PBDSR_k == b.Q_PBDSR_k);
    status = status && (a.D_PBDSR_k == b.D_PBDSR_k);
    status = status && (a.L_PBDSR_k == b.L_PBDSR_k);

    return status;
}

inline bool operator!=(const Permitted_Braking_Distance_Information_Core_1& a, const Permitted_Braking_Distance_Information_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Permitted_Braking_Distance_Information_Core_1 Permitted_Braking_Distance_Information_Core_1;

#define PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Permitted_Braking_Distance_Information_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Permitted_Braking_Distance_Information_Core_1* p) =
      Invariant(p->D_PBD_k)           &&
      Invariant(p->Q_GDIR_k)          &&
      Invariant(p->G_PBDSR_k)         &&
      Invariant(p->Q_PBDSR_k)         &&
      Invariant(p->D_PBDSR_k)         &&
      Invariant(p->L_PBDSR_k);

    predicate ZeroInitialized(Permitted_Braking_Distance_Information_Core_1* p) =
      ZeroInitialized(p->D_PBD_k)           &&
      ZeroInitialized(p->Q_GDIR_k)          &&
      ZeroInitialized(p->G_PBDSR_k)         &&
      ZeroInitialized(p->Q_PBDSR_k)         &&
      ZeroInitialized(p->D_PBDSR_k)         &&
      ZeroInitialized(p->L_PBDSR_k);

    predicate EqualBits(Bitstream* stream, integer pos, Permitted_Braking_Distance_Information_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_PBD_k)           &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR_k)          &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_PBDSR_k)         &&
      EqualBits(stream, pos + 24,  pos + 25,  p->Q_PBDSR_k)         &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_PBDSR_k)         &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_PBDSR_k);

    predicate UpperBitsNotSet(Permitted_Braking_Distance_Information_Core_1* p) =
      UpperBitsNotSet(p->D_PBD_k,          15)  &&
      UpperBitsNotSet(p->Q_GDIR_k,         1)   &&
      UpperBitsNotSet(p->G_PBDSR_k,        8)   &&
      UpperBitsNotSet(p->Q_PBDSR_k,        1)   &&
      UpperBitsNotSet(p->D_PBDSR_k,        15)  &&
      UpperBitsNotSet(p->L_PBDSR_k,        15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Permitted_Braking_Distance_Information_Core_1_UpperBitsNotSet(const Permitted_Braking_Distance_Information_Core_1* p);

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
int Permitted_Braking_Distance_Information_Core_1_Encoder(Bitstream* stream, const Permitted_Braking_Distance_Information_Core_1* p);

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
int Permitted_Braking_Distance_Information_Core_1_Decoder(Bitstream* stream, Permitted_Braking_Distance_Information_Core_1* p);

#endif // PERMITTED_BRAKING_DISTANCE_INFORMATION_CORE_1_CORE_H_INCLUDED

