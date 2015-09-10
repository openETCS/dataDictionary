
#ifndef ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Onboard_telephone_numbers_Core_1
{

    uint64_t  NID_RADIO;        // # 64
};

typedef struct Onboard_telephone_numbers_Core_1 Onboard_telephone_numbers_Core_1;

#define ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE 64

/*@
    logic integer BitSize{L}(Onboard_telephone_numbers_Core_1* p) = ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Onboard_telephone_numbers_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Onboard_telephone_numbers_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Onboard_telephone_numbers_Core_1* p) =
      Invariant(p->NID_RADIO);

    predicate ZeroInitialized(Onboard_telephone_numbers_Core_1* p) =
      ZeroInitialized(p->NID_RADIO);

    predicate EqualBits(Bitstream* stream, integer pos, Onboard_telephone_numbers_Core_1* p) =
      EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

    predicate UpperBitsNotSet(Onboard_telephone_numbers_Core_1* p) =
      UpperBitsNotSet(p->NID_RADIO,        64);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Onboard_telephone_numbers_Core_1_UpperBitsNotSet(const Onboard_telephone_numbers_Core_1* p);

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
int Onboard_telephone_numbers_Core_1_Encoder(Bitstream* stream, const Onboard_telephone_numbers_Core_1* p);

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
int Onboard_telephone_numbers_Core_1_Decoder(Bitstream* stream, Onboard_telephone_numbers_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Onboard_telephone_numbers_Core_1& p)
{
    stream
            << +p.NID_RADIO;

    return stream;
}

inline bool operator==(const Onboard_telephone_numbers_Core_1& a, const Onboard_telephone_numbers_Core_1& b)
{
    bool status = true;

    status = status && (a.NID_RADIO == b.NID_RADIO);

    return status;
}

inline bool operator!=(const Onboard_telephone_numbers_Core_1& a, const Onboard_telephone_numbers_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Onboard_telephone_numbers_Core_1& p)
{
    return Onboard_telephone_numbers_Core_1_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, Onboard_telephone_numbers_Core_1& p)
{
    return Onboard_telephone_numbers_Core_1_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_H_INCLUDED

