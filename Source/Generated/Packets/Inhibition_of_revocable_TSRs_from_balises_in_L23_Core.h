
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Core
{
    // TransmissionMedia=RBC
    // This packet is used to inhibit revocable TSRs from balises in
    // level 2 or 3.
    // Packet Number = 64

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
};

typedef struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Core Inhibition_of_revocable_TSRs_from_balises_in_L23_Core;

#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE 15

/*@
    logic integer BitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Inhibition_of_revocable_TSRs_from_balises_in_L23_UpperBitsNotSet(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

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
int Inhibition_of_revocable_TSRs_from_balises_in_L23_Encode_Bit(Bitstream* stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

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
int Inhibition_of_revocable_TSRs_from_balises_in_L23_Decode_Bit(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

int Inhibition_of_revocable_TSRs_from_balises_in_L23_Decode_Int(const Packet_Info* data, const kcg_int* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET;

    return stream;
}

inline bool operator==(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& a, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);

    return status;
}

inline bool operator!=(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& a, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    return Inhibition_of_revocable_TSRs_from_balises_in_L23_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    return Inhibition_of_revocable_TSRs_from_balises_in_L23_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    return Inhibition_of_revocable_TSRs_from_balises_in_L23_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    return Inhibition_of_revocable_TSRs_from_balises_in_L23_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED

