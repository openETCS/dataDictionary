
#ifndef VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Validated_train_data_Core_2
{

    uint64_t   NID_STM;          // # 8
};

typedef struct Validated_train_data_Core_2 Validated_train_data_Core_2;

#define VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE 8

/*@
    logic integer BitSize{L}(Validated_train_data_Core_2* p) = VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core_2* p) =
      Invariant(p->NID_STM);

    predicate ZeroInitialized(Validated_train_data_Core_2* p) =
      ZeroInitialized(p->NID_STM);

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core_2* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_STM);

    predicate UpperBitsNotSet(Validated_train_data_Core_2* p) =
      UpperBitsNotSet(p->NID_STM,          8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Validated_train_data_Core_2_UpperBitsNotSet(const Validated_train_data_Core_2* p);

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
int Validated_train_data_Core_2_Encode_Bit(Bitstream* stream, const Validated_train_data_Core_2* p);

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
int Validated_train_data_Core_2_Decode_Bit(Bitstream* stream, Validated_train_data_Core_2* p);

int Validated_train_data_Core_2_Encode_Int(PacketInfo* data, kcg_int* stream, const Validated_train_data_Core_2* p);

int Validated_train_data_Core_2_Decode_Int(PacketInfo* data, const kcg_int* stream, Validated_train_data_Core_2* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core_2& p)
{
    stream
            << +p.NID_STM;

    return stream;
}

inline bool operator==(const Validated_train_data_Core_2& a, const Validated_train_data_Core_2& b)
{
    bool status = true;

    status = status && (a.NID_STM == b.NID_STM);

    return status;
}

inline bool operator!=(const Validated_train_data_Core_2& a, const Validated_train_data_Core_2& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Validated_train_data_Core_2& p)
{
    return Validated_train_data_Core_2_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Validated_train_data_Core_2& p)
{
    return Validated_train_data_Core_2_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Validated_train_data_Core_2& p)
{
    std::cerr << "encode int function not implemented for packet 11 yet." << std::endl;

    return Validated_train_data_Core_2_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Validated_train_data_Core_2& p)
{
    std::cerr << "decode int function not implemented for packet 11 yet." << std::endl;

    return Validated_train_data_Core_2_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED

