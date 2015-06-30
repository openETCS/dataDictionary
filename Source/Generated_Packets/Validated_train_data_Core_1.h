
#ifndef VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Validated_train_data_Core_1
{

    uint8_t   M_VOLTAGE_k;      // # 4
    uint16_t  NID_CTRACTION_k;  // # 10
};

#ifdef __cplusplus

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

#define VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE 4737

/*@
    logic integer BitSize{L}(Validated_train_data_Core_1* p) = VALIDATED_TRAIN_DATA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core_1* p) = \true;

    predicate ZeroInitialized(Validated_train_data_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core_1* p) = \true;

    predicate UpperBitsNotSet(Validated_train_data_Core_1* p) = \true;

*/

#endif // VALIDATED_TRAIN_DATA_CORE_1_CORE_H_INCLUDED

