
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"

struct Default_balise_or_Loop_or_RIU_information_Core
{
    // TransmissionMedia=Balise, Loop, RIU
    // Indication to on-board that balise telegram, loop message or RIU information
    // contains default information due to a fault of the trackside equipment.
    // Packet Number = 254

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
};

typedef struct Default_balise_or_Loop_or_RIU_information_Core Default_balise_or_Loop_or_RIU_information_Core;

#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE 15

/*@
    logic integer BitSize{L}(Default_balise_or_Loop_or_RIU_information_Core* p) = DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Default_balise_or_Loop_or_RIU_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_balise_or_Loop_or_RIU_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Default_balise_or_Loop_or_RIU_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Default_balise_or_Loop_or_RIU_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(Default_balise_or_Loop_or_RIU_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(const Default_balise_or_Loop_or_RIU_information_Core* p);

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
int Default_balise_or_Loop_or_RIU_information_Encoder(Bitstream* stream, const Default_balise_or_Loop_or_RIU_information_Core* p);

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
int Default_balise_or_Loop_or_RIU_information_Decoder(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Default_balise_or_Loop_or_RIU_information_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET;

    return stream;
}

inline bool operator==(const Default_balise_or_Loop_or_RIU_information_Core& a, const Default_balise_or_Loop_or_RIU_information_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);

    return status;
}

inline bool operator!=(const Default_balise_or_Loop_or_RIU_information_Core& a, const Default_balise_or_Loop_or_RIU_information_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Default_balise_or_Loop_or_RIU_information_Core& p)
{
    return Default_balise_or_Loop_or_RIU_information_Encoder(&stream, &p);
}

inline int decode(Bitstream& stream, Default_balise_or_Loop_or_RIU_information_Core& p)
{
    return Default_balise_or_Loop_or_RIU_information_Decoder(&stream, &p);
}

#endif // __cplusplus

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED

