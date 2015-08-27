
#ifndef NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED

#include "Bitstream.h"

struct National_Values_Core_4
{

    uint64_t  L_NVKRINT;        // # 5
    uint64_t   M_NVKRINT;        // # 5
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_4& p)
{
    stream 
       << +p.L_NVKRINT << ','
       << +p.M_NVKRINT;

    return stream;
}

inline bool operator==(const National_Values_Core_4& a, const National_Values_Core_4& b)
{
    bool status = true;
    
    status = status && (a.L_NVKRINT == b.L_NVKRINT);
    status = status && (a.M_NVKRINT == b.M_NVKRINT);

    return status;
}

inline bool operator!=(const National_Values_Core_4& a, const National_Values_Core_4& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_4 National_Values_Core_4;

#define NATIONAL_VALUES_CORE_4_CORE_BITSIZE 10

/*@
    logic integer BitSize{L}(National_Values_Core_4* p) = NATIONAL_VALUES_CORE_4_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_4* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_4* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_4* p) =
      Invariant(p->L_NVKRINT)         &&
      Invariant(p->M_NVKRINT);

    predicate ZeroInitialized(National_Values_Core_4* p) =
      ZeroInitialized(p->L_NVKRINT)         &&
      ZeroInitialized(p->M_NVKRINT);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_4* p) =
      EqualBits(stream, pos,       pos + 5,   p->L_NVKRINT)         &&
      EqualBits(stream, pos + 5,   pos + 10,  p->M_NVKRINT);

    predicate UpperBitsNotSet(National_Values_Core_4* p) =
      UpperBitsNotSet(p->L_NVKRINT,        5)   &&
      UpperBitsNotSet(p->M_NVKRINT,        5);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_Core_4_UpperBitsNotSet(const National_Values_Core_4* p);

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
int National_Values_Core_4_Encoder(Bitstream* stream, const National_Values_Core_4* p);

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
int National_Values_Core_4_Decoder(Bitstream* stream, National_Values_Core_4* p);

#endif // NATIONAL_VALUES_CORE_4_CORE_H_INCLUDED

