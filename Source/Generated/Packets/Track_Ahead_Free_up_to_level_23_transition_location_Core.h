
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"

struct Track_Ahead_Free_up_to_level_23_transition_location_Core
{
    // TransmissionMedia=Balise
    // Notification to on-board that track ahead is free from the balise
    // group transmitting this information up to the level 2/3 transition location
    // Packet Number = 90

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct Track_Ahead_Free_up_to_level_23_transition_location_Core Track_Ahead_Free_up_to_level_23_transition_location_Core;

#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) = TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Track_Ahead_Free_up_to_level_23_transition_location_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Ahead_Free_up_to_level_23_transition_location_UpperBitsNotSet(const Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

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
int Track_Ahead_Free_up_to_level_23_transition_location_Encode_Bit(Bitstream* stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

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
int Track_Ahead_Free_up_to_level_23_transition_location_Decode_Bit(Bitstream* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

int Track_Ahead_Free_up_to_level_23_transition_location_Encode_Int(PacketInfo* data, kcg_int* stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

int Track_Ahead_Free_up_to_level_23_transition_location_Decode_Int(PacketInfo* data, const kcg_int* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_NEWCOUNTRY << ','
            << +p.NID_C << ','
            << +p.NID_BG;

    return stream;
}

inline bool operator==(const Track_Ahead_Free_up_to_level_23_transition_location_Core& a, const Track_Ahead_Free_up_to_level_23_transition_location_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);

    if (a.Q_NEWCOUNTRY == 1)
    {
        status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);

    return status;
}

inline bool operator!=(const Track_Ahead_Free_up_to_level_23_transition_location_Core& a, const Track_Ahead_Free_up_to_level_23_transition_location_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core& p)
{
    return Track_Ahead_Free_up_to_level_23_transition_location_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Track_Ahead_Free_up_to_level_23_transition_location_Core& p)
{
    return Track_Ahead_Free_up_to_level_23_transition_location_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Track_Ahead_Free_up_to_level_23_transition_location_Core& p)
{
    std::cerr << "encode int function not implemented for packet 90 yet." << std::endl;

    return Track_Ahead_Free_up_to_level_23_transition_location_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Track_Ahead_Free_up_to_level_23_transition_location_Core& p)
{
    std::cerr << "decode int function not implemented for packet 90 yet." << std::endl;

    return Track_Ahead_Free_up_to_level_23_transition_location_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_CORE_H_INCLUDED

