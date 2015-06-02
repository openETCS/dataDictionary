
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED

#include "Bitstream.h"

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

inline bool operator==(const Track_Condition_Change_of_allowed_current_consumption_Core& a, const Track_Condition_Change_of_allowed_current_consumption_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_SCALE == b.Q_SCALE) &&
        (a.D_CURRENT == b.D_CURRENT) &&
        (a.M_CURRENT == b.M_CURRENT);
}

inline bool operator!=(const Track_Condition_Change_of_allowed_current_consumption_Core& a, const Track_Condition_Change_of_allowed_current_consumption_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Change_of_allowed_current_consumption_Core Track_Condition_Change_of_allowed_current_consumption_Core;

#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE 42

/*@
    logic integer BitSize{L}(Track_Condition_Change_of_allowed_current_consumption_Core* p) = TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Change_of_allowed_current_consumption_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_CURRENT)         &&
      Invariant(p->M_CURRENT);

    predicate ZeroInitialized(Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_CURRENT)         &&
      ZeroInitialized(p->M_CURRENT);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_CURRENT)         &&
      EqualBits(stream, pos + 32,  pos + 42,  p->M_CURRENT);

    predicate UpperBitsNotSet(Track_Condition_Change_of_allowed_current_consumption_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_CURRENT,        15)  &&
      UpperBitsNotSet(p->M_CURRENT,        10);

*/

#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_CORE_H_INCLUDED

