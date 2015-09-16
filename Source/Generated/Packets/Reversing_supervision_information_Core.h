
#ifndef REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Reversing_supervision_information_Core
{
    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing
    // area to the on-board
    // Packet Number = 139

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_REVERSE;        // # 15
    uint64_t   V_REVERSE;        // # 7
};

typedef struct Reversing_supervision_information_Core Reversing_supervision_information_Core;

#define REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE 39

/*@
    logic integer BitSize{L}(Reversing_supervision_information_Core* p) = REVERSING_SUPERVISION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_supervision_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_supervision_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_supervision_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_REVERSE)         &&
      Invariant(p->V_REVERSE);

    predicate ZeroInitialized(Reversing_supervision_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_REVERSE)         &&
      ZeroInitialized(p->V_REVERSE);

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_supervision_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE)         &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

    predicate UpperBitsNotSet(Reversing_supervision_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_REVERSE,        15)  &&
      UpperBitsNotSet(p->V_REVERSE,        7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Reversing_supervision_information_UpperBitsNotSet(const Reversing_supervision_information_Core* p);

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
int Reversing_supervision_information_Encode_Bit(Bitstream* stream, const Reversing_supervision_information_Core* p);

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
int Reversing_supervision_information_Decode_Bit(Bitstream* stream, Reversing_supervision_information_Core* p);

int Reversing_supervision_information_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Reversing_supervision_information_Core* p);

int Reversing_supervision_information_Decode_Int(const Packet_Info* data, const kcg_int* stream, Reversing_supervision_information_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Reversing_supervision_information_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.D_REVERSE << ','
            << +p.V_REVERSE;

    return stream;
}

inline bool operator==(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_REVERSE == b.D_REVERSE);
    status = status && (a.V_REVERSE == b.V_REVERSE);

    return status;
}

inline bool operator!=(const Reversing_supervision_information_Core& a, const Reversing_supervision_information_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Reversing_supervision_information_Core& p)
{
    return Reversing_supervision_information_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Reversing_supervision_information_Core& p)
{
    return Reversing_supervision_information_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Reversing_supervision_information_Core& p)
{
    return Reversing_supervision_information_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Reversing_supervision_information_Core& p)
{
    return Reversing_supervision_information_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // REVERSING_SUPERVISION_INFORMATION_CORE_H_INCLUDED

