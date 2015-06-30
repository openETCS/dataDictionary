
#ifndef ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Onboard_telephone_numbers_Core_1
{

    uint64_t  NID_RADIO_k;      // # 64
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Onboard_telephone_numbers_Core_1& p)
{
    stream 
       << +p.NID_RADIO_k;

    return stream;
}

inline bool operator==(const Onboard_telephone_numbers_Core_1& a, const Onboard_telephone_numbers_Core_1& b)
{
    bool status = true;
    
    status = status && (a.NID_RADIO_k == b.NID_RADIO_k);

    return status;
}

inline bool operator!=(const Onboard_telephone_numbers_Core_1& a, const Onboard_telephone_numbers_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Onboard_telephone_numbers_Core_1 Onboard_telephone_numbers_Core_1;

#define ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE 4537

/*@
    logic integer BitSize{L}(Onboard_telephone_numbers_Core_1* p) = ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Onboard_telephone_numbers_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Onboard_telephone_numbers_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Onboard_telephone_numbers_Core_1* p) = \true;

    predicate ZeroInitialized(Onboard_telephone_numbers_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Onboard_telephone_numbers_Core_1* p) = \true;

    predicate UpperBitsNotSet(Onboard_telephone_numbers_Core_1* p) = \true;

*/

#endif // ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED

