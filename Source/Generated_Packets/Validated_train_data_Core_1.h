
#ifndef VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Validated_train_data_Core_1
{

    uint8_t   M_VOLTAGE_k;      // # 4
    uint16_t  NID_CTRACTION_k;  // # 10
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core_1& p)
{
    stream 
       << +p.M_VOLTAGE_k << ','
       << +p.NID_CTRACTION_k;

    return stream;
}

inline bool operator==(const Validated_train_data_Core_1& a, const Validated_train_data_Core_1& b)
{
    bool status = true;
    
    status = status && (a.M_VOLTAGE_k == b.M_VOLTAGE_k);
    if ((a.M_VOLTAGE_k != 0) && (a.NID_CTRACTION_k != 0))
    {
    status = status && (a.NID_CTRACTION_k == b.NID_CTRACTION_k);
    }

    return status;
}

inline bool operator!=(const Validated_train_data_Core_1& a, const Validated_train_data_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Validated_train_data_Core_1 Validated_train_data_Core_1;

#define VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE 4

/*@
    logic integer BitSize{L}(Validated_train_data_Core_1* p) = VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core_1* p) =
      Invariant(p->M_VOLTAGE_k);

    predicate ZeroInitialized(Validated_train_data_Core_1* p) =
      ZeroInitialized(p->M_VOLTAGE_k);

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core_1* p) =
      EqualBits(stream, pos,       pos + 4,   p->M_VOLTAGE_k);

    predicate UpperBitsNotSet(Validated_train_data_Core_1* p) =
      UpperBitsNotSet(p->M_VOLTAGE_k,      4);

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
int Validated_train_data_Core_1_Encoder(Bitstream* stream, const Validated_train_data_Core_1* p);

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
int Validated_train_data_Core_1_Decoder(Bitstream* stream, Validated_train_data_Core_1* p);

#endif // VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

