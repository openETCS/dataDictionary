
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Track_Condition_Big_Metal_Masses_Core_1
{

    uint16_t  D_TRACKCOND_k;    // # 15
    uint16_t  L_TRACKCOND_k;    // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Big_Metal_Masses_Core_1& p)
{
    stream 
       << +p.D_TRACKCOND_k << ','
       << +p.L_TRACKCOND_k;

    return stream;
}

inline bool operator==(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_TRACKCOND_k == b.D_TRACKCOND_k);
    status = status && (a.L_TRACKCOND_k == b.L_TRACKCOND_k);

    return status;
}

inline bool operator!=(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Big_Metal_Masses_Core_1 Track_Condition_Big_Metal_Masses_Core_1;

#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Big_Metal_Masses_Core_1* p) =
      Invariant(p->D_TRACKCOND_k)     &&
      Invariant(p->L_TRACKCOND_k);

    predicate ZeroInitialized(Track_Condition_Big_Metal_Masses_Core_1* p) =
      ZeroInitialized(p->D_TRACKCOND_k)     &&
      ZeroInitialized(p->L_TRACKCOND_k);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Big_Metal_Masses_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND_k)     &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND_k);

    predicate UpperBitsNotSet(Track_Condition_Big_Metal_Masses_Core_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND_k,    15)  &&
      UpperBitsNotSet(p->L_TRACKCOND_k,    15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core_1* p);

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
int Track_Condition_Big_Metal_Masses_Core_1_Encoder(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core_1* p);

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
int Track_Condition_Big_Metal_Masses_Core_1_Decoder(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p);

#endif // TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

