
#ifndef VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Validated_train_data_Core_2
{

    uint8_t   NID_NTC_n;        // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core_2& p)
{
    stream 
       << +p.NID_NTC_n;

    return stream;
}

inline bool operator==(const Validated_train_data_Core_2& a, const Validated_train_data_Core_2& b)
{
    bool status = true;
    
    status = status && (a.NID_NTC_n == b.NID_NTC_n);

    return status;
}

inline bool operator!=(const Validated_train_data_Core_2& a, const Validated_train_data_Core_2& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Validated_train_data_Core_2 Validated_train_data_Core_2;

#define VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE 4750

/*@
    logic integer BitSize{L}(Validated_train_data_Core_2* p) = VALIDATED_TRAIN_DATA_CORE_2_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core_2* p) = \true;

    predicate ZeroInitialized(Validated_train_data_Core_2* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core_2* p) = \true;

    predicate UpperBitsNotSet(Validated_train_data_Core_2* p) = \true;

*/

#endif // VALIDATED_TRAIN_DATA_CORE_2_CORE_H_INCLUDED

