
#ifndef NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct National_Values_Core_2
{

    uint8_t   V_NVKVINT_n;      // # 7
    uint8_t   M_NVKVINT_n;      // # 7
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_2& p)
{
    stream 
       << +p.V_NVKVINT_n << ','
       << +p.M_NVKVINT_n;

    return stream;
}

inline bool operator==(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    bool status = true;
    
    status = status && (a.V_NVKVINT_n == b.V_NVKVINT_n);
    status = status && (a.M_NVKVINT_n == b.M_NVKVINT_n);

    return status;
}

inline bool operator!=(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core_2 National_Values_Core_2;

#define NATIONAL_VALUES_CORE_2_CORE_BITSIZE 24

/*@
    logic integer BitSize{L}(National_Values_Core_2* p) = NATIONAL_VALUES_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_2* p) = \true;

    predicate ZeroInitialized(National_Values_Core_2* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_2* p) = \true;

    predicate UpperBitsNotSet(National_Values_Core_2* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_Core_2_UpperBitsNotSet(const National_Values_Core_2* p);

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
int National_Values_Core_2_Encoder(Bitstream* stream, const National_Values_Core_2* p);

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
int National_Values_Core_2_Decoder(Bitstream* stream, National_Values_Core_2* p);

#endif // NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

