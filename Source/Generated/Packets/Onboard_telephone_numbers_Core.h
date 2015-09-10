
#ifndef ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Onboard_telephone_numbers_Core_1.h"

struct Onboard_telephone_numbers_Core
{
    // TransmissionMedia=RBC, RIU
    // Telephone numbers associated to the onboard equipment
    // Packet Number = 3

    uint64_t  L_PACKET;         // # 13
    uint64_t   N_ITER_1;         // # 5
    Onboard_telephone_numbers_Core_1   sub_1[31];
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Onboard_telephone_numbers_Core& p)
{
    stream
            << +p.L_PACKET << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Onboard_telephone_numbers_Core& a, const Onboard_telephone_numbers_Core& b)
{
    bool status = true;

    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.N_ITER_1 == b.N_ITER_1);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Onboard_telephone_numbers_Core& a, const Onboard_telephone_numbers_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Onboard_telephone_numbers_Core Onboard_telephone_numbers_Core;

#define ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE 18

/*@
    logic integer BitSize{L}(Onboard_telephone_numbers_Core* p) = ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Onboard_telephone_numbers_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Onboard_telephone_numbers_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Onboard_telephone_numbers_Core* p) =
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Onboard_telephone_numbers_Core* p) =
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Onboard_telephone_numbers_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET);

    predicate UpperBitsNotSet(Onboard_telephone_numbers_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Onboard_telephone_numbers_UpperBitsNotSet(const Onboard_telephone_numbers_Core* p);

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
int Onboard_telephone_numbers_Encoder(Bitstream* stream, const Onboard_telephone_numbers_Core* p);

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
int Onboard_telephone_numbers_Decoder(Bitstream* stream, Onboard_telephone_numbers_Core* p);

#endif // ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED

