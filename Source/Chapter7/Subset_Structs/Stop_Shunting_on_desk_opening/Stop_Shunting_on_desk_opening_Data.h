
#ifndef STOP_SHUNTING_ON_DESK_OPENING_DATA_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_DATA_H_INCLUDED

#include "Bitstream.h"

struct Stop_Shunting_on_desk_opening_Data
{
    // TransmissionMedia=Balise
    // Packet to stop Shunting on desk opening.
    // Packet Number = 135

    uint32_t  Q_DIR;            // # 2
};

typedef struct Stop_Shunting_on_desk_opening_Data Stop_Shunting_on_desk_opening_Data;

#define STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE 15

/*@
    logic integer BitSize{L}(Stop_Shunting_on_desk_opening_Data* p) = STOP_SHUNTING_ON_DESK_OPENING_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Stop_Shunting_on_desk_opening_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_Shunting_on_desk_opening_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_Shunting_on_desk_opening_Data* p) =
      Invariant(p->Q_DIR);

    predicate ZeroInitialized(Stop_Shunting_on_desk_opening_Data* p) =
      ZeroInitialized(p->Q_DIR);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_Shunting_on_desk_opening_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR);


    predicate UpperBitsNotSet(Stop_Shunting_on_desk_opening_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2);

*/

#endif // STOP_SHUNTING_ON_DESK_OPENING_DATA_H_INCLUDED

