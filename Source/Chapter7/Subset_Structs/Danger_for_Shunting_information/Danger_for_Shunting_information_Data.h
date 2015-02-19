
#ifndef DANGER_FOR_SHUNTING_INFORMATION_DATA_H_INCLUDED
#define DANGER_FOR_SHUNTING_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Danger_for_Shunting_information_Data
{
    // TransmissionMedia=Balise
    // Transmission of the aspect of a shunting signal
    // Packet Number = 132

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_ASPECT;         // # 1
};

typedef struct Danger_for_Shunting_information_Data Danger_for_Shunting_information_Data;

#define DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE 16

/*@
    logic integer BitSize{L}(Danger_for_Shunting_information_Data* p) = DANGER_FOR_SHUNTING_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Danger_for_Shunting_information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Danger_for_Shunting_information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Danger_for_Shunting_information_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_ASPECT);

    predicate ZeroInitialized(Danger_for_Shunting_information_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_ASPECT);

    predicate EqualBits(Bitstream* stream, integer pos, Danger_for_Shunting_information_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);


    predicate UpperBitsNotSet(Danger_for_Shunting_information_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_ASPECT,         1);

*/

#endif // DANGER_FOR_SHUNTING_INFORMATION_DATA_H_INCLUDED

