
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Track_Condition_Change_of_allowed_current_consumption_Core
{
    // TransmissionMedia=Any
    // The packet gives information about change of the allowed current consumption.
    // Packet Number = 40

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_CURRENT;        // # 15
    uint16_t  M_CURRENT;        // # 10
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Change_of_allowed_current_consumption_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_CURRENT << ','
       << +p.M_CURRENT;

    return stream;
}

inline bool operator==(const Track_Condition_Change_of_allowed_current_consumption_Core& a, const Track_Condition_Change_of_allowed_current_consumption_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_CURRENT == b.D_CURRENT);
    status = status && (a.M_CURRENT == b.M_CURRENT);

    return status;
}

inline bool operator!=(const Track_Condition_Change_of_allowed_current_consumption_Core& a, const Track_Condition_Change_of_allowed_current_consumption_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Change_of_allowed_current_consumption_Core Track_Condition_Change_of_allowed_current_consumption_Core;

#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE 1421

/*@
    logic integer BitSize{L}(Track_Condition_Change_of_allowed_current_consumption_Core* p) = TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Change_of_allowed_current_consumption_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Change_of_allowed_current_consumption_Core* p) = \true;

    predicate ZeroInitialized(Track_Condition_Change_of_allowed_current_consumption_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Change_of_allowed_current_consumption_Core* p) = \true;

    predicate UpperBitsNotSet(Track_Condition_Change_of_allowed_current_consumption_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Track_Condition_Change_of_allowed_current_consumption_UpperBitsNotSet(const Track_Condition_Change_of_allowed_current_consumption_Core* p);

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
int Track_Condition_Change_of_allowed_current_consumption_Encoder(Bitstream* stream, const Track_Condition_Change_of_allowed_current_consumption_Core* p);

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
int Track_Condition_Change_of_allowed_current_consumption_Decoder(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p);

#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED

