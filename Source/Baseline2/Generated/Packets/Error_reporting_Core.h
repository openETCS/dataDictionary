
#ifndef ERROR_REPORTING_CORE_H_INCLUDED
#define ERROR_REPORTING_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Error_reporting_Core
{
    // TransmissionMedia=Radio
    // Error reporting to the RBC
    // Packet Number = 4

    uint64_t  L_PACKET;         // # 13
    uint64_t   M_ERROR;          // # 8
};

typedef struct Error_reporting_Core Error_reporting_Core;

#define ERROR_REPORTING_CORE_BITSIZE 21

/*@
    logic integer BitSize{L}(Error_reporting_Core* p) = ERROR_REPORTING_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Error_reporting_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Error_reporting_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Error_reporting_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_ERROR);

    predicate ZeroInitialized(Error_reporting_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_ERROR);

    predicate EqualBits(Bitstream* stream, integer pos, Error_reporting_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

    predicate UpperBitsNotSet(Error_reporting_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_ERROR,          8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Error_reporting_UpperBitsNotSet(const Error_reporting_Core* p);

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
int Error_reporting_Encode_Bit(Bitstream* stream, const Error_reporting_Core* p);

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
int Error_reporting_Decode_Bit(Bitstream* stream, Error_reporting_Core* p);

int Error_reporting_Encode_Int(PacketInfo* data, kcg_int* stream, const Error_reporting_Core* p);

int Error_reporting_Decode_Int(PacketInfo* data, const kcg_int* stream, Error_reporting_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Error_reporting_Core& p)
{
    stream
            << +p.L_PACKET << ','
            << +p.M_ERROR;

    return stream;
}

inline bool operator==(const Error_reporting_Core& a, const Error_reporting_Core& b)
{
    bool status = true;

    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.M_ERROR == b.M_ERROR);

    return status;
}

inline bool operator!=(const Error_reporting_Core& a, const Error_reporting_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Error_reporting_Core& p)
{
    return Error_reporting_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Error_reporting_Core& p)
{
    return Error_reporting_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Error_reporting_Core& p)
{
    return Error_reporting_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Error_reporting_Core& p)
{
    return Error_reporting_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // ERROR_REPORTING_CORE_H_INCLUDED

