
#ifndef VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Validated_train_data_Core_1
{

    uint64_t   M_VOLTAGE;        // # 4
    uint64_t  NID_CTRACTION;    // # 10
};

typedef struct Validated_train_data_Core_1 Validated_train_data_Core_1;

#define VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE 4

/*@
    logic integer BitSize{L}(Validated_train_data_Core_1* p) = VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core_1* p) =
      Invariant(p->M_VOLTAGE);

    predicate ZeroInitialized(Validated_train_data_Core_1* p) =
      ZeroInitialized(p->M_VOLTAGE);

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core_1* p) =
      EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE);

    predicate UpperBitsNotSet(Validated_train_data_Core_1* p) =
      UpperBitsNotSet(p->M_VOLTAGE,        4);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Validated_train_data_Core_1_UpperBitsNotSet(const Validated_train_data_Core_1* p);

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
int Validated_train_data_Core_1_Encode_Bit(Bitstream* stream, const Validated_train_data_Core_1* p);

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
int Validated_train_data_Core_1_Decode_Bit(Bitstream* stream, Validated_train_data_Core_1* p);

int Validated_train_data_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Validated_train_data_Core_1* p);

int Validated_train_data_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Validated_train_data_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core_1& p)
{
    stream
            << +p.M_VOLTAGE << ','
            << +p.NID_CTRACTION;

    return stream;
}

inline bool operator==(const Validated_train_data_Core_1& a, const Validated_train_data_Core_1& b)
{
    bool status = true;

    status = status && (a.M_VOLTAGE == b.M_VOLTAGE);

    if ((a.M_VOLTAGE != 0) && (a.NID_CTRACTION != 0))
    {
        status = status && (a.NID_CTRACTION == b.NID_CTRACTION);
    }

    return status;
}

inline bool operator!=(const Validated_train_data_Core_1& a, const Validated_train_data_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

