
#ifndef TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_H_INCLUDED
#define TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Track_Condition_Station_Platforms_Core_1
{

    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t   M_PLATFORM;       // # 4
    uint64_t   Q_PLATFORM;       // # 2
};

typedef struct Track_Condition_Station_Platforms_Core_1 Track_Condition_Station_Platforms_Core_1;

#define TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_BITSIZE 36

/*@
    logic integer BitSize{L}(Track_Condition_Station_Platforms_Core_1* p) = TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Station_Platforms_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Station_Platforms_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Station_Platforms_Core_1* p) =
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND)       &&
      Invariant(p->M_PLATFORM)        &&
      Invariant(p->Q_PLATFORM);

    predicate ZeroInitialized(Track_Condition_Station_Platforms_Core_1* p) =
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND)       &&
      ZeroInitialized(p->M_PLATFORM)        &&
      ZeroInitialized(p->Q_PLATFORM);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Station_Platforms_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND)       &&
      EqualBits(stream, pos + 30,  pos + 34,  p->M_PLATFORM)        &&
      EqualBits(stream, pos + 34,  pos + 36,  p->Q_PLATFORM);

    predicate UpperBitsNotSet(Track_Condition_Station_Platforms_Core_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->M_PLATFORM,       4)   &&
      UpperBitsNotSet(p->Q_PLATFORM,       2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Station_Platforms_Core_1_UpperBitsNotSet(const Track_Condition_Station_Platforms_Core_1* p);

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
int Track_Condition_Station_Platforms_Core_1_Encode_Bit(Bitstream* stream, const Track_Condition_Station_Platforms_Core_1* p);

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
int Track_Condition_Station_Platforms_Core_1_Decode_Bit(Bitstream* stream, Track_Condition_Station_Platforms_Core_1* p);

int Track_Condition_Station_Platforms_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Track_Condition_Station_Platforms_Core_1* p);

int Track_Condition_Station_Platforms_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Track_Condition_Station_Platforms_Core_1* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Station_Platforms_Core_1& p)
{
    stream
            << +p.D_TRACKCOND << ','
            << +p.L_TRACKCOND << ','
            << +p.M_PLATFORM << ','
            << +p.Q_PLATFORM;

    return stream;
}

inline bool operator==(const Track_Condition_Station_Platforms_Core_1& a, const Track_Condition_Station_Platforms_Core_1& b)
{
    bool status = true;

    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);
    status = status && (a.M_PLATFORM == b.M_PLATFORM);
    status = status && (a.Q_PLATFORM == b.Q_PLATFORM);

    return status;
}

inline bool operator!=(const Track_Condition_Station_Platforms_Core_1& a, const Track_Condition_Station_Platforms_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

#endif // TRACK_CONDITION_STATION_PLATFORMS_CORE_1_CORE_H_INCLUDED

