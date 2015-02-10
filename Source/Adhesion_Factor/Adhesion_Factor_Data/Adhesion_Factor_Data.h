
#ifndef ADHESION_FACTOR_DATA_H_INCLUDED
#define ADHESION_FACTOR_DATA_H_INCLUDED

#include "Bitstream.h"

struct Adhesion_Factor_Data
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of the adhesion factor to be used in the brake model.
    // Packet Number = 71

    uint8_t  Q_SCALE;          // # 2
    uint16_t  D_ADHESION;       // # 15
    uint16_t  L_ADHESION;       // # 15
    uint8_t  M_ADHESION;       // # 1
};

typedef struct Adhesion_Factor_Data Adhesion_Factor_Data;

#define ADHESION_FACTOR_DATA_BITSIZE 33

/*@
    logic integer BitSize{L}(Adhesion_Factor_Data* p) = ADHESION_FACTOR_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor_Data* p) =
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_ADHESION)        &&
      Invariant(p->L_ADHESION)        &&
      Invariant(p->M_ADHESION);

    predicate ZeroInitialized(Adhesion_Factor_Data* p) =
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_ADHESION)        &&
      ZeroInitialized(p->L_ADHESION)        &&
      ZeroInitialized(p->M_ADHESION);

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_SCALE)           &&
      EqualBits(stream, pos + 2,   pos + 17,  p->D_ADHESION)        &&
      EqualBits(stream, pos + 17,  pos + 32,  p->L_ADHESION)        &&
      EqualBits(stream, pos + 32,  pos + 33,  p->M_ADHESION);


    predicate UpperBitsNotSet(Adhesion_Factor_Data* p) =
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_ADHESION,       15)  &&
      UpperBitsNotSet(p->L_ADHESION,       15)  &&
      UpperBitsNotSet(p->M_ADHESION,       1);

*/

#endif // ADHESION_FACTOR_DATA_H_INCLUDED

