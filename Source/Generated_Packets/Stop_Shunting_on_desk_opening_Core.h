
#ifndef STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED

#include "Bitstream.h"

struct Stop_Shunting_on_desk_opening_Core
{
    // TransmissionMedia=Balise
    // Packet to stop Shunting on desk opening.    
    // Packet Number = 135

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

#ifdef __cplusplus

inline bool operator==(const Stop_Shunting_on_desk_opening_Core& a, const Stop_Shunting_on_desk_opening_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET);
}

inline bool operator!=(const Stop_Shunting_on_desk_opening_Core& a, const Stop_Shunting_on_desk_opening_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Stop_Shunting_on_desk_opening_Core Stop_Shunting_on_desk_opening_Core;

#define STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE 15

/*@
    logic integer BitSize{L}(Stop_Shunting_on_desk_opening_Core* p) = STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Stop_Shunting_on_desk_opening_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_Shunting_on_desk_opening_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_Shunting_on_desk_opening_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Stop_Shunting_on_desk_opening_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_Shunting_on_desk_opening_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(Stop_Shunting_on_desk_opening_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED

