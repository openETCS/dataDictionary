
#ifndef NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct National_Values_Core_2
{

    uint64_t   V_NVKVINT;        // # 7
    uint64_t   M_NVKVINT;        // # 7
};

typedef struct National_Values_Core_2 National_Values_Core_2;

#define NATIONAL_VALUES_CORE_2_CORE_BITSIZE 14

/*@
    logic integer BitSize{L}(National_Values_Core_2* p) = NATIONAL_VALUES_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core_2* p) =
      Invariant(p->V_NVKVINT)         &&
      Invariant(p->M_NVKVINT);

    predicate ZeroInitialized(National_Values_Core_2* p) =
      ZeroInitialized(p->V_NVKVINT)         &&
      ZeroInitialized(p->M_NVKVINT);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core_2* p) =
      EqualBits(stream, pos,       pos + 7,   p->V_NVKVINT)         &&
      EqualBits(stream, pos + 7,   pos + 14,  p->M_NVKVINT);

    predicate UpperBitsNotSet(National_Values_Core_2* p) =
      UpperBitsNotSet(p->V_NVKVINT,        7)   &&
      UpperBitsNotSet(p->M_NVKVINT,        7);

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
int National_Values_Core_2_Encode_Bit(Bitstream* stream, const National_Values_Core_2* p);

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
int National_Values_Core_2_Decode_Bit(Bitstream* stream, National_Values_Core_2* p);

int National_Values_Core_2_Encode_Int(PacketInfo* data, kcg_int* stream, const National_Values_Core_2* p);

int National_Values_Core_2_Decode_Int(PacketInfo* data, const kcg_int* stream, National_Values_Core_2* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core_2& p)
{
    stream
            << +p.V_NVKVINT << ','
            << +p.M_NVKVINT;

    return stream;
}

inline bool operator==(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    bool status = true;

    status = status && (a.V_NVKVINT == b.V_NVKVINT);
    status = status && (a.M_NVKVINT == b.M_NVKVINT);

    return status;
}

inline bool operator!=(const National_Values_Core_2& a, const National_Values_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // NATIONAL_VALUES_CORE_2_CORE_H_INCLUDED

