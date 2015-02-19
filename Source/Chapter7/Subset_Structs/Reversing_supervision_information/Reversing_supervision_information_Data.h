
#ifndef REVERSING_SUPERVISION_INFORMATION_DATA_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Reversing_supervision_information_Data
{
    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing area to the on-board
    // Packet Number = 139

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_REVERSE;        // # 15
    uint8_t   V_REVERSE;        // # 7
};

typedef struct Reversing_supervision_information_Data Reversing_supervision_information_Data;

#define REVERSING_SUPERVISION_INFORMATION_DATA_BITSIZE 39

/*@
    logic integer BitSize{L}(Reversing_supervision_information_Data* p) = REVERSING_SUPERVISION_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_supervision_information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_supervision_information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_supervision_information_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_REVERSE)         &&
      Invariant(p->V_REVERSE);

    predicate ZeroInitialized(Reversing_supervision_information_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_REVERSE)         &&
      ZeroInitialized(p->V_REVERSE);

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_supervision_information_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE)         &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);


    predicate UpperBitsNotSet(Reversing_supervision_information_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_REVERSE,        15)  &&
      UpperBitsNotSet(p->V_REVERSE,        7);

*/

#endif // REVERSING_SUPERVISION_INFORMATION_DATA_H_INCLUDED

