
#ifndef STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

#include "Bitstream.h"

struct Stop_Shunting_on_desk_opening
{
    // TransmissionMedia=Balise
    // Packet to stop Shunting on desk opening.
    // Packet Number = 135

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
};

typedef struct Stop_Shunting_on_desk_opening Stop_Shunting_on_desk_opening;

#define STOP_SHUNTING_ON_DESK_OPENING_BITSIZE 23

/*@
    logic integer BitSize{L}(Stop_Shunting_on_desk_opening* p) = STOP_SHUNTING_ON_DESK_OPENING_BITSIZE;

    logic integer MaxBitSize{L}(Stop_Shunting_on_desk_opening* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_Shunting_on_desk_opening* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_Shunting_on_desk_opening* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Stop_Shunting_on_desk_opening* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_Shunting_on_desk_opening* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);


    predicate UpperBitsNotSet(Stop_Shunting_on_desk_opening* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // STOP_SHUNTING_ON_DESK_OPENING_H_INCLUDED

