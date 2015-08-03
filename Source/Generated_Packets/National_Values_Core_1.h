
#ifndef NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct National_Values_Core_1
{

    uint16_t  NID_C_p;          // # 10
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_1& p)
{
    stream 
       << +p.NID_C_p;

    return stream;
}

inline bool operator==(const National_Values_Core_1& a, const National_Values_Core_1& b)
{
    bool status = true;
    
    status = status && (a.NID_C_p == b.NID_C_p);

    return status;
}

inline bool operator!=(const National_Values_Core_1& a, const National_Values_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_1 National_Values_Core_1;

#define NATIONAL_VALUES_CORE_1_CORE_BITSIZE 10

/*@
    logic integer BitSize{L}(National_Values_Core_1* p) = NATIONAL_VALUES_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_1* p) =
      Invariant(p->NID_C_p);

    predicate ZeroInitialized(National_Values_Core_1* p) =
      ZeroInitialized(p->NID_C_p);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_1* p) =
      EqualBits(stream, pos,       pos + 10,  p->NID_C_p);

    predicate UpperBitsNotSet(National_Values_Core_1* p) =
      UpperBitsNotSet(p->NID_C_p,          10);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_Core_1_UpperBitsNotSet(const National_Values_Core_1* p);

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
int National_Values_Core_1_Encoder(Bitstream* stream, const National_Values_Core_1* p);

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
int National_Values_Core_1_Decoder(Bitstream* stream, National_Values_Core_1* p);

#endif // NATIONAL_VALUES_CORE_1_CORE_H_INCLUDED

