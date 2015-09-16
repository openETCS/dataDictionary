
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Compressed_Packets.h"

struct Track_Condition_Big_Metal_Masses_Core_1
{

    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
};

typedef struct Track_Condition_Big_Metal_Masses_Core_1 Track_Condition_Big_Metal_Masses_Core_1;

#define TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Big_Metal_Masses_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Big_Metal_Masses_Core_1* p) =
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND);

    predicate ZeroInitialized(Track_Condition_Big_Metal_Masses_Core_1* p) =
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Big_Metal_Masses_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);

    predicate UpperBitsNotSet(Track_Condition_Big_Metal_Masses_Core_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Big_Metal_Masses_Core_1_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core_1* p);

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
int Track_Condition_Big_Metal_Masses_Core_1_Encode_Bit(Bitstream* stream, const Track_Condition_Big_Metal_Masses_Core_1* p);

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
int Track_Condition_Big_Metal_Masses_Core_1_Decode_Bit(Bitstream* stream, Track_Condition_Big_Metal_Masses_Core_1* p);

int Track_Condition_Big_Metal_Masses_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Track_Condition_Big_Metal_Masses_Core_1* p);

int Track_Condition_Big_Metal_Masses_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Track_Condition_Big_Metal_Masses_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Big_Metal_Masses_Core_1& p)
{
    stream
            << +p.D_TRACKCOND << ','
            << +p.L_TRACKCOND;

    return stream;
}

inline bool operator==(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    bool status = true;

    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);

    return status;
}

inline bool operator!=(const Track_Condition_Big_Metal_Masses_Core_1& a, const Track_Condition_Big_Metal_Masses_Core_1& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Track_Condition_Big_Metal_Masses_Core_1& p)
{
    return Track_Condition_Big_Metal_Masses_Core_1_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Track_Condition_Big_Metal_Masses_Core_1& p)
{
    return Track_Condition_Big_Metal_Masses_Core_1_Decode_Bit(&stream, &p);
}

inline int encode(Packet_Info& data, kcg_int* stream, kcg_int startAddress, const Track_Condition_Big_Metal_Masses_Core_1& p)
{
    return Track_Condition_Big_Metal_Masses_Core_1_Encode_Int(&data, stream, startAddress, &p);
}

inline int decode(const Packet_Info& data, const kcg_int* stream, Track_Condition_Big_Metal_Masses_Core_1& p)
{
    return Track_Condition_Big_Metal_Masses_Core_1_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // TRACK_CONDITION_BIG_METAL_MASSES_CORE_1_CORE_H_INCLUDED

